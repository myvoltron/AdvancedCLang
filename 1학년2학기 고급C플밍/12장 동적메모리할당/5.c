#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int* p_num = NULL;
	int* p1;
	int save = 0;

	scanf("%d", &N);
	p_num = (int*)malloc(N * sizeof(int));

	for (p1 = p_num; p1 < p_num + N; ++p1)
		scanf("%d", p1);

	for (p1 = p_num; p1 < p_num + N - 1; ++p1)
	{
		if (*p1 > *(p1 + 1))
		{
			save = *p1;
			*p1 = *(p1 + 1);
			*(p1 + 1) = save;
		}
	}

	for (p1 = p_num; p1 < p_num + N; ++p1)
		printf("%d\n", *p1);

	free(p_num);
	return 0;
}