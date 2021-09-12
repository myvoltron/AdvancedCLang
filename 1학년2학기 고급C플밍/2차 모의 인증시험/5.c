#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_row(int** p, int M, int N);
int check_col(int** p, int M, int N);

int main()
{
    int M = 0, N = 0;
    int x = 0, y = 0, z = 0;
    int i = 0, j = 0, k = 0;
    int** p_num = NULL;
    int row = 0, col = 0;

    scanf("%d %d", &M, &N);
    p_num = (int**)malloc(M * sizeof(int*));
    for (i = 0; i < M; ++i)
        p_num[i] = (int*)malloc(N * sizeof(int));

    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
            p_num[i][j] = 0;
    }

    while (1)
    {
        scanf("%d %d %d", &x, &y, &z);
        if (x == 0 && y == 0 && z == 0)
            break;

        p_num[x][y] = z;
    }

    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
            printf("%d ", p_num[i][j]);
        printf("\n");
    }

    row = check_row(p_num, M, N);
    col = check_col(p_num, M, N);

    printf("%d", row < col ? col : row);
    return 0;
}

int check_row(int** p, int M, int N)
{
    int i = 0, j = 0, k = 0;
    int cnt = 0;
    int max_cnt = 0;

    for (i = 0; i < M; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            if (p[i][j] == 0)
            {
                cnt = 0;
                for (k = j; k < N; ++k)
                {
                    if (p[i][k] != 0)
                        break;

                    cnt++;
                }

                if (cnt > max_cnt)
                    max_cnt = cnt;
            }
        }
    }

    return max_cnt;
}

int check_col(int** p, int M, int N)
{
    int i = 0, j = 0, k = 0;
    int cnt = 0;
    int max_cnt = 0;

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < M; ++j)
        {
            if (p[j][i] == 0)
            {
                cnt = 0;
                for (k = j; k < M; ++k)
                {
                    if (p[k][i] != 0)
                        break;

                    cnt++;
                }

                if (cnt > max_cnt)
                    max_cnt = cnt;
            }
        }
    }

    return max_cnt;
}