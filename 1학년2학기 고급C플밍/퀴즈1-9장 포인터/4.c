#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	char* p1, * p2;
	double num[100] = { 0 };
	double* pnum = num;
	double* pd1, * pd2;
	double tmp;
	int N = 0;
	int times = 1;
	int num_cnt = 0;

	scanf("%d", &N);
	getchar();

	for (p1 = str1; p1 < str1 + N; ++p1)
		scanf("%c", p1);

	for (p1 = str1; p1 < str1 + N; ++p1)
	{
		if (*p1 >= '0' && *p1 <= '9')
		{
			times = 1;

			for (p2 = p1 + 1; p2 < str1 + N; ++p2)
			{
				if (*p2 < '0' || *p2 > '9')
					break;

				times *= 10;
			}

			*pnum += (*p1 - '0') * times;
			if (times == 1)
			{
				pnum++;
				num_cnt++;
			}
		}
	}

	for (pd1 = num; pd1 < num + num_cnt; ++pd1)
	{
		for (pd2 = num; pd2 < num + num_cnt - 1; ++pd2)
		{
			if (*pd2 < *(pd2 + 1))
			{
				tmp = *pd2;
				*pd2 = *(pd2 + 1);
				*(pd2 + 1) = tmp;
			}
		}
	}

	for (p1 = str1; p1 < str1 + N; ++p1)
	{
		if (*p1 >= 'A' && *p1 <= 'Z')
			printf("%c", 'a' + *p1 - 'A');
		else if (*p1 >= 'a' && *p1 <= 'z')
			printf("%c", 'A' + *p1 - 'a');
	}
	printf("\n");

	for (pd1 = num; pd1 < num + num_cnt; ++pd1)
		printf("%.0lf ", *pd1);
	return 0;
}