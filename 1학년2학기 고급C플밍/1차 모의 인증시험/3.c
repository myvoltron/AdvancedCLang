#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StringAdd(char arr[], char ch, int index);
int Convertor(char x);

int main()
{
	char str1[100];
	char* p1;
	int len1 = 0;
	int n1 = 0, n2 = 0;
	int index = 0;

	gets(str1);
	len1 = strlen(str1);

	for (p1 = str1; p1 < str1 + len1 - 1; ++p1)
	{
		n1 = Convertor(*p1);
		n2 = Convertor(*(p1 + 1));

		if (n1 % 2 == 0 && n2 % 2 == 0)
		{
			StringAdd(str1, '*', index + 1);
			p1++;
			len1++;
			index++;
		}

		else if (n1 % 2 != 0 && n2 % 2 != 0)
		{
			StringAdd(str1, '+', index + 1);
			p1++;
			len1++;
			index++;
		}

		index++;
	}

	puts(str1);
	return 0;
}

void StringAdd(char arr[], char ch, int index)
{
	char* p1;
	int len1 = strlen(arr);

	for (p1 = arr + len1; p1 > arr + index; --p1)
		*p1 = *(p1 - 1);

	*(arr + index) = ch;
	*(arr + len1 + 1) = '\0';
}

int Convertor(char x)
{
	return x - '0';
}