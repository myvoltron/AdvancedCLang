#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void input(int* p, int N);
void output(int* p, int K);

int main()
{
	int N = 0, M = 0;
	int K = 0;
	int num1[100];
	int num2[100];
	int* p1, * p2;

	scanf("%d %d", &M, &N);
	input(num1, M);
	input(num2, N);
	scanf("%d", &K);

	p1 = num1;
	p2 = num2;
	while (1)
	{
		if (p1 < num1 + M)
		{
			output(p1, K);
			p1 += K;
		}

		if (p2 < num2 + N)
		{
			output(p2, K);
			p2 += K;
		}

		if (p1 == num1 + M && p2 == num2 + N)
			break;
	}
	return 0;
}

void input(int* p, int N)
{
	int* p1;

	for (p1 = p; p1 < p + N; ++p1)
		scanf("%d", p1);
}
void output(int* p, int K)
{
	int* p1;

	for (p1 = p; p1 < p + K; ++p1)
		printf("%d ", *p1);
}