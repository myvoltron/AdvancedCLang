#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[1001];
	char word[100][1001];
	char* p1, * p2, * p3;
	int k = 0;
	int len = 0, len1 = 0, len2 = 0;
	int i = 0, j = 0;
	int word_cnt = 0;

	gets(str1);
	len = strlen(str1);
	scanf("%d", &k);

	for (p1 = str1; p1 <= str1 + len; ++p1)
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

	for (i = 0; i < word_cnt; ++i)
	{
		for (j = 0; j < word_cnt - 1; ++j)
		{
			len1 = strlen(word[j]);
			len2 = strlen(word[j + 1]);

			if (len1 >= len2)
			{
				if (len1 == len2)
				{
					if (strcmp(word[j], word[j + 1]) > 0)
					{
						strcpy(str1, word[j]);
						strcpy(word[j], word[j + 1]);
						strcpy(word[j + 1], str1);
					}
				}

				else
				{
					strcpy(str1, word[j]);
					strcpy(word[j], word[j + 1]);
					strcpy(word[j + 1], str1);
				}
			}
		}
	}

	puts(word[k - 1]);
	return 0;
}