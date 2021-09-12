#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len = 0;

int check(char*);

int main()
{
    char str[31];

    //문자열을 입력받고 문자열의 길이를 저장한다.
    scanf("%s", str);
    len = strlen(str);

    //문자열길이 출력
    printf("%d ", len);

    //check함수 호출
    printf("%d", check(str));
    return 0;
}

//회문여부를 판단하고 회문일 경우 1, 아니면 0을 반환한다.
int check(char* str)
{
    int i;
    int cnt = 0;

    for (i = 0; i < len; ++i)
    {
        if (*(str + i) != *(str + len - 1 - i))
            cnt++;
    }

    if (cnt > 0)
        return 0;

    return 1;
}