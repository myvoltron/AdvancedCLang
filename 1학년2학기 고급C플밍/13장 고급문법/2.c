#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int factorial(int N)
{
	int s = 1;

	if (N == 1)
		s = 1;
	else
		s = factorial(N - 1) * N;
	return s;
}

int main()
{
	int N = 0;
	double sum = 1;

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		sum += 1.0 / factorial(i);

	printf("%.6lf", sum);
	return 0;
}