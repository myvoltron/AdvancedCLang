#pragma warning(disable : 4996) 
#include <stdlib.h>
#include <stdio.h>

#define ABS(a) (a < 0 ? (-1 * a) : a)
#define MAX(a, b) ((ABS(a)) < (ABS(b)) ? b : a)

int main()
{
    int num[6] = { 0 };
    int i = 0;
    int max = 0;

    for (i = 0; i < 6; ++i)
        scanf("%d", &num[i]);

    for (i = 0; i < 6; ++i)
        max = MAX(num[i], max);

    printf("%d %d", max, ABS(max));
    return 0;
}


