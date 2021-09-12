#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct word
{
	char letters[21];
	int count;
} WORD;

int main()
{
	int N = 0;
	int i = 0, j = 0, k = 0;
	int len = 0;
	int info_len = 0;
	int word_cnt = 0;
	int max_cnt = 0;
	int index = 0;
	char** str = NULL;
	char temp[501];
	char* pc1, * pc2, * pc3;
	char max_word[21];
	WORD* p_word = NULL;

	scanf("%d", &N);
	getchar();

	str = (char**)malloc(N * sizeof(char*));
	if (str == NULL)
	{
		printf("Not Enough Memory");
		return -1;
	}

	for (i = 0; i < N; ++i)
	{
		gets(temp);
		len = strlen(temp);
		str[i] = (char*)malloc((len + 1) * sizeof(char));
		if (str[i] == NULL)
		{
			printf("Not Enough Memory");
			return -1;
		}
		strcpy(str[i], temp);

		for (pc1 = str[i]; pc1 < str[i] + len; ++pc1)
		{
			if (*pc1 >= 'A' && *pc1 <= 'Z')
				*pc1 = 'a' + *pc1 - 'A';
		}
	}

	for (i = 0; i < N; ++i)
	{
		len = strlen(str[i]);

		word_cnt = 0;
		for (pc1 = str[i]; pc1 < str[i] + len; ++pc1)
		{
			if (*pc1 == ' ')
				word_cnt++;
		}
		word_cnt += 1;

		p_word = (WORD*)malloc(word_cnt * sizeof(WORD));
		j = 0;
		for (pc1 = str[i], pc2 = p_word[j].letters; pc1 <= str[i] + len; ++pc1)
		{
			if (*pc1 == ' ')
			{
				*pc2 = '\0';
				j++;
				pc2 = p_word[j].letters;
				continue;
			}
			else if (*pc1 == '\0')
				*pc2 = '\0';

			*pc2 = *pc1;
			pc2++;
		}

		for (j = 0; j < word_cnt; ++j)
		{
			p_word[j].count = 0;
			for (k = 0; k < word_cnt; ++k)
			{
				if (!strcmp(p_word[j].letters, p_word[k].letters))
					p_word[j].count += 1;
			}
		}

		for (j = 0; j < word_cnt; ++j)
		{
			if (p_word[j].count > max_cnt)
			{
				max_cnt = p_word[j].count;
				index = i;
				strcpy(max_word, p_word[j].letters);
			}
		}

		free(p_word);
	}

	printf("%d %d %s", index, max_cnt, max_word);

	for (i = 0; i < N; ++i)
		free(str[i]);
	free(str);
	return 0;
}
