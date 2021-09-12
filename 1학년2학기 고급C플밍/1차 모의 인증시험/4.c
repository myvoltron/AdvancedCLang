#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	char name[10];
	char book[5][20];
	int score[5];
	int cnt, pcnt;
};

int main()
{
	struct student st[100];
	struct student* p1, * p2;
	char tmp[10];
	int N = 0;
	int i = 0;

	scanf("%d", &N);

	for (p1 = st; p1 < st + N; ++p1)
	{
		p1->cnt = 0;
		p1->pcnt = 0;

		scanf("%s", p1->name);

		for (i = 0; i < 5; ++i)
		{
			scanf("%s", p1->book[i]);
			if (!strcmp(p1->book[i], "0"))
				break;

			p1->cnt++;

			scanf("%d", &p1->score[i]);
			if (p1->score[i] >= 50)
				p1->pcnt++;
		}

		if (i == 5)
			scanf("%s", tmp);

		printf("%s %d%%\n", p1->name, p1->pcnt * 20);
	}
	return 0;
}