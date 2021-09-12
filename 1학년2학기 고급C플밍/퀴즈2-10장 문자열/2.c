#pragma warning(disable:4996)
#include <stdio.h>

void strcat(char*, char*);
int strcmp(char*, char*);
int strlen(char*);
void strcpy(char*, char*);

int main()
{
    int N = 0;
    char str1[101];
    char mtmp[101];
    char* p1, * p2;

    int len1 = 0;
    int i = 0, j = 0;
    int cnt1 = 0; //모음의 개수
    int max = -9999;
    scanf("%d", &N);

    gets(str1);

    len1 = strlen(str1);

    for (i = 0; i < N; ++i)
    {
        cnt1 = 0;

        gets(str1);

        len1 = strlen(str1);

        for (p1 = str1; p1 < str1 + len1; ++p1)
        {
            if (*p1 == 'a' || *p1 == 'o' || *p1 == 'i' || *p1 == 'u' || *p1 == 'e')
                cnt1++;
        }

        if (cnt1 > max)
        {
            max = cnt1;
            strcpy(mtmp, str1);
        }
    }

    puts(mtmp);
    return 0;
}

void strcat(char* str1, char* str2)
{
    char* p1, * p2;

    int len1, len2;

    len1 = strlen(str1);
    len2 = strlen(str2);

    for (p1 = str1 + len1, p2 = str2; p2 <= str2 + len2; ++p1, ++p2)
        *p1 = *p2;
}

int strcmp(char* str1, char* str2)
{
    char* p1, * p2;

    for (p1 = str1, p2 = str2; *p1; ++p1, ++p2)
    {
        if (*p1 > *p2)
            return 1;
        else if (*p1 < *p2)
            return -1;
        else if (*p1 == *p2)
            continue;
    }

    return 0;
}

int strlen(char* str)
{
    char* p;
    int len = 0;

    for (p = str; *p; ++p)
        len++;

    return len;
}

void strcpy(char* str1, char* str2)
{
    char* p1, * p2;

    int len2 = 0;

    len2 = strlen(str2);

    for (p1 = str1, p2 = str2; p2 <= str2 + len2; ++p1, ++p2)
        *p1 = *p2;
}