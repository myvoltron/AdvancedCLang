#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int* p = NULL;
	int sum = 0;

	scanf("%d", &N);
	p = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; ++i)
		scanf("%d", &p[i]);
	for (int i = 0; i < N; ++i)
		sum += p[i];

	printf("%d", sum);

	free(p);
	return 0;
}