#pragma warning(disable:4996)
#include <stdio.h> 

int mid(int a[])
{
    int i, j;
    int tmp = 0;

    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 2; ++j)
        {
            if (a[j] >= a[j + 1])
            {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

    return a[1];
}

int main()
{
    int x[3];
    int midnum;

    for (int i = 0; i < 3; ++i)
    {
        scanf("%d", &x[i]);
    }

    midnum = mid(x);

    printf("%d", midnum);

    return 0;
}