#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100

//����ü tel�Դϴ�. 
struct tel
{
	char name[21]; //�̸�
	char tel_no[16]; //��ȭ��ȣ
	char birth[9]; //���� 
};

//�Լ��������� 
int insert(struct tel*, int); //�Է�
void print_all(struct tel*, int); //���
int delete_tel(struct tel*, int); //����
void find_by_birth(struct tel*, int); //�����λ�� ���� 


int main()
{
	struct tel tel_list[MAX_NUM]; //�ִ� 100�� ���� 
	int count = 0; //���� ����ó ���� 
	int n = 0; //��� �Է� 

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
		case 5: //���α׷� ���� 
			return 0;
		}
	}
	return 0;
}

//�Է��Լ��Դϴ�. 
int insert(struct tel* tel_list, int count)
{
	char temp[21];
	struct tel* p_tel;
	struct tel* index = tel_list + count;
	int checker = 0;

	//���� 100�� ������ �� ����Ǿ��ٸ� OVERFLOW�� ����ϰ� �Լ��� �����մϴ�. 
	if (count >= 100)
	{
		printf("OVERFLOW");
		return count;
	}

	printf("Name:"); // ���� ...
	scanf("%s", temp); //�켱 �̸��� �޴´�. 

	//�̸��� ���������� ���ؼ� ������ �ε����� ã�´�. 
	for (p_tel = tel_list; p_tel < tel_list + count; ++p_tel)
	{
		if (strcmp(p_tel->name, temp) > 0)
		{
			index = p_tel; //�ּҸ� �����մϴ�. 
			checker = 1; //�׸��� �ڷ��̵��� �ʿ��ϹǷ� checker�� 1���� ����ϴ�. 
			break;
		}
	}

	//�׸��� �̸��� �߰��ϱ� ���ؼ� �ڷ��̵��� �ʿ��ϴٰ� �ǴܵǹǷ� ������ �ڷ���� �̵���ŵ�ϴ�. 
	if (checker == 1)
	{
		//�ּҸ� Ȱ���� �ݺ������� �ڷ���� �̵���ŵ�ϴ�. 
		for (p_tel = tel_list + count; p_tel > index; --p_tel)
			*p_tel = *(p_tel - 1);
	}

	strcpy(index->name, temp); //�׸��� �̸����� �����մϴ�. 

	//�޴��� �ѹ��� ������ ������ �޽��ϴ�. 
	printf("Phone_number:"); // ���� ...
	scanf("%s", index->tel_no);
	printf("Birth:"); //����
	scanf("%s", index->birth);

	printf("<<%d>> \n", count + 1); //�׸��� �������� �󸶳� �ִ��� ����մϴ�. 
	return count + 1; //������ �߰��Ǿ����Ƿ� count + 1�� ��ȯ�մϴ�. 
}

//��� ����ϴ� �Լ��Դϴ�. 
void print_all(struct tel* tel_list, int count)
{
	struct tel* p_tel1;

	//�ּҸ� �̿��� �ݺ������� ��� ����մϴ�. 
	for (p_tel1 = tel_list; p_tel1 < tel_list + count; ++p_tel1)
		printf("%s %s %s\n", p_tel1->name, p_tel1->tel_no, p_tel1->birth);
}

//Ư�� ����� �����ϴ� �Լ��Դϴ�. 
int delete_tel(struct tel* tel_list, int count)
{
	char temp[21];
	struct tel* p_tel;
	struct tel* index = NULL;
	int checker = 0;

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
	for (p_tel = tel_list; p_tel < tel_list + count; ++p_tel)
	{
		if (!strcmp(temp, p_tel->name)) //���� ã���� �ϴ� �̸��� ã�� �Ǹ� 
		{
			//�ּҸ� �����ϰ� checker�� 1�� ����ϴ�. 
			index = p_tel;
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
		for (p_tel = index; p_tel < tel_list + count - 1; ++p_tel)
			*p_tel = *(p_tel + 1);
	}

	//������ �ϳ� ��������Ƿ� count - 1�� ��ȯ�մϴ�. 
	return count - 1;
}

//������ ������� ����ϴ� �Լ��Դϴ�. 
void find_by_birth(struct tel* tel_list, int count)
{
	struct tel* p_tel;
	int number;
	char* pc1, * pc2;
	char month[3];

	//ã���� �ϴ� ���� �ѹ� �Է� 
	printf("Birth:");
	scanf("%d", &number);

	for (p_tel = tel_list; p_tel < tel_list + count; ++p_tel)
	{
		//�� ������� ���� ���� ã�Ƽ� �����մϴ�. 
		for (pc1 = p_tel->birth + 4, pc2 = month; pc1 < p_tel->birth + 6; ++pc1, ++pc2)
			*pc2 = *pc1;
		*pc2 = '\0';

		if (number == atoi(month)) //���� ã���� �ߴ� �����̶�� �� ����� ������ ����մϴ�. 
			printf("%s %s %s\n", p_tel->name, p_tel->tel_no, p_tel->birth);
	}
}