#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	double num[10];
	int len1 = 0;
	char chnum[10];
	char* p1, * p2, * p3;
	double* pnum = num;
	int i = 0;
	int num_cnt = 0;
	int minus = 0;

	gets(str1);
	len1 = strlen(str1);

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		minus = 0;

		if (*p1 >= '0' && *p1 <= '9')
		{
			i = 0;
			if (*(p1 - 1) == '-' || *(p1 - 2) == '-')
				minus = 1;

			for (p2 = p1, p3 = chnum; p2 < str1 + len1; ++p2)
			{
				if (*p2 < '0' || *p2 > '9')
					break;

				*p3 = *p2;
				p3++;
				i++;
			}
			*p3 = '\0';

			if (minus == 1)
				*pnum = atof(chnum) * -1;
			else
				*pnum = atof(chnum);

			pnum++;
			p1 += i - 1;
			num_cnt++;
		}
	}

	for (pnum = num; pnum < num + num_cnt; ++pnum)
		printf(" %.0lf", *pnum);
	return 0;
}