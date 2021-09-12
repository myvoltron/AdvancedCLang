#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int N = 0;
    int len = 0;
    int len1 = 0, len2 = 0;
    int i = 0, j = 0;
    char temp[101];
    char** str = NULL;
    char* swap;

    scanf("%d", &N);
    str = (char**)malloc(N * sizeof(char*));

    for (i = 0; i < N; ++i)
    {
        scanf("%s", temp);
        len = strlen(temp);
        str[i] = (char*)malloc((len + 1) * sizeof(char));
        strcpy(str[i], temp);
    }

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N - 1; ++j)
        {
            len1 = strlen(str[j]);
            len2 = strlen(str[j + 1]);

            if (len1 > len2)
            {
                swap = str[j];
                str[j] = str[j + 1];
                str[j + 1] = swap;
            }
        }
    }

    for (i = 0; i < N; ++i)
        printf("%s\n", str[i]);

    for (i = 0; i < N; ++i)
        free(str[i]);
    free(str);
    return 0;
}