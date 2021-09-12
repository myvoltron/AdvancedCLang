#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ü tel�Դϴ�. 
struct tel
{
	char* name; //�̸�
	char* tel_no; //��ȭ��ȣ
	char* birth; //���� 
};
typedef struct tel TEL;
int max_num = 0; //

//�Լ��������� 
int insert(struct tel**, int); //�Է�
void print_all(struct tel**, int); //���
int delete_tel(struct tel**, int); //����
void find_by_birth(struct tel**, int); //�����λ�� ���� 


int main()
{
	TEL** tel_list; //�ִ� 100�� ���� 
	int count = 0; //���� ����ó ���� 
	int n = 0; //��� �Է� 

	printf("Max_num:");
	scanf("%d", &max_num); //�ִ� �Է��� �� �ִ� ȸ���� ������ �����մϴ�. 

	tel_list = (TEL**)malloc(max_num * sizeof(TEL*)); //max_num�� Ȱ���ؼ� tel_list�� �����Ҵ��Ѵ�.

	while (1) //���ѹݺ������� 5�� �ԷµǱ� ������ ����ؼ� �۵��ϰ� �մϴ�. 
	{
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");

		scanf("%d", &n); //��ɾ �Է��մϴ�. 

		switch (n)
		{
		case 1:
			count = insert(tel_list, count); //�Է��Լ��� ���Եǰ� �� ����� count������ �����մϴ�. 
			break;
		case 2:
			print_all(tel_list, count); //����Լ�����
			break;

		case 3:
			count = delete_tel(tel_list, count); //�����Լ��� ���Եǰ� �� ����� ���� count������ �����մϴ�. 
			break;
		case 4:
			find_by_birth(tel_list, count); //������ ����� ã�� �Լ����� 
			break;
		case 5:
			//�Ҵ����� 
			for (int i = 0; i < count; ++i)
			{
				free(tel_list[i][0].name);
				free(tel_list[i][0].tel_no);
				free(tel_list[i][0].birth);
				free(tel_list[i]);
			}
			free(tel_list);
			return 0; //���α׷� ���� 
		}
	}

	return 0;
}

//�Է��Լ��Դϴ�. 
int insert(struct tel** tel_list, int count)
{
	char temp[101];
	int checker = 0;
	int i = 0, j = 0;
	int index_i = count;

	//���� max_num ��ŭ�� ������ �� ����Ǿ��ٸ� OVERFLOW�� ����ϰ� �Լ��� �����մϴ�. 
	if (count >= max_num)
	{
		printf("OVERFLOW\n");
		return count;
	}

	printf("Name:"); // ���� ...
	scanf("%s", temp); //�켱 �̸��� �޴´�. 

	//�̸��� ���������� ���ؼ� ������ �ε����� ã�´�. 
	for (i = 0; i < count; ++i)
	{
		if (strcmp(tel_list[i][0].name, temp) > 0)
		{
			index_i = i; //�ּҸ� �����մϴ�. 
			checker = 1; //�׸��� �ڷ��̵��� �ʿ��ϹǷ� checker�� 1���� ����ϴ�. 
			break;
		}
	}

	tel_list[count] = (TEL*)malloc(1 * sizeof(TEL)); //�����Ҵ��� �մϴ�. 
	//�׸��� �̸��� �߰��ϱ� ���ؼ� �ڷ��̵��� �ʿ��ϴٰ� �ǴܵǹǷ� ������ �ڷ���� �̵���ŵ�ϴ�. 
	if (checker == 1)
	{
		//�ڷ�� �̵�
		for (i = count; i > index_i; --i)
			tel_list[i][0] = tel_list[i - 1][0];
	}

	//�׸��� �̸����� �����մϴ�. 
	tel_list[index_i][0].name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy(tel_list[index_i][0].name, temp);

	//�޴��� �ѹ��� ������ ������ �޽��ϴ�. 
	printf("Phone_number:"); // ���� ...
	scanf("%s", temp);
	tel_list[index_i][0].tel_no = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy(tel_list[index_i][0].tel_no, temp);

	printf("Birth:"); //����
	scanf("%s", temp);
	tel_list[index_i][0].birth = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy(tel_list[index_i][0].birth, temp);

	printf("<<%d>> \n", count + 1); //�׸��� �������� �󸶳� �ִ��� ����մϴ�. 
	return count + 1; //������ �߰��Ǿ����Ƿ� count + 1�� ��ȯ�մϴ�. 
}

