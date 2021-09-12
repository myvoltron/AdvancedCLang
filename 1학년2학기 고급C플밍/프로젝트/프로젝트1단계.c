#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100

//구조체 tel입니다. 
struct tel
{
	char name[21]; //이름
	char tel_no[16]; //전화번호
	char birth[9]; //생일 
};

//함수원형설정 
int insert(struct tel*, int); //입력
void print_all(struct tel*, int); //출력
int delete_tel(struct tel*, int); //삭제
void find_by_birth(struct tel*, int); //생일인사람 추적 


int main()
{
	struct tel tel_list[MAX_NUM]; //최대 100개 가능 
	int count = 0; //현재 연락처 개수 
	int n = 0; //명령 입력 

	while (1) //무한반복문으로 5가 입력되기 전까지 계속해서 작동하게 합니다. 
	{
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
		printf("Enter_the_menu_number:");

		scanf("%d", &n); //명령어를 입력합니다. 

		switch (n)
		{
		case 1:
			count = insert(tel_list, count); //입력함수로 가게되고 그 결과로 count변수를 조정합니다. 
			break;
		case 2:
			print_all(tel_list, count); //출력함수실행
			break;

		case 3:
			count = delete_tel(tel_list, count); //삭제함수로 가게되고 그 결과에 따라 count변수를 조정합니다. 
			break;
		case 4:
			find_by_birth(tel_list, count); //생일인 사람을 찾는 함수실행 
			break;
		case 5: //프로그램 종료 
			return 0;
		}
	}
	return 0;
}

//입력함수입니다. 
int insert(struct tel* tel_list, int count)
{
	char temp[21];
	struct tel* p_tel;
	struct tel* index = tel_list + count;
	int checker = 0;

	//만일 100개 정보가 다 저장되었다면 OVERFLOW를 출력하고 함수를 종료합니다. 
	if (count >= 100)
	{
		printf("OVERFLOW");
		return count;
	}

	printf("Name:"); // 고정 ...
	scanf("%s", temp); //우선 이름을 받는다. 

	//이름을 사전순으로 비교해서 삽입할 인덱스를 찾는다. 
	for (p_tel = tel_list; p_tel < tel_list + count; ++p_tel)
	{
		if (strcmp(p_tel->name, temp) > 0)
		{
			index = p_tel; //주소를 저장합니다. 
			checker = 1; //그리고 자료이동이 필요하므로 checker를 1으로 만듭니다. 
			break;
		}
	}

	//그리고 이름을 추가하기 위해서 자료이동이 필요하다고 판단되므로 나머지 자료들을 이동시킵니다. 
	if (checker == 1)
	{
		//주소를 활용한 반복문으로 자료들을 이동시킵니다. 
		for (p_tel = tel_list + count; p_tel > index; --p_tel)
			*p_tel = *(p_tel - 1);
	}

	strcpy(index->name, temp); //그리고 이름값을 복사합니다. 

	//휴대폰 넘버와 생일의 값들을 받습니다. 
	printf("Phone_number:"); // 고정 ...
	scanf("%s", index->tel_no);
	printf("Birth:"); //고정
	scanf("%s", index->birth);

	printf("<<%d>> \n", count + 1); //그리고 정보들이 얼마나 있는지 출력합니다. 
	return count + 1; //정보가 추가되었으므로 count + 1을 반환합니다. 
}

//모두 출력하는 함수입니다. 
void print_all(struct tel* tel_list, int count)
{
	struct tel* p_tel1;

	//주소를 이용한 반복문으로 모두 출력합니다. 
	for (p_tel1 = tel_list; p_tel1 < tel_list + count; ++p_tel1)
		printf("%s %s %s\n", p_tel1->name, p_tel1->tel_no, p_tel1->birth);
}

//특정 대상을 삭제하는 함수입니다. 
int delete_tel(struct tel* tel_list, int count)
{
	char temp[21];
	struct tel* p_tel;
	struct tel* index = NULL;
	int checker = 0;

	//정보가 없다면 NO MEMBER를 출력하고 함수를 종료합니다. 
	if (count == 0)
	{
		printf("NO MEMBER\n");
		return count;
	}

	//특정 대상 입력 
	printf("Name:");
	scanf("%s", temp);

	//특정 대상을 찾고 주소를 저장합니다. 
	for (p_tel = tel_list; p_tel < tel_list + count; ++p_tel)
	{
		if (!strcmp(temp, p_tel->name)) //만약 찾고자 하는 이름을 찾게 되면 
		{
			//주소를 저장하고 checker를 1로 만듭니다. 
			index = p_tel;
			checker = 1;
		}
	}

	//만약 checker가 0이라면 특정 대상이 없다는 의미이므로 함수를 종료합니다. 
	if (checker == 0)
		return count;

	//특정 대상을 찾았다면 삭제를 합니다. 
	else if (checker == 1)
	{
		//주소를 이용한 반복문으로 특정 대상이하 값들을 모두 이동시켜줍니다. 
		for (p_tel = index; p_tel < tel_list + count - 1; ++p_tel)
			*p_tel = *(p_tel + 1);
	}

	//정보가 하나 사라졌으므로 count - 1를 반환합니다. 
	return count - 1;
}

//생일인 사람들을 출력하는 함수입니다. 
void find_by_birth(struct tel* tel_list, int count)
{
	struct tel* p_tel;
	int number;
	char* pc1, * pc2;
	char month[3];

	//찾고자 하는 생일 넘버 입력 
	printf("Birth:");
	scanf("%d", &number);

	for (p_tel = tel_list; p_tel < tel_list + count; ++p_tel)
	{
		//각 사람들의 생일 월을 찾아서 저장합니다. 
		for (pc1 = p_tel->birth + 4, pc2 = month; pc1 < p_tel->birth + 6; ++pc1, ++pc2)
			*pc2 = *pc1;
		*pc2 = '\0';

		if (number == atoi(month)) //만약 찾고자 했던 생일이라면 그 사람의 정보를 출력합니다. 
			printf("%s %s %s\n", p_tel->name, p_tel->tel_no, p_tel->birth);
	}
}