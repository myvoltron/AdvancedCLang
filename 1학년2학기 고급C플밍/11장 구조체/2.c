#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct cutime
{
    int hour;
    int min;
    int sec;
};

int main()
{
    struct cutime time[3] = { {0}, {0}, {0} };

    for (int i = 0; i < 2; ++i)
        scanf("%d %d %d", &time[i].hour, &time[i].min, &time[i].sec);

    time[2].sec = time[1].sec - time[0].sec;
    time[2].min = time[1].min - time[0].min;
    time[2].hour = time[1].hour - time[0].hour;

    if (time[2].sec < 0)
    {
        time[2].sec += 60;
        time[2].min -= 1;
    }

    if (time[2].min < 0)
    {
        time[2].min += 60;
        time[2].hour -= 1;
    }

    printf("%d %d %d", time[2].hour, time[2].min, time[2].sec);
    return 0;
}