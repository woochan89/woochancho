#include"Table.h"
#include<iostream>

int HashFunc(int k)
{
	return k % 100;
}

int main()
{
	Table tbl;
	Key ssn;
	char name[MAX], addr[MAX];
	Value v;
	Key key;

	TBLinit(&tbl, HashFunc);

	for (int i = 1; i <= 3; i++)
	{
		system("cls");
		printf("%d번째 사람\n", i);
		printf("이름 입력 : ");
		scanf("%s", &name);
		printf("주민등록번호 입력 : ");
		scanf("%d", &ssn);
		printf("주소 입력 : ");
		scanf("%s", &addr);
		TBLinsert(&tbl, ssn, InputPerson(ssn,name,addr));
	}

	while (1)
	{
		system("cls");
		printf("삭제할 주민등록번호 입력(종료 : -1) : ");
		scanf("%d", &key);
		if (key == -1)
			break;
		if (v = TBLdelete(&tbl, key))
		{
			PrintPerson(*v);
			printf("삭제 완료!\n");
		}
		else printf("등록된 사람이 아닙니다\n");
		system("pause");
	}

	while (1)
	{
		system("cls");
		printf("조회할 주민등록번호 입력(종료 : -1) : ");
		scanf("%d", &key);
		if (key == -1)
			break;
		if (v=TBLsearch(&tbl, key))
			PrintPerson(*v);
		else printf("등록된 사람이 아닙니다\n");
		system("pause");
	}

	TBLdeleteALL(&tbl);
	return 0;
}