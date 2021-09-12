#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int N;
    int i;
    int min = 0;

    char str[100][101];
    int len[100];

    scanf("%d", &N);
    getchar();

    for (i = 0; i < N; ++i)
    {
        gets(str[i]);
        len[i] = strlen(str[i]);
    }

    min = 0;

    for (i = 1; i < N; ++i)
    {
        if (len[min] > len[i])
            min = i;
    }

    puts(str[min]);
    return 0;
}