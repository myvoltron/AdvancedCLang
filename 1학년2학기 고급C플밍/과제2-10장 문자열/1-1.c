#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	char num[10];
	char ch;
	char* p1, * p2, * p3;
	int N = 0;
	int len1 = 0;
	int times = 1;
	int sum = 0;

	gets(str1);
	len1 = strlen(str1);
	scanf("%d", &N);

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		if (*p1 >= 'A' && *p1 <= 'Z')
			*p1 += N;
		else if (*p1 >= 'a' && *p1 <= 'z')
			*p1 -= N;

		else if (*p1 >= '0' && *p1 <= '9')
		{
			times = 0;

			for (p2 = p1, p3 = num; p2 < str1 + len1; ++p2)
			{
				if (*p2 < '0' || *p2 > '9')
					break;

				*p3 = *p2;
				p3++;
				times++;
			}
			*p3 = '\0';

			ch = 'A' + atoi(num) - 1;
			sum = N - times;

			for (p2 = str1 + len1 + sum - 1; p2 > p1 + times; --p2)
				*p2 = *(p2 - sum);
			for (p2 = p1; p2 < p1 + N; ++p2)
				*p2 = ch;

			len1 += sum;
			p1 += N - 1;
			*(str1 + len1) = '\0';
		}

		else
			*p1 = ' ';
	}

	puts(str1);
	return 0;
}