//��� ����ϴ� �Լ��Դϴ�. 
void print_all(struct tel** tel_list, int count)
{
	int i = 0;

	//�ݺ������� ��� ���
	for (i = 0; i < count; ++i)
		printf("%s %s %s\n", tel_list[i][0].name, tel_list[i][0].tel_no, tel_list[i][0].birth);
}

//Ư�� ����� �����ϴ� �Լ��Դϴ�. 
int delete_tel(struct tel** tel_list, int count)
{
	char temp[101];
	int checker = 0;
	int i = 0, j = 0;
	int index_i = count;

	//������ ���ٸ� NO MEMBER�� ����ϰ� �Լ��� �����մϴ�. 
	if (count == 0)
	{
		printf("NO MEMBER\n");
		return count;
	}

	//Ư�� ��� �Է� 
	printf("Name:");
	scanf("%s", temp);

	//Ư�� ����� ã�� �ּҸ� �����մϴ�. 
	for (i = 0; i < count; ++i)
	{
		if (!strcmp(temp, tel_list[i][0].name)) //���� ã���� �ϴ� �̸��� ã�� �Ǹ� 
		{
			//�ּҸ� �����ϰ� checker�� 1�� ����ϴ�. 
			index_i = i;
			checker = 1;
		}
	}

	//���� checker�� 0�̶�� Ư�� ����� ���ٴ� �ǹ��̹Ƿ� �Լ��� �����մϴ�. 
	if (checker == 0)
		return count;

	//Ư�� ����� ã�Ҵٸ� ������ �մϴ�. 
	else if (checker == 1)
	{
		//�ּҸ� �̿��� �ݺ������� Ư�� ������� ������ ��� �̵������ݴϴ�. 
		for (i = index_i; i < count - 1; ++i)
		{
			strcpy(tel_list[i][0].name, tel_list[i + 1][0].name);
			strcpy(tel_list[i][0].tel_no, tel_list[i + 1][0].tel_no);
			strcpy(tel_list[i][0].birth, tel_list[i + 1][0].birth);
		}
	}

	//�Ҵ������� �մϴ�.	
	free(tel_list[count - 1][0].name);
	free(tel_list[count - 1][0].tel_no);
	free(tel_list[count - 1][0].birth);
	free(tel_list[count - 1]);

	//������ �ϳ� ��������Ƿ� count - 1�� ��ȯ�մϴ�. 
	return count - 1;
}

//������ ������� ����ϴ� �Լ��Դϴ�. 
void find_by_birth(struct tel** tel_list, int count)
{
	int i = 0, j = 0;
	int number;
	char* pc1, * pc2;
	char month[3];

	//ã���� �ϴ� ���� �ѹ� �Է� 
	printf("Birth:");
	scanf("%d", &number);

	for (i = 0; i < count; ++i)
	{
		//�� ������� ���� ���� ã�Ƽ� �����մϴ�. 
		for (pc1 = tel_list[i][0].birth + 4, pc2 = month; pc1 < tel_list[i][0].birth + 6; ++pc1, ++pc2)
			*pc2 = *pc1;
		*pc2 = '\0';

		if (number == atoi(month)) //���� ã���� �ߴ� �����̶�� �� ����� ������ ����մϴ�. 
			printf("%s %s %s\n", tel_list[i][0].name, tel_list[i][0].tel_no, tel_list[i][0].birth);
	}
}

/*
3
1
HongGilDong
01111112222
20000101
1
KimJoo
222111333
19960303
1
Han
010222333
19980101
1
5
*/