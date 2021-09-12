#pragma warning(disable:4996)
#include <stdio.h> 

void ABC(int*, int);

int main()
{
    int arr[10];
    int* p;
    int k = 10;

    for (p = arr; p < arr + 10; ++p) scanf("%d", p);

    for (p = arr; p < arr + 9; ++p)
    {
        ABC(p, k--);
    }

    for (p = arr; p < arr + 10; ++p) printf(" %d", *p);
    return 0;
}

void ABC(int* x, int k)
{
    int tmp = -9999;
    int* p;
    int* p1 = NULL;

    int cnt = 0;

    for (p = x; p < x + k; ++p)
    {
        if (*p > tmp)
        {
            tmp = *p;
            p1 = p;
        }
    }

    tmp = *x;
    *x = *p1;
    *p1 = tmp;
}