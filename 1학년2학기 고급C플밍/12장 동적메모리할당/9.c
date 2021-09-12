#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int len = 0;
	int len1 = 0, len2 = 0;
	int i = 0, j = 0;
	char** str = NULL;
	char temp[101];
	char* save = NULL;

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

	//정렬 
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N - 1; ++j)
		{
			len1 = strlen(str[j]);
			len2 = strlen(str[j + 1]);

			if (len1 < len2)
			{
				save = str[j];
				str[j] = str[j + 1];
				str[j + 1] = save;
			}
		}
	}

	for (i = 0; i < N; ++i)
		printf("%s\n", str[i]);

	//할당해제 
	for (i = 0; i < N; ++i)
		free(str[i]);
	free(str);
	return 0;
}