#pragma warning(disable:4996)
#include <stdio.h> 

void gcdlcm(int a, int b, int* max, int* min)
{
    int i, j;

    //�ִ�����
    for (i = 1; i < (a < b ? b : a); ++i)
    {
        if (a % i == 0 && b % i == 0) *max = i;
    }

    //�ּҰ����
    *min = a * b / *max;
}

int main()
{
    int a, b;
    int max, min;

    scanf("%d %d", &a, &b);

    gcdlcm(a, b, &max, &min);

    printf("%d %d", max, min);
    return 0;
}