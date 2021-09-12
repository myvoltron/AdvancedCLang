#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	char* p1, * p2;
	int N = 0;
	int sum = 0;
	int times = 1;

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

			sum += (*p1 - '0') * times;
		}
	}

	for (p1 = str1; p1 < str1 + N; ++p1)
	{
		if (*p1 >= 'A' && *p1 <= 'Z' || *p1 >= 'a' && *p1 <= 'z')
			printf("%c", *p1);
	}

	printf("%d", sum);
	return 0;
}