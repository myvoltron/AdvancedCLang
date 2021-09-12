#pragma warning(disable:4996)
#include <stdio.h> 
int main()
{
    int arr[5];
    int rank[5] = { 1, 1, 1, 1, 1 };
    int tmps[5];
    int* par;
    int* prank;
    int* ptmps;


    //입력부분
    for (par = arr, ptmps = tmps; par < arr + 5; ++par, ++ptmps)
    {
        scanf("%d", par);
        *ptmps = *par;
    }

    //내림차순 정렬 부분
    for (ptmps = tmps, prank = rank; ptmps < tmps + 5; ++ptmps, ++prank)
    {
        for (par = arr; par < arr + 5; ++par)
        {
            if (*ptmps < *par)
            {
                *prank += 1;
            }
        }
    }

    //마지막 출력 부분
    for (prank = rank, par = arr; prank < rank + 5; ++prank, ++par)
    {
        printf("%d=r%d ", *par, *prank);
    }

    return 0;
}