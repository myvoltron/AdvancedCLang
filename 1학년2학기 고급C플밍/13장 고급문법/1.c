#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cal_gcd(int N, int M)
{
	//printf("%d %d\n", N, M);
	if (M == N)
		return M;
	else if (M != N)
	{
		if (M > N)
			cal_gcd(N, M - N);
		else if (N > M)
			cal_gcd(M, N - M);
	}
}

int main()
{
	int N = 0, M = 0;

	scanf("%d %d", &N, &M);
	if (N >= M)
		printf("%d", cal_gcd(N, M));
	else if (N <= M)
		printf("%d", cal_gcd(M, N));
	return 0;
}