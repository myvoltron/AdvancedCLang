#pragma warning(disable:4996)
#include <stdio.h> 

int main()
{
    char arr[100];
    char tmp;
    int i, j;
    int cnt = 0;

    scanf("%s", arr);

    i = 0;

    while (1)
    {
        if (arr[i++] == NULL) break;
        cnt++;
    }

    for (i = 0; i < cnt; ++i)
    {
        printf("%s\n", arr);

        tmp = arr[0];

        for (j = 0; j < cnt - 1; ++j)
        {
            arr[j] = arr[j + 1];
        }

        arr[cnt - 1] = tmp;
    }

    return 0;
}