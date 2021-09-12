#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
	char name[8];
	int score1, score2, score3;
	double avg;
};

int main()
{
	int N = 0;
	int i = 0;
	struct student* pst = NULL;

	scanf("%d", &N);
	pst = (struct student*)malloc(N * sizeof(struct student));

	for (i = 0; i < N; ++i)
	{
		scanf("%s %d %d %d", pst[i].name, &pst[i].score1, &pst[i].score2, &pst[i].score3);
		pst[i].avg = pst[i].score1 + pst[i].score2 + pst[i].score3;
		pst[i].avg /= 3.0;
	}

	for (i = 0; i < N; ++i)
	{
		printf("%s %.1lf", pst[i].name, pst[i].avg);
		if (pst[i].score1 >= 90 || pst[i].score2 >= 90 || pst[i].score3 >= 90)
			printf(" GREAT");
		if (pst[i].score1 < 70 || pst[i].score2 < 70 || pst[i].score3 < 70)
			printf(" BAD");

		printf("\n");
	}

	free(pst);
	return 0;
}