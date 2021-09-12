#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

/*
struct student
{
    char name[8];
    int sc_k,sc_e,sc_m;
    double avg;
    char gd;
};
*/

struct complex
{
    double x;
    double y;
};

struct complex add(struct complex n1, struct complex n2)
{
    struct complex n;

    n.x = n1.x + n2.x;
    n.y = n1.y + n2.y;

    return n;
}

int main()
{
    struct complex n1, n2;

    scanf("%lf %lf", &n1.x, &n1.y);
    scanf("%lf %lf", &n2.x, &n2.y);

    n1 = add(n1, n2);

    printf("%.1lf + %.1lfi", n1.x, n1.y);

    return 0;
}