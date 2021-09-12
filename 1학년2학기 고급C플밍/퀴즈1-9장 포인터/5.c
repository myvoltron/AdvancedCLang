#pragma warning(disable:4996)
#include <stdio.h>

int AVG(int*);

int main()
{
    int ar[100];
    int* p1;
    int N;
    int avg = 0;

    scanf("%d", &N);

    while (N > 0)
    {
        for (p1 = ar; ; ++p1)
        {
            scanf("%d", p1);
            if (*p1 == 0) break;
        }

        avg = AVG(ar);

        for (p1 = ar; ; ++p1)
        {
            if (*p1 == 0)
                break;

            if (*p1 <= avg)
                printf("%d ", *p1);
        }

        printf("\n");
        --N;
    }

    return 0;
}

int AVG(int* ar)
{
    int* p1;
    int sum = 0; //합
    int cnt1 = 0; //정수들의 개수

    for (p1 = ar; ; ++p1)
    {
        if (*p1 == 0) break;

        sum += *p1;
        cnt1++;
    }

    return (sum / cnt1);
}