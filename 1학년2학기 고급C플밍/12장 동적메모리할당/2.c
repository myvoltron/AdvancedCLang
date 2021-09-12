#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int i = 0;
	float* pf = NULL;
	float max_num = -99;

	scanf("%d", &N);

	pf = (float*)malloc(N * sizeof(float));
	for (i = 0; i < N; ++i)
		scanf("%f", &pf[i]);

	for (i = 0; i < N; ++i)
	{
		if (pf[i] > max_num)
			max_num = pf[i];
	}

	printf("%.2f", max_num);

	free(pf);
	return 0;
}