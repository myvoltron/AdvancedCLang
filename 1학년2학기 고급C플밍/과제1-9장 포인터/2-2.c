#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int correct(int* arr);
int newnum(int* arr);

int main()
{
	int lotto[6];
	int* p1;

	for (p1 = lotto; p1 < lotto + 6; ++p1)
		scanf("%d", p1);

	printf("%d\n", correct(lotto));
	for (p1 = lotto; p1 < lotto + 6; ++p1)
		printf("%d ", *p1);


	return 0;
}

int correct(int* lotto)
{
	int* p1, * p2;

	int cnt1 = 0, cnt2 = 0;

	for (p1 = lotto; p1 < lotto + 6; ++p1)
	{
		cnt1 = 0;

		for (p2 = lotto; p2 < lotto + 6; ++p2)
		{
			if (p2 < p1 && *p2 == *p1)
				break;

			if (*p2 == *p1)
				cnt1++;
		}

		if (cnt1 >= 2)
		{
			*p1 = newnum(lotto);
			cnt2++;
		}
	}

	if (cnt2 >= 1)
		return 1;
	return 0;
}
int newnum(int* arr)
{
	int* p1, * p2;
	int k = 1;

	for (p1 = arr; p1 < arr + 6; ++p1)
	{
		for (p2 = arr; p2 < arr + 6; ++p2)
		{
			if (*p2 == k)
				k++;
		}
	}

	return k;
}