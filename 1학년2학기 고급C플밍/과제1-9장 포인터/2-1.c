#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int arr[6];
	int* p1, * p2, * p3;
	int cnt1 = 0, cnt2 = 0;

	for (p1 = arr; p1 < arr + 6; ++p1)
		scanf("%d", p1);

	for (p1 = arr; p1 < arr + 6; ++p1)
	{
		cnt1 = 0;

		for (p2 = arr; p2 < arr + 6; ++p2)
		{
			if (p2 < p1 && *p1 == *p2)
				break;

			if (*p1 == *p2)
				cnt1++;
		}

		if (cnt1 >= 2)
		{
			printf("%d %d\n", *p1, cnt1);
			cnt2++;
		}
	}

	if (cnt2 == 0)
		printf("0");
	return 0;
}