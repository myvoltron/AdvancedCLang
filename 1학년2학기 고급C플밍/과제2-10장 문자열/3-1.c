#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int strlen(char*);
int strcmp(char*, char*);
void strcat(char*, char*);
void strcpy(char*, char*);

int main()
{
	char str1[100];
	char str2[100];
	int len1 = 0;
	int len2 = 0;

	char* p1, * p2;

	int cnt1 = 0, cnt2 = 0;
	int same_cnt = 0;

	int i = 0, j = 0;

	gets(str1);
	gets(str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		cnt1 = 0;
		i = 0;

		for (p2 = str2; p2 < str2 + len2; ++p2)
		{
			if (*(p1 + i++) == *p2)
				cnt1++;
		}

		if (cnt1 == len2)
		{
			p1 += i - 1;
			same_cnt++;
		}
	}

	printf("%d", same_cnt);
}

//strÇÔ¼öµé 
int strlen(char* str1)
{
	int len1 = 0;
	char* p1;

	for (p1 = str1; *p1; ++p1)
		len1++;

	return len1;
}

int strcmp(char* str1, char* str2)
{
	char* p1, * p2;

	for (p1 = str1, p2 = str2; *p1 || *p2; ++p1, ++p2)
	{
		if (*p1 > *p2)
			return 1;
		else if (*p1 < *p2)
			return -1;
		else if (*p1 == *p2)
			continue;
	}

	return 0;
}

void strcat(char* str1, char* str2)
{
	char* p1, * p2;

	int len1 = 0, len2 = 0;

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (p1 = str1 + len1, p2 = str2; p2 < str2 + len2; ++p1, ++p2)
		*p1 = *p2;
}

void strcpy(char* str1, char* str2)
{
	char* p1, * p2;

	int len2 = strlen(str2);

	for (p1 = str1, p2 = str2; p2 <= str2 + len2; ++p1, ++p2)
		*p1 = *p2;
}