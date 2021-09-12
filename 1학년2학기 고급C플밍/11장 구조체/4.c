#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student_manage
{
    char name[21];
    int s1, s2, s3;
};

int main()
{
    struct student_manage st[20];
    int N;
    double avg = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        scanf("%s", st[i].name);
        scanf("%d %d %d", &st[i].s1, &st[i].s2, &st[i].s3);

        avg = (double)(st[i].s1 + st[i].s2 + st[i].s3) / 3;

        printf("%s ", st[i].name);
        printf("%.1f ", avg);

        if (avg >= 90)
            printf("A\n");
        else if (avg >= 80 && avg < 90)
            printf("B\n");
        else if (avg >= 70 && avg < 80)
            printf("C\n");
        else if (avg < 70)
            printf("F\n");
    }

    return 0;
}