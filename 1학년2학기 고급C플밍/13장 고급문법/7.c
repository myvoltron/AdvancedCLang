#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add(int x, int y);

int main()
{
    int A = 0;
    void* ptr;

    scanf("%d", &A);

    ptr = &A;

    printf("%d", *(int*)ptr);

    int x, y;
    int(*fp)(int, int) = add;

    scanf("%d %d", &x, &y);

    printf("%d", fp(x, y));
    return 0;
}

int add(int x, int y)
{
    return x + y;
}