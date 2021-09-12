#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct result
{
    int max_sc;
    int min_sc;
    char c_pass;
    int dissc;
    int st_dissc;
};

char passorfail(struct result* st)
{
    st->dissc = st->max_sc - st->min_sc;

    if (st->st_dissc > st->dissc)
        return 'P';

    return 'F';
}

int main()
{
    struct result st1;

    scanf("%d %d %d", &st1.max_sc, &st1.min_sc, &st1.st_dissc);

    st1.c_pass = passorfail(&st1);

    printf("%d %c", st1.dissc, st1.c_pass);
    return 0;
}