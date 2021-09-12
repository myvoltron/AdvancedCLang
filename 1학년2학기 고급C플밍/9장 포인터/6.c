#pragma warning(disable:4996)
#include <stdio.h> 
int main()
{
    char ch[10];
    char* pch;

    char sch[10];
    char* psch;

    int cnt = 0;
    int maxcnt = -1;

    char maxs;

    //입력부분
    for (pch = ch, psch = sch; pch < ch + 10; ++pch, ++psch)
    {
        scanf("%c", pch);
        *psch = *pch;
    }

    //계산부분
    for (psch = sch; psch < sch + 10; ++psch)
    {
        cnt = 0;
        for (pch = ch; pch < ch + 10; ++pch)
        {
            if (*psch == *pch)
            {
                cnt++;
            }
        }

        if (cnt > maxcnt)
        {
            maxcnt = cnt;
            maxs = *psch;
        }
    }

    printf("%c %d", maxs, maxcnt);

    return 0;
}