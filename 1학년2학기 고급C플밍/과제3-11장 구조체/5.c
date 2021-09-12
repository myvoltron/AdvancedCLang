#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////����ü student/////////
struct student
{
	char name[31];
	char stnum[10];
	int cnum;
	char classname[10][31];
	double grade[10];
	double avg_grade;
};

///////�Լ�����/////////
void sort_s(struct student st[], int cnt);
void print_s(struct student st[], int cnt);
void input_info(struct student st[]);
int delete_s(struct student st[], char deletename[], int cnt);

////////main�Լ�/////////
int main()
{
	//������ �迭, ������ ���� �����մϴ�. 
	char key, tmp;
	struct student st[100];
	struct student* p1 = st; //������ p1�� st�� �����մϴ�. 
	int cnt1 = 0; //�Է��� �л��� ��
	char deletename[31];
	int checker = 0;

	while (1)
	{
		if (p1 > st + 100) //���� p1�� �ּҰ��� st + 100�� �Ѵ´ٸ� break
			break;

		scanf("%c%c", &key, &tmp); //��ɾ �Է¹޽��ϴ�.

		if (key == 'I') //�л������Է�
		{
			input_info(p1);
			p1++; //�ּҿ� 1�� ���մϴ�.
			cnt1++; //�л��� cnt1�� 1�� ���մϴ�. 
		}

		else if (key == 'S') // �������� ���� �� ���	
		{
			if (cnt1 == 0)	//���� �����ִ� �л��� ���ٸ� continue�մϴ�. 		  	
				continue;

			sort_s(st, cnt1);
		}

		else if (key == 'D') //�л����� ����
		{
			scanf("%s", deletename); //������ ������ �л��� �̸��� �޽��ϴ�.
			getchar(); //���� �޾��ֱ�

			checker = delete_s(st, deletename, cnt1); //���� ������ �ߴٸ� 1�� �ް� �ƴ϶�� 0�� �޽��ϴ�.
			cnt1 -= checker; //checker�� ����ŭ ���������� �մϴ�.
			p1 -= checker;
		}

		else if (key == 'P') //�����ִ� �л� ���� ���
		{
			if (cnt1 == 0)	//���� �����ִ� �л��� ���ٸ� continue�մϴ�. 		  
				continue;

			print_s(st, cnt1);
		}

		else if (key == 'Q') //�۾� ����		
			break;
	}

	return 0;
}


//////�Լ���������/////
void sort_s(struct student st[], int cnt) //������������ �����ؼ� ����ϴ� �Լ��Դϴ�.
{
	//�迭 ������ ���� ���� �����մϴ�.
	struct student sort_st[100];
	struct student* p1, * p2;
	struct student* ps;
	struct student tmp;

	for (p1 = st, ps = sort_st; p1 < st + cnt; ++p1, ++ps) // ps�� sort_st�� �����ؼ� �� �迭�� ���� �迭������ �������ݴϴ�.
		*ps = *p1;

	//�̸��������� �������� ����
	for (p1 = sort_st; p1 < sort_st + cnt; ++p1)
	{
		for (p2 = sort_st; p2 < sort_st + cnt - 1; ++p2)
		{
			if (strcmp(p2->name, (p2 + 1)->name) > 0)
			{
				//swap
				tmp = *p2;
				*p2 = *(p2 + 1);
				*(p2 + 1) = tmp;
			}
		}
	}

	//�������� ������ ���� ���
	print_s(sort_st, cnt);
}

void print_s(struct student st[], int cnt) //�л����� ������ ����ϴ� �Լ�
{
	struct student* p1;

	//�̸� �й� ����� ��������� ����մϴ�.
	for (p1 = st; p1 < st + cnt; ++p1)
		printf("%s %s %d %.2lf\n", p1->name, p1->stnum, p1->cnum, p1->avg_grade);
}

void input_info(struct student st[]) //�л��� ������ �Է��ϴ� �Լ�
{
	struct student* p1 = st; //�Է¹��� �迭�� �����Ѵ�.

	//�� ������ 0���� �ʱ�ȭ���ݴϴ�. 
	int i = 0;
	p1->avg_grade = 0;
	p1->cnum = 0;

	//�� ������ �Է��մϴ�.
	scanf("%s", p1->name);
	scanf("%s", p1->stnum);
	scanf("%d", &p1->cnum);
	for (i = 0; i < p1->cnum; ++i)
	{
		scanf("%s", p1->classname[i]);
		scanf("%lf", &p1->grade[i]);
		p1->avg_grade += p1->grade[i];
	}
	getchar(); //���۹ޱ�

	p1->avg_grade = (double)(p1->avg_grade) / p1->cnum; //grade�� ��������� ����
}

int delete_s(struct student st[], char deletename[], int cnt) //�л��� ������ �����ϴ� �Լ�
{
	struct student* p1, * p2;

	for (p1 = st; p1 < st + cnt; ++p1)
	{
		if (strcmp(deletename, p1->name) == 0) //���� ������ �̸��� ã�� �Ǹ�
		{
			for (p2 = p1; p2 < st + cnt - 1; ++p2) // �������� �о ������ �Ѵ�.
				*p2 = *(p2 + 1);

			return 1; //���� 1�� ��ȯ�մϴ�. 
		}
	}

	return 0; // 0�� ��ȯ�մϴ�. 
}