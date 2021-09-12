#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0, D = 0;
	int i = 0;
	int* p_num = NULL;

	scanf("%d", &N);

	p_num = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; ++i)
		scanf("%d", &p_num[i]);

	scanf("%d", &D);

	p_num = (int*)realloc(p_num, (N - D) * sizeof(int));
	for (i = 0; i < N - D; ++i)
		printf("%d\n", p_num[i]);

	free(p_num);
	return 0;
}
