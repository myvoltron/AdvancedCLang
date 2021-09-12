#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int strlen(char*);
int strcmp(char*, char*);
void strcpy(char*, char*);
void strcat(char*, char*);

int main()
{
	char str1[101];
	char str2[101];
	int len1 = 0;
	int len2 = 0;

	gets(str1);
	gets(str2);

	if (strcmp(str1, str2) > 0)
	{
		strcat(str2, str1);
		puts(str2);
	}

	else if (strcmp(str1, str2) < 0)
	{
		strcat(str1, str2);
		puts(str1);
	}
	return 0;
}

int strlen(char* str1)
{
	char* p1;
	int len1 = 0;

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

void strcpy(char* str1, char* str2)
{
	char* p1, * p2;

	int len2 = 0;

	len2 = strlen(str2);

	for (p1 = str1, p2 = str2; p2 < str2 + len2; ++p1, ++p2)
		*p1 = *p2;
}

void strcat(char* str1, char* str2)
{
	char* p1, * p2;
	int len1 = 0, len2 = 0;
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (p1 = str1 + len1, p2 = str2; p2 <= str2 + len2; ++p1, ++p2)
		*p1 = *p2;
}