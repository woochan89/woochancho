#include"NameCard.h"

void main()
{
	char Name[30];
	char Number[30];

	for (int i = 0; i < 3; i++)
	{
		cout << "�̸��� �Է����ּ��� : ";
		cin >> Name;
		cout << "�޴��� ��ȣ�� �Է����ּ��� : ";
		cin >> Number;
		*MakeNameCard(Name, Number);
	}
}