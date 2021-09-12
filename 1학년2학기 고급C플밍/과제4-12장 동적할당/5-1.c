#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct customer
{
	char id[5];
	char* name;
	char* phone;
} CUS;

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int len = 0;
	char find_s[5];
	char temp[101];
	char* pc1, * pc2;
	CUS* p_cus = NULL;

	scanf("%d", &N);

	p_cus = (CUS*)malloc(N * sizeof(CUS));
	if (p_cus == NULL)
	{
		printf("Not Enough Memory");
		return -1;
	}

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

	scanf("%s", find_s);

	for (i = 0; i < N; ++i)
	{
		if (!strcmp(find_s, p_cus[i].id))
			printf("%s %s %d\n", p_cus[i].name, p_cus[i].phone, i + 1);
	}

	for (i = 0; i < N; ++i)
	{
		free(p_cus[i].name);
		free(p_cus[i].phone);
	}
	free(p_cus);
	return 0;
}

