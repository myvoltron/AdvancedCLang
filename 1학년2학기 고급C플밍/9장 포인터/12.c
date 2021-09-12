#pragma warning(disable:4996)
#include <stdio.h> 

void addArray(int*, int*, int*, int);

int main()
{
    int arr1[20];
    int arr2[20];
    int arr3[20];

    int* p;
    int N;

    scanf("%d", &N);

    for (p = arr1; p < arr1 + N; ++p) scanf("%d", p);

    for (p = arr2 + N - 1; p >= arr2; --p) scanf("%d", p);

    addArray(arr1, arr2, arr3, N);

    for (p = arr3; p < arr3 + N; ++p) printf(" %d", *p);

    return 0;
}

void addArray(int* x, int* y, int* z, int N)
{
    int* p;

    for (p = x; p < x + N; ++p)
    {
        *(z++) = *p + *(y++);
    }
}