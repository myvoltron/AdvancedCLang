#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len = 0;

int check(char*);

int main()
{
    char str[31];

    //���ڿ��� �Է¹ް� ���ڿ��� ���̸� �����Ѵ�.
    scanf("%s", str);
    len = strlen(str);

    //���ڿ����� ���
    printf("%d ", len);

    //check�Լ� ȣ��
    printf("%d", check(str));
    return 0;
}

//ȸ�����θ� �Ǵ��ϰ� ȸ���� ��� 1, �ƴϸ� 0�� ��ȯ�Ѵ�.
int check(char* str)
{
    int i;
    int cnt = 0;

    for (i = 0; i < len; ++i)
    {
        if (*(str + i) != *(str + len - 1 - i))
            cnt++;
    }

    if (cnt > 0)
        return 0;

    return 1;
}