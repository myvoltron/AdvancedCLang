#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student
{
    char name[9];
    int score;
};

struct student* select_min(struct student* p_st)
{
    int min = p_st->score;

    struct student* pmin = p_st;
    struct student* p1;

    for (p1 = p_st + 1; p1 < p_st + 5; ++p1)
    {
        if (p1->score < min)
        {
            min = p1->score;
            pmin = p1;
        }
    }

    return pmin;
}

int main()
{
    struct student st[5];
    struct student* p1;

    for (p1 = st; p1 < st + 5; ++p1)
    {
        scanf("%s %d", p1->name, &p1->score);
    }

    p1 = select_min(st);

    printf("%s %d", p1->name, p1->score);
    return 0;
}