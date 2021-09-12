#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct school
{
    char name[10];
    int score;
};

int main()
{
    struct school st[5];

    int i;
    int sum = 0, avg = 0;

    for (i = 0; i < 5; ++i)
    {
        scanf("%s", st[i].name);
        scanf("%d", &st[i].score);

        sum += st[i].score;
    }

    avg = sum / 5;

    for (i = 0; i < 5; ++i)
    {
        if (st[i].score <= avg)
            printf("%s\n", st[i].name);
    }
    return 0;
}