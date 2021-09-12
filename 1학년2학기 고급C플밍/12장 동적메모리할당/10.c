#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int* num1 = NULL;
	int* num2 = NULL;
	int i = 0, j = 0;
	int len = 0;
	int cnt = 0;
	int checker = 0;

	num1 = (int*)malloc(5 * sizeof(int));
	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &num1[i]);
		len++;

		if (num1[i] == -1)
		{
			checker = 1;
			break;
		}
	}

	if (checker != 1)
	{
		for (i = 1; i <= 5; ++i)
		{
			num2 = (int*)malloc((5 + 3 * i) * sizeof(int));
			for (j = 0; j < len; ++j)
				num2[j] = num1[j];

			cnt = 0;
			for (j = len; j < len + 3; ++j)
			{
				scanf("%d", &num2[j]);
				cnt++;

				if (num2[j] == -1)
				{
					checker = 1;
					break;
				}
			}
			len += cnt;

			num1 = (int*)malloc((5 + 3 * i) * sizeof(int));
			for (j = 0; j < len; ++j)
				num1[j] = num2[j];

			if (checker == 1)
				break;
		}
	}


	for (i = 0; i < len; ++i)
		printf(" %d", num1[i]);

	free(num1);
	free(num2);
	return 0;
}