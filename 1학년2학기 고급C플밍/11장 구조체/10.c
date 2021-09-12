#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct date
{
    int year;
    int month;
    int day;
};

struct date* select_min(struct date* p1, struct date* p2)
{
    if (p1->year < p2->year)
        return p1;
    else if (p1->year > p2->year)
        return p2;

    if (p1->month < p2->month)
        return p1;
    else if (p1->month > p2->month)
        return p2;

    if (p1->day < p2->day)
        return p1;
    else if (p1->day > p2->day)
        return p2;
}

int main()
{
    struct date n1, n2;
    struct date* p;

    scanf("%d/%d/%d", &n1.year, &n1.month, &n1.day);
    scanf("%d/%d/%d", &n2.year, &n2.month, &n2.day);

    p = select_min(&n1, &n2);

    printf("%d/%d/%d", p->year, p->month, p->day);
    return 0;
}