#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char name[9];
    int score1, score2, score3;
    double avg;
} st;

int main()
{
    int N = 0;
    int len = 0;
    int i = 0, j = 0, k = 0;
    st* p_st = NULL;
    st save;

    scanf("%d", &N);
    p_st = (st*)malloc(N * sizeof(st));

    for (i = 0; i < N; ++i)
    {
        scanf("%s %d %d %d", p_st[i].name, &p_st[i].score1, &p_st[i].score2, &p_st[i].score3);
        p_st[i].avg = p_st[i].score1 + p_st[i].score2 + p_st[i].score3;
        p_st[i].avg /= 3.0;
    }

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N - 1; ++j)
        {
            if (p_st[j].avg < p_st[j + 1].avg)
            {
                save = p_st[j];
                p_st[j] = p_st[j + 1];
                p_st[j + 1] = save;
            }
        }
    }

    for (i = 0; i < N; ++i)
        printf("%s %.1lf\n", p_st[i].name, p_st[i].avg);

    free(p_st);
    return 0;
}