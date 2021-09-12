#pragma warning(disable:4996)
#include <stdio.h> 

void swap(int* p1, int* p2)
{
    int tmp = 0;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main()
{
    int N; //(N <= 50)

    int x[50];
    int a, b;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &x[i]);
    }

    scanf("%d %d", &a, &b);

    swap(&x[a], &x[b]);

    for (int i = 0; i < N; ++i)
    {
        printf(" %d", x[i]);
    }
    return 0;
}