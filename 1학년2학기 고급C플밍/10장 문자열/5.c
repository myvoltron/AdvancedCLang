#pragma warning(disable:4996)
#include <stdio.h> 

int main()
{
    char str1[100];
    char str2[20];

    int N; // 삽입위치
    int cnt1 = 0, cnt2 = 0; //str1, str2 길이 구하기
    int i = 0, j = 0;

    scanf("%s", str1);
    getchar();
    scanf("%s", str2);

    scanf("%d", &N); //삽입위치 입력

    //str1 과 str2의 길이를 구합니다.
    while (1)
    {
        if (str1[i++] == '\0') break;
        cnt1++;
    }

    i = 0;

    while (1)
    {
        if (str2[i++] == '\0') break;
        cnt2++;
    }

    //str2를 str1에 삽입하는 과정을 진행합니다.
    for (i = cnt1 + cnt2 - 1; i >= cnt2 + N; --i)
    {
        str1[i] = str1[i - cnt2];
    }

    //str1의 마지막부분에 NULL문자를 삽입해 문자열을 완성합니다.
    str1[cnt1 + cnt2] = '\0';

    for (i = N, j = 0; i < N + cnt2; ++i, ++j)
    {
        str1[i] = str2[j];
    }

    //출력
    printf("%s", str1);
    return 0;
}