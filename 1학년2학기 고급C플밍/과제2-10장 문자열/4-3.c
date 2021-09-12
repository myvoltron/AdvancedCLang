#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	char chnum[10];
	char* p1, * p2, * p3;
	double num[10] = { 0 };
	double* pdouble = num;
	double sum = 0;
	int len1 = 0;
	int times = 0;
	int mis = 0;
	int num_cnt = 0;

	gets(str1);
	len1 = strlen(str1);

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		if (*p1 >= '0' && *p1 <= '9')
		{
			times = 0;
			mis = 0;

			if (*(p1 - 1) == '-' || *(p1 - 2) == '-')
				mis = 1;

			for (p2 = p1, p3 = chnum; p2 < str1 + len1; ++p2)
			{
				if (*p2 < '0' || *p2 > '9')
					break;

				*p3 = *p2;
				p3++;
				times++;
			}
			*p3 = '\0';

			if (mis == 1)
			{
				*pdouble = -1 * atof(chnum);
				pdouble++;
			}
			else
			{
				*pdouble = atof(chnum);
				pdouble++;
			}
			p1 += times - 1;
			num_cnt++;
		}
	}

	pdouble = num;

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		if (*p1 == '*')
		{
			if (*pdouble != 0 && *(pdouble + 1) == 0)
				sum *= *pdouble;
			else if (*(pdouble + 1) != 0 && *pdouble == 0)
				sum *= *(pdouble + 1);
			else
				sum += *pdouble * *(pdouble + 1);
			*pdouble = 0;
			*(pdouble + 1) = 0;
			pdouble++;
		}
		else if (*p1 == '/')
		{
			if (*pdouble != 0 && *(pdouble + 1) == 0)
				sum /= *pdouble;
			else if (*(pdouble + 1) != 0 && *pdouble == 0)
				sum /= *(pdouble + 1);
			else
				sum += *pdouble / *(pdouble + 1);
			*pdouble = 0;
			*(pdouble + 1) = 0;
			pdouble++;
		}

		else if (*p1 == '+' || *p1 == '-')
			pdouble++;
	}

	for (pdouble = num; pdouble < num + num_cnt; ++pdouble)
		sum += *pdouble;

	printf("%lf", sum);
	return 0;
}