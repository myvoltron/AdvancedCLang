#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char name[10];
	char stnum[11];
	char ch;
};

int main()
{
	struct student st[5];
	struct student* p1, * p2;
	struct student* save = NULL;
	char find_name[10];
	char* pc1, * pc2;
	int cnt1 = 0, cnt2 = 0;

	for (p1 = st; p1 < st + 5; ++p1)
	{
		scanf("%s", p1->name);
		scanf("%s", p1->stnum);
		getchar();
		scanf("%c", &p1->ch);
	}

	scanf("%s", find_name);

	for (p1 = st; p1 < st + 5; ++p1)
	{
		if (!strcmp(p1->name, find_name))
			save = p1;

	}

	for (p1 = st; p1 < st + 5; ++p1)
	{
		if (save->ch == p1->ch && save != p1)
		{
			cnt1 = 0;

			for (pc1 = p1->stnum, pc2 = save->stnum; pc1 < p1->stnum + 4; ++pc1, ++pc2)
			{
				if (*pc1 == *pc2)
					cnt1++;
			}

			if (cnt1 == 4)
			{
				printf(" %s\n", p1->name);
				cnt2++;
			}
		}
	}

	if (cnt2 == 0)
		printf("0");
	return 0;
}