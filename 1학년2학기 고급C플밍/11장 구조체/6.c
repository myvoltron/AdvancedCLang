#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct student_manage
{
    int gender;
    int weight;
    int height;
};

//��ü��޺� �ο� �� ���ϱ�
int main()
{
    struct student_manage st[10];
    int grade[3] = { 0 };
    int N; // �л��� ��

    int i;

    scanf("%d", &N);

    for (i = 0; i < N; ++i)
    {
        scanf("%d %d %d", &st[i].gender, &st[i].weight, &st[i].height);

        if (st[i].gender == 1)
        {
            if (st[i].height >= 175)
            {
                if (st[i].weight >= 70)
                    grade[0]++;
                else if (st[i].weight >= 60 && st[i].weight < 70)
                    grade[1]++;
                else if (st[i].weight < 60)
                    grade[2]++;
            }

            else if (st[i].height >= 165 && st[i].height < 175)
            {
                if (st[i].weight >= 70)
                    grade[2]++;
                else if (st[i].weight >= 60 && st[i].weight < 70)
                    grade[0]++;
                else if (st[i].weight < 60)
                    grade[1]++;
            }

            else
            {
                if (st[i].weight >= 70)
                    grade[1]++;
                else if (st[i].weight >= 60 && st[i].weight < 70)
                    grade[2]++;
                else if (st[i].weight < 60)
                    grade[0]++;
            }
        }

        else
        {
            if (st[i].height >= 175)
            {
                if (st[i].weight >= 60)
                    grade[0]++;
                else if (st[i].weight >= 50 && st[i].weight < 60)
                    grade[1]++;
                else if (st[i].weight < 50)
                    grade[2]++;
            }

            else if (st[i].height >= 165 && st[i].height < 175)
            {
                if (st[i].weight >= 60)
                    grade[2]++;
                else if (st[i].weight >= 50 && st[i].weight < 60)
                    grade[0]++;
                else if (st[i].weight < 50)
                    grade[1]++;
            }

            else
            {
                if (st[i].weight >= 60)
                    grade[1]++;
                else if (st[i].weight >= 50 && st[i].weight < 60)
                    grade[2]++;
                else if (st[i].weight < 50)
                    grade[0]++;
            }
        }
    }

    for (i = 0; i < 3; ++i)
        printf("%d ", grade[i]);
    return 0;
}