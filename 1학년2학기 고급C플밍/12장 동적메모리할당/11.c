#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int* p_num = NULL;
	int* new_num = NULL;

	scanf("%d", &N);
	p_num = (int*)malloc(N * sizeof(int));

	for (i = 0; i < N; ++i)
		p_num[i] = i;

	new_num = (int*)malloc((N - 1) * sizeof(int));

	for (i = 0; i < N; ++i)
	{
		if (i == N / 2)
			continue;

		new_num[j++] = p_num[i];
	}

	for (i = 0; i < N - 1; ++i)
		printf(" %d", new_num[i]);

	free(p_num);
	free(new_num);
	return 0;
}