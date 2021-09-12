#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct vector
{
    int x1;
    int y1;
    int z1;
};

int main()
{
    struct vector v1;
    struct vector v2;
    struct vector v3;

    scanf("%d %d %d", &v1.x1, &v1.y1, &v1.z1);
    scanf("%d %d %d", &v2.x1, &v2.y1, &v2.z1);

    v3.x1 = v1.x1 * v2.x1;
    v3.y1 = v1.y1 * v2.y1;
    v3.z1 = v1.z1 * v2.z1;

    printf("%d %d %d\n", v3.x1, v3.y1, v3.z1);
    printf("%d", v3.x1 + v3.y1 + v3.z1);
    return 0;
}