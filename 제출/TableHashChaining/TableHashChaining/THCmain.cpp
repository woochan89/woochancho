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
		printf("%d��° ���\n", i);
		printf("�̸� �Է� : ");
		scanf("%s", &name);
		printf("�ֹε�Ϲ�ȣ �Է� : ");
		scanf("%d", &ssn);
		printf("�ּ� �Է� : ");
		scanf("%s", &addr);
		TBLinsert(&tbl, ssn, InputPerson(ssn,name,addr));
	}

	while (1)
	{
		system("cls");
		printf("������ �ֹε�Ϲ�ȣ �Է�(���� : -1) : ");
		scanf("%d", &key);
		if (key == -1)
			break;
		if (v = TBLdelete(&tbl, key))
		{
			PrintPerson(*v);
			printf("���� �Ϸ�!\n");
		}
		else printf("��ϵ� ����� �ƴմϴ�\n");
		system("pause");
	}

	while (1)
	{
		system("cls");
		printf("��ȸ�� �ֹε�Ϲ�ȣ �Է�(���� : -1) : ");
		scanf("%d", &key);
		if (key == -1)
			break;
		if (v=TBLsearch(&tbl, key))
			PrintPerson(*v);
		else printf("��ϵ� ����� �ƴմϴ�\n");
		system("pause");
	}

	TBLdeleteALL(&tbl);
	return 0;
}