#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int, int);
int sub(int, int);
int multiply(int, int);

int main()
{
    int x = 0, y = 0;
    int (*handle[3])(int, int) = { add, sub, multiply };
    int i = 0;

    scanf("%d %d", &x, &y);

    for (i = 0; i < 3; ++i)
        printf("%d ", handle[i](x, y));
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
int sub(int x, int y)
{
    return x - y;
}
int multiply(int x, int y)
{
    return x * y;
}