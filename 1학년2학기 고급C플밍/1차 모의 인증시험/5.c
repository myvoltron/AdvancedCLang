#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char name[51];
	char stnum[8];
};

int main()
{
	struct student st[100];
	struct student* p1, * p2;
	struct student tmp;

	int N = 0;

	scanf("%d", &N);
	getchar();

	for (p1 = st; p1 < st + N; ++p1)
	{
		gets(p1->name);
		scanf("%s", p1->stnum);
		getchar();
	}

	for (p1 = st; p1 < st + N; ++p1)
	{
		for (p2 = st; p2 < st + N - 1; ++p2)
		{
			if (strcmp(p2->name, (p2 + 1)->name) > 0)
			{
				tmp = *p2;
				*p2 = *(p2 + 1);
				*(p2 + 1) = tmp;
			}
		}
	}

	for (p1 = st; p1 < st + N; ++p1)
	{
		for (p2 = st; p2 < st + N - 1; ++p2)
		{
			if (strcmp(p2->stnum, (p2 + 1)->stnum) > 0 && !strcmp(p2->name, (p2 + 1)->name))
			{
				tmp = *p2;
				*p2 = *(p2 + 1);
				*(p2 + 1) = tmp;
			}
		}
	}

	for (p1 = st; p1 < st + N; ++p1)
		printf("%s %s\n", p1->name, p1->stnum);
	return 0;
}