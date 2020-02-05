#include"Namecard.h"
#include<stdio.h>
#include<iostream>

int main()
{
	int Max;
	NameCard **CardList;
	char name[NAME_LEN], phone[PHONE_LEN];

	printf("몇명의 정보를 저장 하시겠습니까? : ");
	scanf("%d", &Max);
	CardList = new NameCard*[Max];

	for (int i = 0; i < Max; i++) {
		printf("%d번째 사람의 이름 : ", i + 1);
		scanf("%s", &name);
		printf("%d번째 사람의 번호 : ", i + 1);
		scanf("%s", &phone);
		CardList[i] = MakeNameCard(name, phone);
		system("cls");
	}
	printf("찾고 싶은 번호의 이름 입력 : ");
	scanf("%s", &name);
	for (int i = 0; i < Max; i++)
	{
		if (NameCompare(CardList[i], name))
			ShowNameCardInfo(CardList[i]);
	}
	printf("변경하고 싶은 번호의 이름 입력 : ");
	scanf("%s", &name);
	for (int i = 0; i < Max; i++)
	{
		if (NameCompare(CardList[i], name))
		{
			printf("변경할 번호 입력 : ");
			scanf("%s", &phone);
			ChangePhoneNum(CardList[i], phone);
		}
	}
	printf("삭제 하고 싶은 번호의 이름 입력 : ");
	scanf("%s", &name);
	for (int i = 0; i < Max; i++)
	{
		if (NameCompare(CardList[i], name))
		{
			DeleteData(CardList[i]);
			CardList[i] = NULL;
		}
	}
	for (int i = 0; i < Max; i++) {
		if (CardList[i] == NULL) continue;
		ShowNameCardInfo(CardList[i]);
	}
	return 0;
}