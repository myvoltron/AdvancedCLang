#pragma warning(disable:4996)
#include <stdio.h> 

void strcopy(char* p1, char* p2)
{
    int i;

    for (i = 0; i < 6; ++i)
    {
        *(p1 + i) = *(p2 + i);
    }
}

int main()
{
    char a[6], b[6];
    char* p;

    for (p = b; p < b + 6; ++p)
    {
        scanf("%c", p);
    }

    strcopy(a, b);

    for (p = a; p < a + 6; ++p)
    {
        printf("%c", *p);
    }

    return 0;
}