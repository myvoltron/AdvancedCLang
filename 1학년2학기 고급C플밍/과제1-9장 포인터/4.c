#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main()
{
    int a[12], b[12];

    int n = 0, m = 0;
    int* p1, * p2, * p3;
    int tmp = 0;

    //�迭 a�� �Է��� �ϰ� n�� ���ϱ�
    for (p1 = a; ; ++p1)
    {
        scanf("%d", p1);
        if (*p1 == 0)
            break;
        n++;
    }

    //�迭 b�� �Է��� �ϰ� m�� ���ϱ�
    for (p1 = b; ; ++p1)
    {
        scanf("%d", p1);
        if (*p1 == 0)
            break;
        m++;
    }

    //�켱 a�迭 �������� ����
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

    //b�迭�� ���ؼ� a�迭 ���� �ϼ�
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

    //b�迭 ����
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

    //������ ���
    for (p1 = a; p1 < a + n; ++p1)
        printf("%d ", *p1);
    printf("\n");
    for (p1 = b; p1 < b + m; ++p1)
        printf("%d ", *p1);
    return 0;
}