#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
    char str1[42];
    char str2[21];

    int N = 0; // ������ġ
    int S; //���� ����
    int cnt1 = 0, cnt2 = 0; //str1, str2 ���� ���ϱ�
    int i = 0, j = 0;

    scanf("%s", str1);
    getchar();
    scanf("%s", str2);

    scanf("%d", &N); //������ġ �Է�
    scanf("%d", &S); //�������� �Է�

    //str1 �� str2�� ���̸� ���մϴ�.
    while (1)
    {
        if (str1[i++] == '\0') break;
        cnt1++;
    }

    i = 0;

    while (1)
    {
        if (str2[i++] == '\0') break;
        cnt2++;
    }

    //str2�� str1�� �����ϴ� ������ �����մϴ�.
    for (i = cnt1 + cnt2 - 1; i >= cnt2 + N; --i)
    {
        str1[i] = str1[i - cnt2];
    }

    //str1�� �������κп� NULL���ڸ� ����
    str1[cnt1 + cnt2] = '\0';

    //���� ���� S�� ���� ���� ���������� �ϰų� ���������� �մϴ�.
    if (S == 0) //����
    {
        for (i = N, j = 0; i < N + cnt2; ++i, ++j)
        {
            str1[i] = str2[j];
        }
    }

    else if (S == 1) //����
    {
        for (i = N, j = cnt2 - 1; i < N + cnt2; ++i, --j)
        {
            str1[i] = str2[j];
        }
    }
    //���
    printf("%s", str1);
    return 0;
}