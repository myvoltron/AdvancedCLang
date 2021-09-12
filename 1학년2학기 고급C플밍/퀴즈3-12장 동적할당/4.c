#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
	char* str;
	int cnt;
	int num;
	int result;
} ST;

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int len = 0;
	char temp[101];
	char* pc1, * pc2, * pc3;
	ST* p_st = NULL;
	ST save;

	scanf("%d", &N);
	getchar();
	p_st = (ST*)malloc(N * sizeof(ST));

	for (i = 0; i < N; ++i)
	{
		gets(temp);
		len = strlen(temp);
		p_st[i].str = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p_st[i].str, temp);
	}

	for (i = 0; i < N; ++i)
	{
		len = strlen(p_st[i].str);

		p_st[i].num = 0;
		for (pc1 = p_st[i].str; pc1 < p_st[i].str + len; ++pc1)
		{
			if (*pc1 >= '0' && *pc1 <= '9')
			{
				for (pc2 = pc1, pc3 = temp; pc2 < p_st[i].str + len; ++pc2, ++pc3)
				{
					if (*pc2 < '0' || *pc2 > '9')
						break;

					*pc3 = *pc2;
				}
				*pc3 = '\0';
				p_st[i].num += atoi(temp);
				pc1 += strlen(temp) - 1;
				continue;
			}
		}

		p_st[i].cnt = 0;
		for (pc1 = p_st[i].str; pc1 < p_st[i].str + len; ++pc1)
		{
			if (*pc1 >= '0' && *pc1 <= '9')
				continue;

			else if (*pc1 == 'a' || *pc1 == 'e' || *pc1 == 'u' || *pc1 == 'i' || *pc1 == 'o' ||
				*pc1 == 'A' || *pc1 == 'E' || *pc1 == 'U' || *pc1 == 'I' || *pc1 == 'O')
				p_st[i].cnt += 1;
		}

		p_st[i].result = p_st[i].cnt + p_st[i].num;
	}

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N - 1; ++j)
		{
			if (p_st[j].result > p_st[j + 1].result)
			{
				save = p_st[j];
				p_st[j] = p_st[j + 1];
				p_st[j + 1] = save;
			}
		}
	}

	for (i = 0; i < N; ++i)
		printf("%s\n", p_st[i].str);

	for (i = 0; i < N; ++i)
		free(p_st[i].str);
	free(p_st);
	return 0;
}
