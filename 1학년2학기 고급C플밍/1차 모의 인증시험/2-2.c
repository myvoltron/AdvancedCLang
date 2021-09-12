#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	char word[100][100];
	char* p1, * p2;
	int len1 = 0;
	int i = 0, j = 0;
	int N = 0;
	int word_cnt = 0;

	gets(str1);
	len1 = strlen(str1);
	scanf("%d", &N);

	for (p1 = str1; p1 <= str1 + len1; ++p1)
	{
		if (*p1 == ' ')
		{
			word[i][j] = '\0';
			i++;
			j = 0;
			continue;
		}
		else if (*p1 == '\0')
		{
			word[i][j] = '\0';
			i++;
			j = 0;
			break;
		}
		word[i][j++] = *p1;
	}
	word_cnt = i;

	puts(word[N - 1]);

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

	puts(word[0]);
	return 0;
}