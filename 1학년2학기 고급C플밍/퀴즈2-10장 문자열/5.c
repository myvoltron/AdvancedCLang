#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int strlen(char*);
int strcmp(char*, char*);
void strcpy(char*, char*);
void strcat(char*, char*);

int main()
{
	char str1[1001];
	char word[100][1001];

	int len1 = 0;
	int len2 = 0;

	char* p1, * p2;

	int i = 0, j = 0;
	int word_cnt = 0;
	int len = 0;

	gets(str1);
	len1 = strlen(str1);

	for (p1 = str1; p1 < str1 + len1; ++p1)
	{
		if (*p1 == ' ')
		{
			word[i][j] = '\0';
			i++;
			j = 0;
			continue;
		}

		word[i][j++] = *p1;
	}

	word[i][j] = '\0';
	word_cnt = i + 1; //단어의 개수
	/////단어 분리 완료

	for (i = 0; i < word_cnt; ++i)
		puts(word[i]);

	for (i = 0; i < word_cnt; ++i)
	{
		for (j = 0; j < word_cnt - 1; ++j)
		{
			if (strcmp(word[j], word[j + 1]) > 0)
			{
				strcpy(str1, word[j]);
				strcpy(word[j], word[j + 1]);
				strcpy(word[j + 1], str1);
			}
		}
	}

	for (i = 0; i < word_cnt; ++i)
		puts(word[i]);
	return 0;
}


///////문자열 함수
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

	for (p1 = str1, p2 = str2; p2 <= str2 + len2; ++p1, ++p2)
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