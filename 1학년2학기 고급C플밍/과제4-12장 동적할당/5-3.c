#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct customer
{
	char id[5];
	char* name;
	char* phone;
	struct customer* next;
} cus;

int main()
{
	int N = 0;
	int len = 0;
	int checker = 0;
	int i = 0, j = 0;
	int k = 1;
	cus* p_cus = NULL;
	char temp[101];
	char* pc1, * pc2;
	char find[101];

	scanf("%d", &N);
	p_cus = (cus*)malloc(N * sizeof(cus));

	for (i = 0; i < N; ++i)
	{
		scanf("%s", temp);
		len = strlen(temp);

		p_cus[i].name = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p_cus[i].name, temp);

		scanf("%s", temp);
		len = strlen(temp);

		p_cus[i].phone = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p_cus[i].phone, temp);

		for (pc1 = p_cus[i].phone + len - 4, pc2 = p_cus[i].id; pc1 < p_cus[i].phone + len; ++pc1, ++pc2)
			*pc2 = *pc1;
		*pc2 = '\0';
	}

	for (i = 0; i < N - 1; ++i)
	{
		for (j = i + 1; j < N; ++j)
		{
			if (p_cus[i].id[3] == p_cus[j].id[3])
			{
				p_cus[i].next = &p_cus[j];
			}
		}
	}

	scanf("%s", find);
	k = 1;
	for (i = 0; i < N; ++i)
	{
		if (!strcmp(p_cus[i].id, find))
			printf("%s %s %d\n", p_cus[i].name, p_cus[i].phone, k);

		else if (p_cus[i].id[3] == find[3])
			k++;
	}

	for (i = 0; i < N; ++i)
	{
		free(p_cus[i].name);
		free(p_cus[i].phone);
	}
	free(p_cus);
	return 0;
}