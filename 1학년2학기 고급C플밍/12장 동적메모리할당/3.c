#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N = 0;
	int i = 0;
	int cnt1 = 0, cnt2 = 0;
	char* str = NULL;
	char a, b;

	scanf("%d", &N);
	getchar();

	str = (char*)malloc(N * sizeof(char));
	for (i = 0; i < N; ++i)
		scanf("%c", &str[i]);
	getchar();

	scanf("%c %c", &a, &b);

	for (i = 0; i < N; ++i)
	{
		if (str[i] == a)
			cnt1++;
		if (str[i] == b)
			cnt2++;
	}

	printf("%d %d", cnt1, cnt2);

	free(str);
	return 0;
}