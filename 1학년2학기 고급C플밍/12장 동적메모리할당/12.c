#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int i = 0, j = 0;
	int len = 0;
	char** str = NULL;
	char tmp[101];
	char* p_save;

	scanf("%d", &N);
	str = (char**)malloc(N * sizeof(char*));

	for (i = 0; i < N; ++i)
	{
		scanf("%s", tmp);
		len = strlen(tmp);

		str[i] = (char*)malloc((len + 1) * sizeof(char));
		strcpy(str[i], tmp);
	}

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N - 1; ++j)
		{
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				p_save = str[j];
				str[j] = str[j + 1];
				str[j + 1] = p_save;
			}
		}
	}

	for (i = 0; i < N; ++i)
		printf("%s\n", str[i]);

	for (i = 0; i < N; ++i)
		free(str[i]);
	free(str);
	return 0;
}