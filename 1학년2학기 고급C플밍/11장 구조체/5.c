#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student
{
    char name[8];
    int sc_k, sc_e, sc_m;
    double avg;
    char gd;
};

int main()
{
    struct student st[50], * p = st;
    int N;

    int i = 0;

    scanf("%d", &N);
    getchar();

    for (p = st; p < st + N; ++p)
    {
        //입력부분
        scanf("%s", p->name);
        scanf("%d %d %d", &(p->sc_k), &(p->sc_e), &(p->sc_m));

        //평균 성적 산출
        p->avg = (p->sc_k + p->sc_e + p->sc_m) / 3.0;

        //학점 설정
        if (p->avg >= 90 && p->avg <= 100)
            p->gd = 'A';
        else if (p->avg >= 80 && p->avg < 90)
            p->gd = 'B';
        else if (p->avg >= 70 && p->avg < 80)
            p->gd = 'C';
        else if (p->avg < 70)
            p->gd = 'D';
    }

    //출력
    for (p = st; p < st + N; ++p)
        printf("%s %.1lf %c\n", p->name, p->avg, p->gd);
    return 0;
}