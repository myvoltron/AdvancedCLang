#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char** ptr = NULL;
	char ch = 'a';
	int i = 0, j = 0;
	int k = 0, l = 0;

	scanf("%d %d", &i, &j);

	ptr = (char**)malloc(j * sizeof(char*));
	for (k = 0; k < j; ++k)
		ptr[k] = (char*)malloc(i * sizeof(char));

	for (k = 0; k < j; ++k)
	{
		for (l = 0; l < i; ++l)
		{
			ptr[k][l] = ch;

			if (ch == 'z')
			{
				ch = 'A';
				continue;
			}
			else if (ch == 'Z')
			{
				ch = 'a';
				continue;
			}

			ch++;
		}
	}

	for (k = 0; k < j; ++k)
	{
		for (l = 0; l < i; ++l)
			printf("%c ", ptr[k][l]);

		printf("\n");
	}

	for (k = 0; k < j; ++k)
		free(ptr[k]);
	free(ptr);
	return 0;
}