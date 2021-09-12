#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	char* p1, * p2, * p3;
	int cnt1 = 0;

	for (p1 = str1; p1 < str1 + 10; ++p1)
		scanf("%c", p1);

	for (p1 = str1; p1 < str1 + 10; ++p1)
	{
		cnt1 = 0;

		for (p2 = str1; p2 < str1 + 10; ++p2)
		{
			if (p2 < p1 && *p1 == *p2)
				break;

			if (*p2 == *p1)
				cnt1++;
		}

		if (cnt1 >= 2)
			printf("%c %d", *p1, cnt1);
	}
	return 0;
}