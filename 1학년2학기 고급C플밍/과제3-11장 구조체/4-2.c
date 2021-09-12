#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct time
{
	int year;
	int month;
	int day;
	int hour;
	int min;
};

struct parking_system
{
	char carnum[5];
	char stnum[7];
	struct time time1;
	struct time time2;
};

int cal_cost(struct parking_system* p, struct parking_system* ille, int ille_cnt);

int main()
{
	struct parking_system car[100];
	struct parking_system ille[100];
	struct parking_system* p1, * p2;
	struct parking_system* pille = ille;
	int N = 0;
	int i = 0;
	int ille_cnt = 0;
	int cnt1 = 0;
	int K = 0;
	char find_carnum[5];

	scanf("%d", &N);

	for (p1 = car; p1 < car + N; ++p1)
	{
		scanf("%s", p1->carnum);
		scanf("%s", p1->stnum);
		scanf("%d-%d-%d", &p1->time1.year, &p1->time1.month, &p1->time1.day);
		scanf("%d:%d", &p1->time1.hour, &p1->time1.min);
		scanf("%d-%d-%d", &p1->time2.year, &p1->time2.month, &p1->time2.day);
		scanf("%d:%d", &p1->time2.hour, &p1->time2.min);
	}

	for (p1 = car; p1 < car + N; ++p1)
	{
		cnt1 = 0;

		for (p2 = car; p2 < car + N; ++p2)
		{
			if (p2 < p1 && !strcmp(p1->stnum, p2->stnum))
				break;

			if (!strcmp(p1->stnum, p2->stnum))
				cnt1++;
		}

		if (cnt1 >= 2)
		{
			*pille = *p1;
			pille++;
			ille_cnt++;
		}
	}

	scanf("%d", &K);
	for (i = 0; i < K; ++i)
	{
		scanf("%s", find_carnum);

		for (p1 = car; p1 < car + N; ++p1)
		{
			if (!strcmp(p1->carnum, find_carnum))
				printf("%d\n", cal_cost(p1, ille, ille_cnt));
		}
	}
	return 0;
}

int cal_cost(struct parking_system* p, struct parking_system* ille, int ille_cnt)
{
	struct parking_system* p1;

	int time1 = 0, time2 = 0, time3 = 0;
	int cost = 0;

	for (p1 = ille; p1 < ille + ille_cnt; ++p1)
	{
		if (!strcmp(p1->stnum, p->stnum))
			return 100000;
	}

	time2 = p->time2.hour * 60 + p->time2.min;
	time1 = p->time1.hour * 60 + p->time1.min;

	time3 = time2 - time1;

	if (time3 <= 60)
		return 3000;

	else if (time3 > 60)
	{
		time3 -= 60;
		cost += 3000;

		while (time3 > 0)
		{
			cost += 1000;
			time3 -= 10;

			if (cost > 30000)
				return 30000;
		}
	}

	return cost;
}