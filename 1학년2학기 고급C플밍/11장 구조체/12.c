#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

//����ü student�Դϴ�. �л� ������ ���õ� ������ �����մϴ�.
struct student
{
    char name[10];
    int s1, s2, s3;
    double avg;
};

//�Լ����� ����
void read_data(struct student*);
void cal_avg(struct student*);
void sort(struct student*);
void print_score(struct student*);

int main()
{
    struct student st[10]; //����ü student�� �迭 st[10]�� �����մϴ�.
    int i = 0;

    read_data(st);
    cal_avg(st);
    sort(st);
    print_score(st);
    return 0;
}

//�� �л��� �̸��� ����� ������ �Է¹޽��ϴ�.
void read_data(struct student* st)
{
    struct student* p1;

    for (p1 = st; p1 < st + 10; ++p1)
        scanf("%s %d %d %d", p1->name, &p1->s1, &p1->s2, &p1->s3);
}

//�� �л��� ���� ���� ��հ��� ���մϴ�.
void cal_avg(struct student* st)
{
    struct student* p1;

    for (p1 = st; p1 < st + 10; ++p1)
        p1->avg = ((p1->s1) + (p1->s2) + (p1->s3)) / 3.0;
}

//��հ��� ���� �л����� �̸��� ���� �������� ������ ������ �����Ѵ�.
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
                //�̸���ȯ
                strcpy(tmp, p2->name);
                strcpy(p2->name, (p2 + 1)->name);
                strcpy((p2 + 1)->name, tmp);

                //��� ���� ��ȯ
                save = p2->avg;
                p2->avg = (p2 + 1)->avg;
                (p2 + 1)->avg = save;
            }
        }
    }
}

//���� �̸��� ��հ��� ����մϴ�.
void print_score(struct student* st)
{
    struct student* p1;

    p1 = st;

    //�켱 �ְ����� �������� ��츦 ����Ѵ�.
    printf("%s %.2lf\n%s %.2lf\n", p1->name, p1->avg, (p1 + 9)->name, (p1 + 9)->avg);

    //���� ���� 30% �л����� ��츦 ����Ѵ�.
    for (p1 = st + 7; p1 < st + 10; ++p1)
        printf("%s %.2lf\n", p1->name, p1->avg);
}