#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[81];
    char str2[11];

    char* p1;
    char* p2;

    int len1, len2;
    int i = 0;

    int cnt1 = 0, cnt2 = 0;

    gets(str1);
    gets(str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    printf("%d ", len1);

    for (p1 = str1; p1 < str1 + len1 - len2 + 1; ++p1)
    {
        for (p2 = str2; p2 < str2 + len2; ++p2)
        {
            if (*p2 == *(p1 + i))
                cnt1++;
            i++;
        }

        if (cnt1 == len2)
            cnt2++;

        cnt1 = 0;
        i = 0;
    }

    if (cnt2 > 0)
        printf("1");

    else
        printf("0");
    return 0;
}