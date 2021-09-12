#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel_info
{
	char name[31];
	int rank;
	double repu;
	double dis;
	char food;
};

int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);

int main()
{
	struct hotel_info hotel[100];
	struct hotel_info* p1, * p2;
	struct hotel_info tmp;
	int N = 0, G = 0;
	double D;

	N = in_hotel_info(hotel);

	for (p1 = hotel; p1 < hotel + N; ++p1)
	{
		for (p2 = hotel; p2 < hotel + N - 1; ++p2)
		{
			if (p2->repu <= (p2 + 1)->repu)
			{
				if (p2->repu == (p2 + 1)->repu)
				{
					if (strcmp(p2->name, (p2 + 1)->name) > 0)
					{
						tmp = *p2;
						*p2 = *(p2 + 1);
						*(p2 + 1) = tmp;
					}
				}

				else
				{
					tmp = *p2;
					*p2 = *(p2 + 1);
					*(p2 + 1) = tmp;
				}
			}
		}
	}

	scanf("%d %lf", &G, &D);
	out_hotel_info(hotel, N, G, D);
	return 0;
}

int in_hotel_info(struct hotel_info* p)
{
	int N = 0;
	struct hotel_info* p1;

	for (p1 = p; ; ++p1)
	{
		scanf("%s", p1->name);
		if (!strcmp(p1->name, "0"))
			break;

		scanf("%d", &p1->rank);
		scanf("%lf", &p1->repu);
		scanf("%lf", &p1->dis);
		getchar();
		scanf("%c", &p1->food);
		N++;
	}

	return N;
}

void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
	struct hotel_info* p1;

	for (p1 = p; p1 < p + N; ++p1)
	{
		if (p1->rank >= G && p1->dis <= D)
			printf("%s %d %.1lf %.1lf %c\n", p1->name, p1->rank, p1->repu, p1->dis, p1->food);
	}
}