#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct score
{
    int arr[10];
    int rank[10];
};

//��ü��޺� �ο� �� ���ϱ�
int main()
{
    struct score s;

    int ar[10];
    int sore[10] = { 0 };

    int i = 0, j = 0;

    //���ڵ��� �Է¹޴´�.
    for (i = 0; i < 10; ++i)
        scanf("%d", &ar[i]);

    //����ü �迭�� ������ ������ �����Ѵ�.
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            if (ar[i] <= ar[j])
                sore[i]++;
        }

        s.arr[i] = ar[i];
        s.rank[i] = sore[i];
    }

    //3��° ������ ���ڿ� 7��° ������ ���ڸ� ����Ѵ�.
    for (i = 0; i < 10; ++i)
    {
        if (s.rank[i] == 3)
            printf("%d ", s.arr[i]);
    }

    for (i = 0; i < 10; ++i)
    {
        if (s.rank[i] == 7)
            printf("%d ", s.arr[i]);
    }
    return 0;
}