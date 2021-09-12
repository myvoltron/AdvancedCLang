#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[101];
    char str2[101];

    char* p1;
    char* p2;

    int len1, len2;
    int i = 0, j = 0;

    int cnt1 = 0;
    int cnt2 = 0;

    gets(str1);

    gets(str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 > len2)
    {
        for (p1 = str1; p1 < str1 + len1 - len2 + 1; ++p1)
        {
            for (p2 = str2; p2 < str2 + len2; ++p2)
            {
                if (*p2 == *(p1 + i))
                    cnt1++;
                i++;
            }
            i = 0;

            if (cnt1 == len2)
            {
                cnt2++;
                p1 += len2 - 1;
            }
            cnt1 = 0;
        }
    }

    else if (len2 > len1)
    {
        for (p2 = str2; p2 < str2 + len2 - len1 + 1; ++p2)
        {
            for (p1 = str1; p1 < str1 + len1; ++p1)
            {
                if (*p1 == *(p2 + i))
                    cnt1++;
                i++;
            }
            i = 0;

            if (cnt1 == len1)
            {
                cnt2++;
                p2 += len1 - 1;
            }
            cnt1 = 0;
        }
    }

    printf("%d", cnt2);
    return 0;
}