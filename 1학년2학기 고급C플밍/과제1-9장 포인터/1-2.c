#pragma warning(disable:4996)
#include <stdio.h> 

//함수 원형 설정을 합니다.
int* MAX(int*); //최대값의 주소를 반환하는 함수입니다.

int* MIN(int*); //최솟값의 주소를 반환하는 함수입니다.

int main()
{
    int N; //줄 수에 해당하는 정수 N을 선언합니다.

    int ar[100]; //배열을 선언합니다.

    int* p1; //반복문이나 논리 연산에 사용될 포인터를 선언합니다.
    int* p2;

    int* maxarr; //함수 MAX(), MIN()에서 반환된 주소값을 할당받을 포인터를 선언합니다.
    int* minarr;

    scanf("%d", &N);    // N에 정수를 입력받습니다.

    for (p1 = ar; p1 < ar + N; ++p1) //주소를 활용해 중첩반복문을 사용할 수 있습니다.
    {
        for (p2 = ar; ; ++p2)
        {
            scanf("%d", p2);    // 입력부분

            if (*p2 == 0) break; //입력한 수가 0이면 반복문 탈출         
        }

        maxarr = MIN(ar) < MAX(ar) ? MAX(ar) : MIN(ar); //주소값이 더 큰것을 maxarr에 대입합니다.
        if (maxarr == MAX(ar)) minarr = MIN(ar); //그 외에 주소값이 작은것을 minarr에 대입합니다.

        else minarr = MAX(ar);

        if (maxarr == minarr || minarr + 1 == maxarr) printf("none"); //만약 maxarr과 minarr이 같거나 차이가 하나만 난다면 출력할 정수가 없다는 뜻이니,  none을 출력합니다.

        else for (p2 = minarr + 1; p2 < maxarr; ++p2) printf("%d ", *p2); //그 외에 출력할 숫자가 있다면 주소를 활용한 반복문을 통해 정수들을 출력합니다.

        printf("\n");
    }
    return 0;
}

//함수설정부분
/*
최대 최소 구하는 방법.......

내가 생각해보기로는

1. 오름차, 내림차 순으로 정리해서 구해본다. -> 배열의 크기를 알아야할듯

2. max, min 변수를 선언하고 조건문을 사용해서 구한다.

*/

int* MAX(int* x) //최대값의 주소를 반환하는 함수입니다.
{
    int max = -9999; //정수 max를 선언하고 -9999로 초기화합니다.
    int* p; //반복문이나 논리 연산에 사용될 포인터를 선언합니다.
    int* pmax = NULL; //최대값의 주소를 저장할 포인터를 선언합니다.

    for (p = x; ; ++p) //p와 x를 연결한 반복문입니다.
    {
        if (*p == 0) break; //p를 참조한 값이 0이라면 반복문을 탈출합니다.

        if (*p >= max) //p를 참조한 값이 max보다 크다면 아래의 문장들을 실행합니다.
        {
            max = *p; //max변수에 p를 참조한 값을 대입하고
            pmax = p; //pmax에 p의 주소값을 대입합니다.
        }
    }

    return pmax; //pmax의 값을 반환합니다.
}

int* MIN(int* x) //최솟값의 주소를 반환하는 함수입니다.
{
    int min = 9999; //정수 min를 선언하고 9999로 초기화합니다.
    int* p; //반복문이나 논리 연산에 사용될 포인터를 선언합니다.
    int* pmin = NULL; //최솟값의 주소를 저장할 포인터를 선언합니다.

    for (p = x; ; ++p) //p와 x를 연결한 반복문입니다.
    {
        if (*p == 0) break; //p를 참조한 값이 0이라면 반복문을 탈출합니다.

        if (*p <= min) //p를 참조한 값이 min보다 작다면 아래의 문장들을 실행합니다.
        {
            min = *p; //min변수에 p를 참조한 값을 대입하고
            pmin = p; //pmin에 p의 주소값을 대입합니다.       
        }
    }

    return pmin; //pmin의 값을 반환합니다.
}