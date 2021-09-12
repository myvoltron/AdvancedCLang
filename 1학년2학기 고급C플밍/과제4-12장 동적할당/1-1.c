#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st
{
	char* str;
	int cnt;
};

int main()
{
	int N = 0;
	int cst_cnt = 0; //자음의 개수
	int len = 0;
	int i = 0;
	struct st* p_st = NULL;
	struct st* p1, * p2;
	struct st save;
	char temp[101];
	char* pc1;

	//입력받을 개수
	scanf("%d", &N);
	getchar();

	//구조체 동적할당
	p_st = (struct st*)malloc(N * sizeof(struct st));

	//입력받고 자음의 개수 세는 부분
	for (p1 = p_st; p1 < p_st + N; ++p1)
	{
		p1->cnt = 0; //우선 cnt의 값을 0으로 초기화

		gets(temp);
		len = strlen(temp);

		//자음일때 cnt개수를 증가
		for (pc1 = temp; pc1 < temp + len; ++pc1)
		{
			if (*pc1 != 'a' && *pc1 != 'o' && *pc1 != 'i' && *pc1 != 'e' && *pc1 != 'u'
				&& *pc1 != 'A' && *pc1 != 'O' && *pc1 != 'I' && *pc1 != 'E' && *pc1 != 'U')
				p1->cnt += 1;
		}

		p1->str = (char*)malloc((len + 1) * sizeof(char));
		strcpy(p1->str, temp);
	}

	//정렬
	for (p1 = p_st; p1 < p_st + N; ++p1)
	{
		for (p2 = p_st; p2 < p_st + N - 1; ++p2)
		{
			if (p2->cnt < (p2 + 1)->cnt)
			{
				save = *p2;
				*p2 = *(p2 + 1);
				*(p2 + 1) = save;
			}
		}
	}

	//출력
	for (p1 = p_st; p1 < p_st + N; ++p1)
		printf("%s\n", p1->str);

	//할당해제
	for (p1 = p_st; p1 < p_st + N; ++p1)
		free(p1->str);
	free(p_st);
	return 0;
}