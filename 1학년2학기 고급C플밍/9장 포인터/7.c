#pragma warning(disable:4996)
#include <stdio.h> 

void input(int* p1, int* p2, int* p3)
{
    scanf("%d %d %d", p1, p2, p3);
}

void output(int* p1, int* p2, int* p3)
{
    printf("%d %d %d", *p1, *p2, *p3);
}

int main()
{
    int x, y, z;
    input(&x, &y, &z);
    output(&x, &y, &z);

    return 0;
}