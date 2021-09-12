#pragma warning(disable:4996)
#include <stdio.h> 

int arrsum(int*, int*);

int main()
{
    int N, S, E;
    int arr[100];
    int* p;

    scanf("%d %d %d", &N, &S, &E);

    for (p = arr; p < arr + N; ++p) scanf("%d", p);

    printf("%d", arrsum(arr + S, arr + E));
    return 0;
}

int arrsum(int* s, int* e)
{
    int* p;
    int sum = 0;

    for (p = s; p <= e; ++p) sum += *p;

    return sum;
}