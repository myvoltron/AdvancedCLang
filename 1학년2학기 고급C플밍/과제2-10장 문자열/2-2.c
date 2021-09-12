#pragma warning(disable : 4996) 
#include<stdio.h>
#include <string.h>

int main()
{
    char x[1000], arr[10][100];
    int i = 0, j = 0, t = 0;

    gets(x);

    while (1)
    {
        if (x[j] == ' ')
        {
            arr[i][t] = '\0';
            puts(arr[i]);
            t = 0;
            i++;
        }
        else if (x[j] == '\0')
        {
            arr[i][t] = '\0';
            puts(arr[i]);
            break;
        }
        else
        {
            arr[i][t] = x[j];
            t++;
        }
        j++;
    }

    int a, b;
    i += 1;
    for (a = 0; a < i; a++)
    {
        for (b = 0; b < i - 1; b++)
        {
            if (arr[b][0] > arr[b + 1][0])
            {
                strcpy(x, arr[b]);
                strcpy(arr[b], arr[b + 1]);
                strcpy(arr[b + 1], x);
            }
        }
    }

    for (int q = 0; q < i; ++q)
        puts(arr[q]);

    return 0;
}