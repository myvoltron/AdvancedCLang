#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int N = 0;
	int len1 = 0, len2 = 0;
	int cnt1 = 0, cnt2 = 0;
	char* str1 = NULL;
	char str2[11];
	char* pc1, * pc2, * pc3;

	scanf("%d", &N);
	getchar();
	str1 = (char*)malloc((N + 1) * sizeof(char));

	gets(str1);
	gets(str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (pc1 = str1; pc1 < str1 + len1; ++pc1)
	{
		cnt1 = 0;
		for (pc2 = str2, pc3 = pc1; pc2 < str2 + len2; ++pc2, ++pc3)
		{
			if (*pc3 == *pc2)
				cnt1++;
		}

		if (cnt1 == len2)
		{
			cnt2++;
			pc1 += len2 - 1;
		}
	}

	printf("%d", cnt2);

	free(str1);
	return 0;
}
