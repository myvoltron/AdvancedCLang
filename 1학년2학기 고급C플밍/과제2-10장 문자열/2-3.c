#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[100]; //�Է¹��� �迭
    char word[10][100]; //�и��� �ܾ���� ���� ���߹迭
    char firstword[100] = ""; //���������� ���� ���� �ܾ ���� �迭
    char* p1; //������ ������

    int len1; //�Է¹��� ���ڿ��� ����
    int i, j;
    int cnt = 0; //�ܾ��� ���� ����

    //���ڿ� �Է�, ���ڿ��� ���� ����
    gets(str1);
    len1 = strlen(str1);

    i = 0; //i, j�� 0���� �ʱ�ȭ
    j = 0;

    //������ �������� �ؼ� �ܾ���� word�迭�� ����
    for (p1 = str1; p1 <= str1 + len1; ++p1) // -> ������ ����� �ݺ��� ����
    {

        if (*p1 != ' ') //*p1�� ������ �ƴϸ� word�迭�� *p1 ����
        {
            word[i][j++] = *p1;
        }

        else if (*p1 == ' ') //���� ������ �´ٸ�
        {
            word[i][j] = '\0'; //word�� '\0'�� �����ؼ� ���ڿ��� �ϼ��Ѵ�.
            j = 0; //j�� 0���� �ʱ�ȭ�ϰ� i�� 1������Ŵ
            i++;
        }
    }

    cnt = i + 1; //�ܾ��� ����

    //�и��� �ܾ�� ���
    for (i = 0; i < cnt; ++i)
        puts(word[i]);


    strcpy(firstword, word[0]); //�켱 firstword�� word�迭�� ù��° �ܾ ����

    for (i = 1; i < cnt; ++i)
    {
        if (strcmp(firstword, word[i]) > 0) //���� firstword�� �ִ� �ܾ�� word[i]�� �ִ� �ܾ ���������� �� �����ٸ� firstword�� word[i] ����.
        {
            strcpy(firstword, word[i]);
        }
    }

    //���������� firstword ���
    puts(firstword);
    return 0;
}