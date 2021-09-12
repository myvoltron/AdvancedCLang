#pragma warning(disable:4996)
#include <stdio.h> 
int main()
{
    char ch[20];
    char* pch = &ch;

    int i, cnt = 0;

    for (i = 0; i < 20; ++i)
    {
        scanf("%c", (pch + i));
    }

    i = 0;

    while (1)
    {
        if (*(pch + i) == '#') break;
        i++;
        cnt++;
    }

    for (i = 0; i < cnt; ++i)
    {
        printf("%c", *(pch + cnt - i - 1));
    }

    return 0;
}