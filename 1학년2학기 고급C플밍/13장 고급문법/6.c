#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ABC(int(*p)[20], int k1, int k2);

int main()
{
    int N = 0;
    int num[20][20] = { 0 };
    int i = 0, j = 0;

    scanf("%d", &N);
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
            num[i][j] = 0;
    }

    ABC(num, N, N);

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
            printf(" %d", num[i][j]);
        printf("\n");
    }
    return 0;
}

void ABC(int(*p)[20], int k1, int k2)
{
    int i = 0, j = 0;

    for (i = 0; i < k1; ++i)
    {
        for (j = 0; j < k2; ++j)
            (*(p + i))[j] = i + j;
    }
}