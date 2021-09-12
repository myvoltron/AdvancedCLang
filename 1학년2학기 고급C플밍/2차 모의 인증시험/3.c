#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int len = 0;
	int f_len = 0;
	int cnt1 = 0, cnt2 = 0;
	int max_cnt = 0;
	int checker = 0;
	int index = 0;
	char** str = NULL;
	char find[101];
	char temp[101];
	char* pc1, * pc2, * pc3;

	scanf("%d", &N);
	scanf("%s", find);
	f_len = strlen(find);
	getchar();

	str = (char**)malloc(N * sizeof(char*));
	if (str == NULL)
	{
		printf("Not Enough Memory");
		return -1;
	}

	for (i = 0; i < N; ++i)
	{
		gets(temp);
		len = strlen(temp);
		str[i] = (char*)malloc((len + 1) * sizeof(char));
		strcpy(str[i], temp);
	}

	for (i = 0; i < N; ++i)
	{
		len = strlen(str[i]);
		cnt2 = 0;

		for (pc1 = str[i]; pc1 < str[i] + len; ++pc1)
		{
			cnt1 = 0;
			for (pc2 = find, pc3 = pc1; pc2 < find + f_len; ++pc2, ++pc3)
			{
				if (*pc2 == *pc3)
					cnt1++;
			}

			if (cnt1 == f_len)
			{
				cnt2++;
				pc1 += f_len - 1;
				checker++;
			}
		}

		if (cnt2 > max_cnt)
		{
			max_cnt = cnt2;
			index = i;
		}
	}

	if (checker == 0)
		printf("NONE");
	else
		printf("%s", str[index]);

	for (i = 0; i < N; ++i)
		free(str[i]);
	free(str);
	return 0;
}
