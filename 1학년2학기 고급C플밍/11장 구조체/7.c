#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

struct score
{
    int arr[10];
    int rank[10];
};

//신체등급별 인원 수 구하기
int main()
{
    struct score s;

    int ar[10];
    int sore[10] = { 0 };

    int i = 0, j = 0;

    //숫자들을 입력받는다.
    for (i = 0; i < 10; ++i)
        scanf("%d", &ar[i]);

    //구조체 배열에 정수와 순위를 저장한다.
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            if (ar[i] <= ar[j])
                sore[i]++;
        }

        s.arr[i] = ar[i];
        s.rank[i] = sore[i];
    }

    //3번째 순위의 숫자와 7번째 순위의 숫자를 출력한다.
    for (i = 0; i < 10; ++i)
    {
        if (s.rank[i] == 3)
            printf("%d ", s.arr[i]);
    }

    for (i = 0; i < 10; ++i)
    {
        if (s.rank[i] == 7)
            printf("%d ", s.arr[i]);
    }
    return 0;
}