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
	int carnum;
	int stnum;
	struct time time1;
	struct time time2;
};

int main()
{
	struct parking_system car[100];
	struct parking_system ille[100];
	struct parking_system* p1, * p2;
	struct parking_system* pille = ille;
	struct parking_system tmp;
	int N = 0;
	int cnt1 = 0;
	int ille_cnt = 0;

	scanf("%d", &N);

	for (p1 = car; p1 < car + N; ++p1)
	{
		scanf("%d %d", &p1->carnum, &p1->stnum);
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
			if (p2 < p1 && p2->stnum == p1->stnum)
				break;

			if (p2->stnum == p1->stnum)
				cnt1++;
		}

		if (cnt1 >= 2)
		{
			*pille = *p1;
			pille++;
			ille_cnt++;
		}
	}

	for (p1 = ille; p1 < ille + ille_cnt; ++p1)
	{
		for (p2 = ille; p2 < ille + ille_cnt - 1; ++p2)
		{
			if (p2->stnum > (p2 + 1)->stnum)
			{
				tmp = *p2;
				*p2 = *(p2 + 1);
				*(p2 + 1) = tmp;
			}
		}
	}

	for (p1 = ille; p1 < ille + ille_cnt; ++p1)
		printf("%d\n", p1->stnum);
	return 0;
}