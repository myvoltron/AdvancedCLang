#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct complexnumber
{
    double n1;
    double n2;
    double ab;
} com;

com add(com num1, com num2);
com sub(com num1, com num2);
double cal_abs(double n1, double n2);

int main()
{
    com num[3];
    com max, min;
    com result1, result2;
    int i = 0;
    double max_num = 0;
    double min_num = 999;

    for (i = 0; i < 3; ++i)
    {
        scanf("%lf %lf", &num[i].n1, &num[i].n2);
        num[i].ab = cal_abs(num[i].n1, num[i].n2);
    }

    for (i = 0; i < 3; ++i)
    {
        if (num[i].ab > max_num)
        {
            max_num = num[i].ab;
            max = num[i];
        }

        if (num[i].ab < min_num)
        {
            min_num = num[i].ab;
            min = num[i];
        }
    }

    result1 = add(max, min);
    result2 = sub(max, min);

    if (result1.n1 < 0)
        printf("%+.1lf%+.1lfi", result1.n1, result1.n2);
    else
        printf("%.1lf%+.1lfi", result1.n1, result1.n2);
    printf("\n");
    if (result2.n1 < 0)
        printf("%+.1lf%+.1lfi", result2.n1, result2.n2);
    else
        printf("%.1lf%+.1lfi", result2.n1, result2.n2);
    return 0;
}

com add(com num1, com num2)
{
    com result;
    result.n1 = num1.n1 + num2.n1;
    result.n2 = num1.n2 + num2.n2;
    return result;
}
com sub(com num1, com num2)
{
    com result;
    result.n1 = num1.n1 - num2.n1;
    result.n2 = num1.n2 - num2.n2;
    return result;
}

double cal_abs(double n1, double n2)
{
    double result = n1 * n1 + n2 * n2;
    return sqrt(result);
}