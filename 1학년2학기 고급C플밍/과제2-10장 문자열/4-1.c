#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[101];
    char num[100]; //���ڼ��ڵ� �ӽ�����
    float number[10];

    char* p1;

    int len1 = 0;
    int i = 0, j = 0;

    //���ڿ��� �Է¹޴´�
    gets(str1);

    //���ڿ��� ���̸� ����
    len1 = strlen(str1);

    j = 0;

    for (p1 = str1; p1 < str1 + len1; ++p1)
    {
        if (*p1 >= '0' && *p1 <= '9')
        {
            i = 0;

            while (1)
            {
                if (*(p1 + i) < '0' || *(p1 + i) > '9')
                    break;

                num[i] = *(p1 + i);
                i++;
            }

            num[i] = '\0';
            p1 += i;
            number[j++] = atof(num);
        }
    }

    for (i = 0; i < j; ++i)
        printf(" %.0lf", number[i]);
    return 0;
}