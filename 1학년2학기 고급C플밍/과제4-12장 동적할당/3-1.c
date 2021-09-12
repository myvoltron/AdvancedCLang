#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char* studentname;
    char id[5];
    char* subjectname;
    double subjectscore;
} st;

int main()
{
    int N = 0, K = 0;
    int i = 0, j = 0, k = 0;
    int len = 0;
    int info_len = 0;
    st* p_st = NULL;
    st tmp;
    char temp[101];
    char* pc1, * pc2;
    char save[100];

    scanf("%d", &N);
    getchar();
    p_st = (st*)malloc(N * sizeof(st));

    for (i = 0; i < N; ++i)
    {
        gets(temp);
        len = strlen(temp);

        for (pc1 = temp, pc2 = save; pc1 < temp + len; ++pc1, ++pc2)
        {
            if (*pc1 == ' ')
            {
                *pc2 = '\0';
                break;
            }

            *pc2 = *pc1;
        }
        info_len = strlen(save);
        p_st[i].studentname = (char*)malloc((info_len + 1) * sizeof(char));
        strcpy(p_st[i].studentname, save);

        pc1++;
        for (pc1, pc2 = p_st[i].id; pc1 < temp + len; ++pc1, ++pc2)
        {
            if (*pc1 == ' ')
            {
                *pc2 = '\0';
                break;
            }

            *pc2 = *pc1;
        }

        pc1++;
        for (pc1, pc2 = save; pc1 < temp + len; ++pc1, ++pc2)
        {
            if (*pc1 == ' ')
            {
                *pc2 = '\0';
                break;
            }

            *pc2 = *pc1;
        }
        info_len = strlen(save);
        p_st[i].subjectname = (char*)malloc((info_len + 1) * sizeof(char));
        strcpy(p_st[i].subjectname, save);

        pc1++;
        for (pc1, pc2 = save; pc1 <= temp + len; ++pc1, ++pc2)
        {
            if (*pc1 == '\0')
            {
                *pc2 = '\0';
                break;
            }

            *pc2 = *pc1;
        }
        p_st[i].subjectscore = atof(save);
    }

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N - 1; ++j)
        {
            if (p_st[j].subjectscore < p_st[j + 1].subjectscore)
            {
                tmp = p_st[j];
                p_st[j] = p_st[j + 1];
                p_st[j + 1] = tmp;
            }
        }
    }

    scanf("%d", &K);
    K -= 1;

    printf("%s %s %s %.2lf", p_st[K].studentname, p_st[K].id, p_st[K].subjectname, p_st[K].subjectscore);

    for (i = 0; i < N; ++i)
    {
        free(p_st[i].studentname);
        free(p_st[i].subjectname);
    }
    free(p_st);
    return 0;
}