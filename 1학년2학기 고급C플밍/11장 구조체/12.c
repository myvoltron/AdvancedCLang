#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

//구조체 student입니다. 학생 정보와 관련된 변수를 포함합니다.
struct student
{
    char name[10];
    int s1, s2, s3;
    double avg;
};

//함수원형 설정
void read_data(struct student*);
void cal_avg(struct student*);
void sort(struct student*);
void print_score(struct student*);

int main()
{
    struct student st[10]; //구조체 student형 배열 st[10]을 선언합니다.
    int i = 0;

    read_data(st);
    cal_avg(st);
    sort(st);
    print_score(st);
    return 0;
}

//각 학생의 이름과 퀴즈당 점수를 입력받습니다.
void read_data(struct student* st)
{
    struct student* p1;

    for (p1 = st; p1 < st + 10; ++p1)
        scanf("%s %d %d %d", p1->name, &p1->s1, &p1->s2, &p1->s3);
}

//각 학생의 퀴즈 점수 평균값을 구합니다.
void cal_avg(struct student* st)
{
    struct student* p1;

    for (p1 = st; p1 < st + 10; ++p1)
        p1->avg = ((p1->s1) + (p1->s2) + (p1->s3)) / 3.0;
}

//평균값에 따라 학생들의 이름과 퀴즈 점수들을 내림차 순으로 정렬한다.
void sort(struct student* st)
{
    struct student* p1, * p2;
    char tmp[10];
    double save;
    for (p1 = st; p1 < st + 10; ++p1)
    {
        for (p2 = st; p2 < st + 9; ++p2)
        {
            if (p2->avg < (p2 + 1)->avg)
            {
                //이름교환
                strcpy(tmp, p2->name);
                strcpy(p2->name, (p2 + 1)->name);
                strcpy((p2 + 1)->name, tmp);

                //평균 점수 교환
                save = p2->avg;
                p2->avg = (p2 + 1)->avg;
                (p2 + 1)->avg = save;
            }
        }
    }
}

//이후 이름과 평균값을 출력합니다.
void print_score(struct student* st)
{
    struct student* p1;

    p1 = st;

    //우선 최고점과 최저점의 경우를 출력한다.
    printf("%s %.2lf\n%s %.2lf\n", p1->name, p1->avg, (p1 + 9)->name, (p1 + 9)->avg);

    //이후 하위 30% 학생들의 경우를 출력한다.
    for (p1 = st + 7; p1 < st + 10; ++p1)
        printf("%s %.2lf\n", p1->name, p1->avg);
}