#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct subject
{
	char* name;
	double score;
} SUB;

typedef struct student
{
	char* name;
	char id[5];
	int numsubject;
	SUB* psub;
	double avg;
} ST;

int main()
{
	int N = 0, K = 0;
	int i = 0, j = 0;
	int len = 0;
	int info_len = 0;
	int index = 0;
	double max_score = 0;
	char temp[101];
	char save[101];
	char* pc1, * pc2, * pc3;
	char* save_sub = NULL;
	ST* p_st = NULL;
	ST tran;

	scanf("%d", &N);
	getchar();

	p_st = (ST*)malloc(N * sizeof(ST));

	for (i = 0; i < N; ++i)
	{
		gets(temp);
		len = strlen(temp);

		for (pc1 = temp, pc2 = save; pc1 < temp + len; ++pc1)
		{
			if (*pc1 == ' ')
			{
				*pc2 = '\0';
				p_st[i].name = (char*)malloc((strlen(save) + 1) * sizeof(char));
				strcpy(p_st[i].name, save);
				break;
			}

			*pc2 = *pc1;
			pc2++;
		}

		pc1++;
		for (pc1, pc2 = p_st[i].id; pc1 < temp + len; ++pc1)
		{
			if (*pc1 == ' ')
			{
				*pc2 = '\0';
				break;
			}

			*pc2 = *pc1;
			pc2++;
		}

		save_sub = pc1 + 1;
		p_st[i].numsubject = 0;
		for (pc1 = save_sub; pc1 <= temp + len; ++pc1)
		{
			if (*pc1 == ' ')
				p_st[i].numsubject++;
			else if (*pc1 == '\0')
				p_st[i].numsubject++;
		}
		p_st[i].numsubject /= 2;

		p_st[i].psub = (SUB*)malloc(p_st[i].numsubject * sizeof(SUB));
		p_st[i].avg = 0;
		j = 0;
		for (pc1 = save_sub, pc2 = save; pc1 <= temp + len; ++pc1)
		{
			if (*pc1 == ' ')
			{
				*pc2 = '\0';

				if (*(pc1 - 1) >= '0' && *(pc1 - 1) <= '9')
				{
					p_st[i].psub[j].score = atof(save);
					p_st[i].avg += atof(save);
					j++;
				}
				else
				{
					p_st[i].psub[j].name = (char*)malloc((strlen(save) + 1) * sizeof(char));
					strcpy(p_st[i].psub[j].name, save);
				}

				pc2 = save;
				continue;
			}

			else if (*pc1 == '\0')
			{
				*pc2 = '\0';
				p_st[i].psub[j].score = atof(save);
				p_st[i].avg += atof(save);
			}

			*pc2 = *pc1;
			pc2++;
		}

		p_st[i].avg /= p_st[i].numsubject;
	}

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N - 1; ++j)
		{
			if (p_st[j].avg <= p_st[j + 1].avg)
			{
				if (p_st[j].avg == p_st[j + 1].avg)
				{
					if (strcmp(p_st[j].id, p_st[j + 1].id) > 0)
					{
						tran = p_st[j];
						p_st[j] = p_st[j + 1];
						p_st[j + 1] = tran;
					}
				}
				else
				{
					tran = p_st[j];
					p_st[j] = p_st[j + 1];
					p_st[j + 1] = tran;
				}
			}
		}
	}

	scanf("%d", &K);
	K -= 1;

	printf("%s %s %.2lf", p_st[K].name, p_st[K].id, p_st[K].avg);
	for (i = 0; i < p_st[K].numsubject; ++i)
	{
		if (p_st[K].psub[i].score > max_score)
		{
			max_score = p_st[K].psub[i].score;
			index = i;
		}
	}
	printf(" %s %.2lf", p_st[K].psub[index].name, p_st[K].psub[index].score);

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < p_st[i].numsubject; ++j)
			free(p_st[i].psub[j].name);
		free(p_st[i].name);
		free(p_st[i].psub);
	}
	free(p_st);
	return 0;
}
