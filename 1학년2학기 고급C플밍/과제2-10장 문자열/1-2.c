#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change(char* str1, int N);

int main()
{
	char str1[100];
	char str2[100];
	char str3[100], str4[100];

	int N = 10;
	int result = 0;

	gets(str1);
	gets(str2);
	strcpy(str3, str1);
	strcpy(str4, str2);

	for (int i = 0; i <= N; ++i)
	{
		strcpy(str1, str3);
		strcpy(str2, str4);

		change(str1, i);
		change(str2, i);

		if (strcmp(str1, str4) == 0)
			result += 1;

		if (strcmp(str2, str3) == 0)
			result += 2;

		if (result >= 1)
			break;
	}

	printf("%d", result);
	return 0;
}

void change(char* str1, int N)
{
	char num[10];
	char ch;
	char* p1, * p2, * p3;

	int times = 0;
	int sum = 0;

	int len1 = strlen(str1);

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		if (*p1 >= 'A' && *p1 <= 'Z')
			*p1 += N;
		else if (*p1 >= 'a' && *p1 <= 'z')
			*p1 -= N;

		else if (*p1 >= '0' && *p1 <= '9')
		{
			times = 0; //ÀÚ¸®¼ö

			for (p2 = p1, p3 = num; ; ++p2)
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
}