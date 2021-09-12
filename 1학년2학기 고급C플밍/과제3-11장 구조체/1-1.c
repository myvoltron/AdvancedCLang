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
	char find_name[10];
	char tmp;

	for (p1 = st; p1 < st + 5; ++p1)
	{
		scanf("%s", p1->name);
		scanf("%s", p1->stnum);
		getchar();
		scanf("%c%c", &p1->ch, &tmp);
	}

	scanf("%s", find_name);

	for (p1 = st; p1 < st + 5; ++p1)
	{
		if (strcmp(p1->name, find_name) == 0)
			printf(" %s %c", p1->stnum, p1->ch);
	}

	return 0;
}