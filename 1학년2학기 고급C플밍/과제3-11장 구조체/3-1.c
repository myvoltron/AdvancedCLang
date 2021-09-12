#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel_info
{
	char name[31];
	int grade;
	double repu;
	double distan;
	char food;
};

int in_hotel_info(struct hotel_info* p);
void out_hotel_info(struct hotel_info* p, int N, int G, double D);

int main()
{
	struct hotel_info hotel[100];
	int N = 0, G = 0;
	double D = 0;

	N = in_hotel_info(hotel);

	scanf("%d %lf", &G, &D);

	out_hotel_info(hotel, N, G, D);
	return 0;
}

int in_hotel_info(struct hotel_info* p)
{
	struct hotel_info* p1;
	int N = 0;

	for (p1 = p; ; ++p1)
	{
		scanf("%s", p1->name);
		if (strcmp(p1->name, "0") == 0)
			break;

		scanf("%d %lf %lf", &p1->grade, &p1->repu, &p1->distan);
		getchar();
		scanf("%c", &p1->food);
		N++;
	}

	return N;
}
void out_hotel_info(struct hotel_info* p, int N, int G, double D)
{
	struct hotel_info* p1, * p2;
	struct hotel_info tmp;

	for (p1 = p; p1 < p + N; ++p1)
	{
		for (p2 = p; p2 < p + N - 1; ++p2)
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

	for (p1 = p; p1 < p + N; ++p1)
	{
		if (p1->grade >= G && p1->distan <= D)
		{
			printf("%s %d %.1lf %.1lf %c", p1->name, p1->grade, p1->repu, p1->distan, p1->food);
			break;
		}
	}
}