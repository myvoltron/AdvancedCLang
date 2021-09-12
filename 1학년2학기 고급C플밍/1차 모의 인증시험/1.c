#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(int* p, int M);
int* sel_max(int* p, int M);
void output(int* p, int N);

int main()
{
	int in[100], out[100], * max, i, N, M;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}
	output(out, N);
	return 0;
}

void input(int* p, int M)
{
	int* p1;

	for (p1 = p; p1 < p + M; ++p1)
		scanf("%d", p1);
}

int* sel_max(int* p, int M)
{
	int* p1, * p2;
	int* result = p;
	int cnt1 = 0;
	int max = -999;

	for (p1 = p; p1 < p + M; ++p1)
	{
		cnt1 = 0;

		for (p2 = p; p2 < p + M; ++p2)
		{
			if (p2 < p1 && *p1 == *p2)
				break;

			if (*p1 == *p2)
				cnt1++;
		}

		if (cnt1 > max)
		{
			result = p1;
			max = cnt1;
		}
	}

	return result;
}

void output(int* p, int N)
{
	int* p1;

	for (p1 = p; p1 < p + N; ++p1)
		printf(" %d", *p1);
}