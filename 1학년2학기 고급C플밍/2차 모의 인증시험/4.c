#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
	int id;
	int score1, score2;
	double result;
} ST;

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int condition1 = 0, condition2 = 0;
	int max_condition = 0;
	ST* p_st = NULL;
	ST* p_result = NULL;
	ST tran;

	scanf("%d", &N);

	p_st = (ST*)malloc(N * sizeof(ST));
	p_result = (ST*)malloc(N * sizeof(ST));

	condition1 = N * 6 / 10;
	condition2 = N * 8 / 10;

	for (i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &p_st[i].id, &p_st[i].score1, &p_st[i].score2);
		p_st[i].result = p_st[i].score1 * 0.4 + p_st[i].score2 * 0.6;
	}

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N - 1; ++j)
		{
			if (p_st[j].result < p_st[j + 1].result)
			{
				tran = p_st[j];
				p_st[j] = p_st[j + 1];
				p_st[j + 1] = tran;
			}
		}
	}

	for (i = 0; i < condition1; ++i)
	{
		if (p_st[i].result == p_st[i + 1].result && i + 1 == condition1)
			condition1 += 1;

		p_result[i] = p_st[i];
	}

	if (condition1 < condition2)
	{
		for (i = condition1 - 1; i < N; ++i)
		{
			for (j = condition1 - 1; j < N - 1; ++j)
			{
				if (p_st[j].score2 < p_st[j + 1].score2)
				{
					tran = p_st[j];
					p_st[j] = p_st[j + 1];
					p_st[j + 1] = tran;
				}
			}
		}

		for (i = condition1 - 1; i < condition2; ++i)
		{
			if (p_st[i].score2 == p_st[i + 1].score2 && i + 1 == condition2)
				condition2 += 1;

			p_result[i] = p_st[i];
		}
	}

	max_condition = condition1 < condition2 ? condition2 : condition1;

	for (i = 0; i < max_condition; ++i)
	{
		for (j = 0; j < max_condition - 1; ++j)
		{
			if (p_result[j].id > p_result[j + 1].id)
			{
				tran = p_result[j];
				p_result[j] = p_result[j + 1];
				p_result[j + 1] = tran;
			}
		}
	}

	for (i = 0; i < max_condition; ++i)
		printf("%d\n", p_result[i].id);

	free(p_st);
	free(p_result);
	return 0;
}
