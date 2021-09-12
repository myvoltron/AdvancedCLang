#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customer
{
    char id[5];
    char* name;
    char* phone;
} CUS;

int main()
{
    int N = 0;
    int i = 0, j = 0;
    int len = 0;
    int checker = 0;
    char temp[101];
    char find[101];
    char* pc1, * pc2;
    CUS* p_guest = NULL;

    scanf("%d", &N);
    p_guest = (CUS*)malloc(N * sizeof(CUS));

    for (i = 0; i < N; ++i)
    {
        scanf("%s", temp);
        len = strlen(temp);
        p_guest[i].name = (char*)malloc((len + 1) * sizeof(char));
        strcpy(p_guest[i].name, temp);

        scanf("%s", temp);
        len = strlen(temp);
        p_guest[i].phone = (char*)malloc((len + 1) * sizeof(char));
        strcpy(p_guest[i].phone, temp);

        for (pc1 = p_guest[i].phone + len - 4, pc2 = p_guest[i].id; pc1 < p_guest[i].phone + len; ++pc1, ++pc2)
            *pc2 = *pc1;
        *pc2 = '\0';
    }

    scanf("%s", find);

    for (i = 0; i < N; ++i)
    {
        if (!strcmp(find, p_guest[i].name) || !strcmp(find, p_guest[i].id))
        {
            printf("%s %s %d\n", p_guest[i].name, p_guest[i].phone, i + 1);
            checker++;
        }
    }

    if (checker == 0)
        printf("None");

    for (i = 0; i < N; ++i)
    {
        free(p_guest[i].name);
        free(p_guest[i].phone);
    }
    free(p_guest);
    return 0;
}