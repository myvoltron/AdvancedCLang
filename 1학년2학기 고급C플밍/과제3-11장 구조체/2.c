#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _bank
{
	int id;
	int arrival_time;
	int service_time;
	int waiting_time;
};

void waitingtime(struct _bank guest[], int N);
double avgtime(struct _bank guest[], int N);

int main()
{
	struct _bank guest[100];
	struct _bank* p1;
	int N = 0;

	scanf("%d", &N);

	for (p1 = guest; p1 < guest + N; ++p1)
	{
		scanf("%d", &p1->id);
		scanf("%d", &p1->arrival_time);
		scanf("%d", &p1->service_time);
	}

	waitingtime(guest, N);
	printf("%.2lf", avgtime(guest, N));
	return 0;
}

void waitingtime(struct _bank guest[], int N)
{
	struct _bank* p1;
	int time = 0;

	for (p1 = guest; p1 < guest + N; ++p1)
	{
		p1->waiting_time = time - p1->arrival_time;
		time += p1->service_time;
	}
}
double avgtime(struct _bank guest[], int N)
{
	struct _bank* p1;
	double avg = 0;

	for (p1 = guest; p1 < guest + N; ++p1)
		avg += p1->waiting_time;

	return (double)avg / N;
}