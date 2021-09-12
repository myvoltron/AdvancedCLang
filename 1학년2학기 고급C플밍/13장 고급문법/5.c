#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void pswap(int** ppx, int** ppy);

int main()
{
    int x, y;
    int* px = &x, * py = &y;

    scanf("%d %d", px, py);
    pswap(&px, &py);
    printf("%d %d", *px, *py);
    return 0;
}

void pswap(int** ppx, int** ppy)
{
    int save;
    save = **ppx;
    **ppx = **ppy;
    **ppy = save;
}