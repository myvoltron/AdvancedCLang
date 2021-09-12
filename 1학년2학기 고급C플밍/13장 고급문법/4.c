#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    unsigned int x[4] = { 0 };
    unsigned int result = 0;
    int i = 0;

    for (i = 0; i < 4; ++i)
        scanf("%d", &x[i]);

    for (i = 0; i < 4; ++i)
        x[i] = x[i] << (3 - i) * 8;

    for (i = 0; i < 4; ++i)
        result += x[i];

    printf("%d", result);
    return 0;
}