#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char str1[100]; //입력받을 배열
    char word[10][100]; //분리된 단어들을 받을 이중배열
    char firstword[100] = ""; //사전순으로 가장 빠른 단어를 받을 배열
    char* p1; //문자형 포인터

    int len1; //입력받은 문자열의 길이
    int i, j;
    int cnt = 0; //단어의 개수 저장

    //문자열 입력, 문자열의 길이 저장
    gets(str1);
    len1 = strlen(str1);

    i = 0; //i, j를 0으로 초기화
    j = 0;

    //공백을 기준으로 해서 단어들을 word배열에 저장
    for (p1 = str1; p1 <= str1 + len1; ++p1) // -> 포인터 연결로 반복문 실행
    {

        if (*p1 != ' ') //*p1이 공백이 아니면 word배열에 *p1 대입
        {
            word[i][j++] = *p1;
        }

        else if (*p1 == ' ') //만약 공백이 온다면
        {
            word[i][j] = '\0'; //word에 '\0'을 대입해서 문자열을 완성한다.
            j = 0; //j를 0으로 초기화하고 i를 1증가시킴
            i++;
        }
    }

    cnt = i + 1; //단어의 개수

    //분리한 단어들 출력
    for (i = 0; i < cnt; ++i)
        puts(word[i]);


    strcpy(firstword, word[0]); //우선 firstword에 word배열의 첫번째 단어를 대입

    for (i = 1; i < cnt; ++i)
    {
        if (strcmp(firstword, word[i]) > 0) //만약 firstword에 있는 단어보다 word[i]에 있는 단어가 사전순으로 더 빠르다면 firstword에 word[i] 대입.
        {
            strcpy(firstword, word[i]);
        }
    }

    //마지막으로 firstword 출력
    puts(firstword);
    return 0;
}