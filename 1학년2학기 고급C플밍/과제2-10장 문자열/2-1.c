#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[100];
    char* p1, * p2;

    char tmp;
    int len1;

    //문자열 입력, 문자열의 길이 저장
    gets(str1);
    len1 = strlen(str1);

    for (p1 = str1; p1 < str1 + len1; ++p1)
    {
        for (p2 = str1; p2 < str1 + len1 - 1; ++p2)
        {
            if (*p2 > *(p2 + 1))
            {
                tmp = *p2;
                *p2 = *(p2 + 1);
                *(p2 + 1) = tmp;
            }
        }
    }

    puts(str1);
    return 0;
}