#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int i = 0;
	int len = 0;
	int index = 0;
	int min_len = 999;
	char** str = NULL;
	char temp[101];

	scanf("%d", &N);
	getchar();
	str = (char**)malloc(N * sizeof(char*));

	for (i = 0; i < N; ++i)
	{
		gets(temp);
		len = strlen(temp);

		str[i] = (char*)malloc((len + 1) * sizeof(char));
		strcpy(str[i], temp);
	}

	for (i = 0; i < N; ++i)
	{
		if (strlen(str[i]) < min_len)
		{
			index = i;
			min_len = strlen(str[i]);
		}
	}

	printf("%s", str[index]);

	for (i = 0; i < N; ++i)
		free(str[i]);
	free(str);
	return 0;
}