#pragma warning(disable:4996)
#include <stdio.h> 
int main()
{
    int ar[3];
    int* p;

    for (p = ar; p < ar + 3; ++p)
    {
        scanf("%d", p);
    }

    p = ar;

    if (*p >= *(p + 1))
    {
        if (*(p + 2) >= *p) printf("%d", *p);

        else
        {
            if (*(p + 2) >= *(p + 1)) printf("%d", *(p + 2));
            else printf("%d", *(p + 1));
        }
    }

    else if (*p <= *(p + 1))
    {
        if (*(p + 2) >= *(p + 1)) printf("%d", *(p + 1));

        else
        {
            if (*(p + 2) >= *p) printf("%d", *(p + 2));
            else printf("%d", *p);
        }
    }

    else if (*p >= *(p + 1))
    {
        if (*(p + 2) >= *p) printf("%d", *p);

        else
        {
            if (*(p + 2) >= *(p + 1)) printf("%d", *(p + 2));
            else printf("%d", *(p + 1));
        }
    }

    return 0;
}
