#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
    int arr[5];

    int* p1, * p2;
    int tmp = 0;

    for (p1 = arr; p1 < arr + 5; ++p1)
        scanf("%d", p1);

    for (p1 = arr; p1 < arr + 5; ++p1)
    {
        for (p2 = arr; p2 < arr + 4; ++p2)
        {
            if (*p2 < *(p2 + 1))
            {
                tmp = *p2;
                *p2 = *(p2 + 1);
                *(p2 + 1) = tmp;
            }
        }
    }

    p1 = arr;

    printf("%d", *(p1 + 2));
    return 0;
}