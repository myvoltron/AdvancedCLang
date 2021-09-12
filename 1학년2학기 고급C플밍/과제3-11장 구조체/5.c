#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////구조체 student/////////
struct student
{
	char name[31];
	char stnum[10];
	int cnum;
	char classname[10][31];
	double grade[10];
	double avg_grade;
};

///////함수원형/////////
void sort_s(struct student st[], int cnt);
void print_s(struct student st[], int cnt);
void input_info(struct student st[]);
int delete_s(struct student st[], char deletename[], int cnt);

////////main함수/////////
int main()
{
	//변수나 배열, 포인터 등을 선언합니다. 
	char key, tmp;
	struct student st[100];
	struct student* p1 = st; //포인터 p1을 st와 연결합니다. 
	int cnt1 = 0; //입력한 학생의 수
	char deletename[31];
	int checker = 0;

	while (1)
	{
		if (p1 > st + 100) //만약 p1의 주소값이 st + 100을 넘는다면 break
			break;

		scanf("%c%c", &key, &tmp); //명령어를 입력받습니다.

		if (key == 'I') //학생정보입력
		{
			input_info(p1);
			p1++; //주소에 1을 더합니다.
			cnt1++; //학생수 cnt1에 1을 더합니다. 
		}

		else if (key == 'S') // 오름차순 정렬 후 출력	
		{
			if (cnt1 == 0)	//만약 남아있는 학생이 없다면 continue합니다. 		  	
				continue;

			sort_s(st, cnt1);
		}

		else if (key == 'D') //학생정보 삭제
		{
			scanf("%s", deletename); //정보를 삭제할 학생의 이름을 받습니다.
			getchar(); //버퍼 받아주기

			checker = delete_s(st, deletename, cnt1); //이후 삭제를 했다면 1을 받고 아니라면 0을 받습니다.
			cnt1 -= checker; //checker의 값만큼 뺄셈연산을 합니다.
			p1 -= checker;
		}

		else if (key == 'P') //남아있는 학생 정보 출력
		{
			if (cnt1 == 0)	//만약 남아있는 학생이 없다면 continue합니다. 		  
				continue;

			print_s(st, cnt1);
		}

		else if (key == 'Q') //작업 종료		
			break;
	}

	return 0;
}


//////함수원형설정/////
void sort_s(struct student st[], int cnt) //오름차순으로 정렬해서 출력하는 함수입니다.
{
	//배열 포인터 변수 등을 선언합니다.
	struct student sort_st[100];
	struct student* p1, * p2;
	struct student* ps;
	struct student tmp;

	for (p1 = st, ps = sort_st; p1 < st + cnt; ++p1, ++ps) // ps와 sort_st를 연결해서 이 배열에 본래 배열값들을 복사해줍니다.
		*ps = *p1;

	//이름기준으로 오름차순 정렬
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

	//오름차순 정렬한 것을 출력
	print_s(sort_st, cnt);
}

void print_s(struct student st[], int cnt) //학생들의 정보를 출력하는 함수
{
	struct student* p1;

	//이름 학번 과목수 평균학점을 출력합니다.
	for (p1 = st; p1 < st + cnt; ++p1)
		printf("%s %s %d %.2lf\n", p1->name, p1->stnum, p1->cnum, p1->avg_grade);
}

void input_info(struct student st[]) //학생의 정보를 입력하는 함수
{
	struct student* p1 = st; //입력받은 배열과 연결한다.

	//각 값들을 0으로 초기화해줍니다. 
	int i = 0;
	p1->avg_grade = 0;
	p1->cnum = 0;

	//각 값들을 입력합니다.
	scanf("%s", p1->name);
	scanf("%s", p1->stnum);
	scanf("%d", &p1->cnum);
	for (i = 0; i < p1->cnum; ++i)
	{
		scanf("%s", p1->classname[i]);
		scanf("%lf", &p1->grade[i]);
		p1->avg_grade += p1->grade[i];
	}
	getchar(); //버퍼받기

	p1->avg_grade = (double)(p1->avg_grade) / p1->cnum; //grade에 평균학점을 대입
}

int delete_s(struct student st[], char deletename[], int cnt) //학생의 정보를 삭제하는 함수
{
	struct student* p1, * p2;

	for (p1 = st; p1 < st + cnt; ++p1)
	{
		if (strcmp(deletename, p1->name) == 0) //만약 삭제할 이름을 찾게 되면
		{
			for (p2 = p1; p2 < st + cnt - 1; ++p2) // 왼쪽으로 밀어서 삭제를 한다.
				*p2 = *(p2 + 1);

			return 1; //이후 1을 반환합니다. 
		}
	}

	return 0; // 0을 반환합니다. 
}