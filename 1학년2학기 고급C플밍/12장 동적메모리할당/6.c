#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int i = 0;
	int cnt = 0;
	char* str = NULL;

	scanf("%d", &N);
	getchar();

	str = (char*)malloc(N * sizeof(char));
	for (i = 0; i < N; ++i)
		scanf("%c", &str[i]);

	for (i = 0; i < N - 2; ++i)
	{
		if (str[i] == 'c' && str[i + 1] == 'a' && str[i + 2] == 't')
			cnt++;
	}

	printf("%d", cnt);

	free(str);
	return 0;
}