#pragma warning(disable:4996)
#include <stdio.h> 

int main()
{
    char arr[20];
    int i;

    scanf("%s", arr);

    for (i = 0; arr[i] != NULL; ++i)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z') printf("%c", arr[i]);
    }


    return 0;
}