#pragma warning(disable:4996)
#include <stdio.h> 
int main()
{
    int x, y, z, t;
    int* px, * py, * pz, * tmp;

    scanf("%d %d %d", &x, &y, &z);

    px = &x;
    py = &y;
    pz = &z;
    tmp = &t;

    *tmp = *pz;
    *pz = *py;
    *py = *px;
    *px = *tmp;

    printf("%d %d %d", *px, *py, *pz);

    return 0;
}