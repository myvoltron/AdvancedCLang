#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main()
{
    int a[12], b[12];

    int n = 0, m = 0;
    int* p1, * p2, * p3;
    int tmp = 0;

    //배열 a에 입력을 하고 n값 구하기
    for (p1 = a; ; ++p1)
    {
        scanf("%d", p1);
        if (*p1 == 0)
            break;
        n++;
    }

    //배열 b에 입력을 하고 m값 구하기
    for (p1 = b; ; ++p1)
    {
        scanf("%d", p1);
        if (*p1 == 0)
            break;
        m++;
    }

    //우선 a배열 내림차순 정렬
    for (p1 = a; p1 < a + n; ++p1)
    {
        for (p2 = a; p2 < a + n - 1; ++p2)
        {
            if (*p2 < *(p2 + 1))
            {
                tmp = *p2;
                *p2 = *(p2 + 1);
                *(p2 + 1) = tmp;
            }
        }
    }

    //b배열도 비교해서 a배열 정렬 완성
    for (p1 = b; p1 < b + m; ++p1)
    {
        for (p2 = b; p2 < b + m; ++p2)
        {
            for (p3 = a; p3 < a + n; ++p3)
            {
                if (*p2 > *p3)
                {
                    tmp = *p2;
                    *p2 = *p3;
                    *p3 = tmp;
                }
            }
        }
    }

    //b배열 정렬
    for (p1 = b; p1 < b + m; ++p1)
    {
        for (p2 = b; p2 < b + m - 1; ++p2)
        {
            if (*p2 > *(p2 + 1))
            {
                tmp = *p2;
                *p2 = *(p2 + 1);
                *(p2 + 1) = tmp;
            }
        }
    }

    //마지막 출력
    for (p1 = a; p1 < a + n; ++p1)
        printf("%d ", *p1);
    printf("\n");
    for (p1 = b; p1 < b + m; ++p1)
        printf("%d ", *p1);
    return 0;
}