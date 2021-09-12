#pragma warning(disable:4996)
#include <stdio.h> 

int add_to_k(int*, int*);

int main()
{
    int N;
    int d[100];
    int* p;
    int sum = 0;

    scanf("%d", &N);

    for (p = d; p < d + N; ++p)
    {
        scanf("%d", p);
        sum += add_to_k(d, p);
    }

    printf("%d", sum);

    return 0;
}

int add_to_k(int* p1, int* p2)
{
    int* p;
    int sum = 0;

    for (p = p1; p <= p2; ++p) sum += *p;

    return sum;
}