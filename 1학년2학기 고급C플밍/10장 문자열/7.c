#pragma warning(disable:4996)
#include <stdio.h>

void add_arr(int, int, char*);

int main()
{
    int N = 0;
    int times = 1;
    int i = 0, j = 0;
    int save = 0; //N값 저장용
    int num = 0; // = N / times % 10
    int cnt1 = 0, cnt2 = 0; //cnt1은 입력받은 정수의 자리수 계산용 || cnt2는 문자열길이 계산용
    char arr[1000] = "";

    scanf("%d", &N);

    save = N;

    //자리수 계산
    while (save > 0)
    {
        save /= 10;
        cnt1++;
    }

    cnt1--;

    //자리수 cnt1을 이용해 ~자리수의 수를 make
    for (i = 0; i < cnt1; ++i)
        times *= 10;

    //part to make arr
    while (times > 0)
    {
        num = N / times % 10;
        if (num != 0)
        {
            add_arr(num, times, arr);
        }

        times /= 10;
    }

    //출력
    printf("%s", arr);
    return 0;
}

void add_arr(int num, int times, char* arr)
{
    char one[10] = "one ";
    char two[10] = "two ";
    char three[10] = "three ";
    char four[10] = "four ";
    char five[10] = "five ";
    char six[10] = "six ";
    char seven[10] = "seven ";
    char eight[10] = "eight ";
    char nine[10] = "nine ";

    char ten[10] = "TEN ";
    char hun[10] = "HUN ";
    char tho[10] = "THO ";

    char* p1 = arr;
    char* p2 = one;
    char* p3 = ten;

    int cnt = 0;

    if (num == 2) p2 = two;
    else if (num == 3) p2 = three;
    else if (num == 4) p2 = four;
    else if (num == 5) p2 = five;
    else if (num == 6) p2 = six;
    else if (num == 7) p2 = seven;
    else if (num == 8) p2 = eight;
    else if (num == 9) p2 = nine;

    if (times == 1000) p3 = tho;
    else if (times == 100) p3 = hun;

    while (1)
    {
        if (*p1++ == NULL) break;
        cnt++;
    }

    p1 = arr;

    while (1)
    {
        if (*p2 == NULL) break;

        *(p1 + cnt++) = *(p2++);
    }

    if (times >= 10)
    {
        while (1)
        {
            if (*p3 == NULL) break;

            *(p1 + cnt++) = *(p3++);
        }
    }

    *(p1 + cnt) = NULL;

}