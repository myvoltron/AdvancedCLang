#pragma warning(disable:4996)
#include <stdio.h> 

void strccat(char*, char*);

int main()
{
    char a[12];
    char b[6];

    char* p1;

    //입력부분
    for (p1 = a; p1 < a + 6; ++p1) scanf("%c", p1);

    getchar();

    for (p1 = b; p1 < b + 6; ++p1) scanf("%c", p1);

    strccat(a, b);

    for (p1 = a; p1 < a + 12; ++p1) printf("%c", *p1);
    return 0;
}

void strccat(char* a, char* b)
{
    char* p1;
    char* p2;

    for (p1 = a + 6, p2 = b; p1 < a + 12; ++p1, ++p2)
    {
        *p1 = *p2;
    }
}