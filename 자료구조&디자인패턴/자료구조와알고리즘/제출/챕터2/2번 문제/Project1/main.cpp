#include"Namecard.h"
#include<stdio.h>
#include<iostream>

int main()
{
	int Max;
	NameCard **CardList;
	char name[NAME_LEN], phone[PHONE_LEN];

	printf("����� ������ ���� �Ͻðڽ��ϱ�? : ");
	scanf("%d", &Max);
	CardList = new NameCard*[Max];

	for (int i = 0; i < Max; i++) {
		printf("%d��° ����� �̸� : ", i + 1);
		scanf("%s", &name);
		printf("%d��° ����� ��ȣ : ", i + 1);
		scanf("%s", &phone);
		CardList[i] = MakeNameCard(name, phone);
		system("cls");
	}
	printf("ã�� ���� ��ȣ�� �̸� �Է� : ");
	scanf("%s", &name);
	for (int i = 0; i < Max; i++)
	{
		if (NameCompare(CardList[i], name))
			ShowNameCardInfo(CardList[i]);
	}
	printf("�����ϰ� ���� ��ȣ�� �̸� �Է� : ");
	scanf("%s", &name);
	for (int i = 0; i < Max; i++)
	{
		if (NameCompare(CardList[i], name))
		{
			printf("������ ��ȣ �Է� : ");
			scanf("%s", &phone);
			ChangePhoneNum(CardList[i], phone);
		}
	}
	printf("���� �ϰ� ���� ��ȣ�� �̸� �Է� : ");
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