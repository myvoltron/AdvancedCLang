#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	char str2[100];
	char* p1, * p2, * p3;
	int len1 = 0, len2 = 0;
	int cnt1 = 0, cnt2 = 0;

	gets(str1);
	gets(str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		cnt1 = 0;

		for (p2 = str2, p3 = p1; p2 < str2 + len2; ++p2, ++p3)
		{
			if (*(p1 - 1) >= 'A' && *(p1 - 1) <= 'Z' || *(p1 - 1) >= 'a' && *(p1 - 1) <= 'z')
				break;
			if (*(p1 + len2) >= 'A' && *(p1 + len2) <= 'Z' || *(p1 + len2) >= 'a' && *(p1 + len2) <= 'z')
				break;

			if (*p2 == *p3)
				cnt1++;
		}

		if (cnt1 == len2)
			cnt2++;
	}

	printf("%d", cnt2);
	return 0;
}