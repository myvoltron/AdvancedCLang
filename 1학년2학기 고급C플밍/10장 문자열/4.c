#pragma warning(disable:4996)
#include <stdio.h> 

int main()
{
    char a[100];
    char b[100];
    int cnt = 0, cnt1 = 0;
    int i = 0;
    int result;

    scanf("%s", a);
    getchar();
    scanf("%s", b);

    while (1)
    {
        if (a[i++] == NULL) break;
        cnt++;
    }

    for (i = 0; i < cnt; ++i)
    {
        if (a[i] == b[i]) cnt1++;
    }

    if (cnt1 == cnt) result = 1;
    else result = 0;

    printf("%d %d", cnt, result);

    return 0;
}