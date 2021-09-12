#pragma warning(disable:4996)
#include <stdio.h> 

int main()
{
    char arr[9];
    int N;
    int i = 0;

    scanf("%d", &N);

    while (N > 0)
    {
        arr[i] = N % 10 + '0';
        N /= 10;
        i++;
    }

    arr[i] = NULL;
    printf("%s", arr);
    return 0;
}