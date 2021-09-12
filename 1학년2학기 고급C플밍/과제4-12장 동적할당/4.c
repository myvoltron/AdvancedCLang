#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tourcity
{
	char name[21];
	int cost;
	char out_in;
	char date[10];
} TOUR;

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int len = 0;
	int index_i = 0;
	int index_j = 0;
	int max_cost = 0;
	int* tour_cnt = NULL;
	char** cityname = NULL;
	char temp[21];
	TOUR** p_tour = NULL;

	scanf("%d", &N);
	cityname = (char**)malloc(N * sizeof(char*));
	p_tour = (TOUR**)malloc(N * sizeof(TOUR*));

	for (i = 0; i < N; ++i)
	{
		scanf("%s", temp);
		cityname[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(cityname[i], temp);
	}


	tour_cnt = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &tour_cnt[i]);
		p_tour[i] = (TOUR*)malloc(tour_cnt[i] * sizeof(TOUR));
	}

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < tour_cnt[i]; ++j)
			scanf("%s %d %c %s", p_tour[i][j].name, &p_tour[i][j].cost, &p_tour[i][j].out_in, p_tour[i][j].date);
	}

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < tour_cnt[i]; ++j)
		{
			if (p_tour[i][j].cost >= max_cost)
			{
				if (p_tour[i][j].cost == max_cost)
				{
					if (strcmp(p_tour[i][j].date, p_tour[index_i][index_j].date) < 0)
					{
						max_cost = p_tour[i][j].cost;
						index_i = i;
						index_j = j;
					}
				}
				else
				{
					max_cost = p_tour[i][j].cost;
					index_i = i;
					index_j = j;
				}
			}
		}
	}

	printf("%s %s %d %s %c", cityname[index_i], p_tour[index_i][index_j].name, p_tour[index_i][index_j].cost, p_tour[index_i][index_j].date, p_tour[index_i][index_j].out_in);

	for (i = 0; i < N; ++i)
	{
		free(cityname[i]);
		free(p_tour[i]);
	}
	free(cityname);
	free(p_tour);
	free(tour_cnt);
	return 0;
}
