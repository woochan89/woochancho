#include"NameCard.h"

void main()
{
	char Name[30];
	char Number[30];
	int People;

	NameCard **Card;
	int sel;
	bool flag;
	
	cout << "����� ī�� ������ �Է��Ͻðڽ��ϱ�?" << endl;
	cin >> People;
	Card = new NameCard*[People];
	for (int i = 0; i < People; i++)
	{
		system("cls");
		cout <<i+1 <<"��° ī���� �̸��� �Է����ּ��� : ";
		cin >> Name;
		cout <<i+1<< "��° ī���� �޴��� ��ȣ�� �Է����ּ��� : ";
		cin >> Number;
		Card[i] = MakeNameCard(Name, Number);
	}
	
	while (true)
	{
		system("cls");
		cout << "1. ���� ���" << endl;
		cout << "2. ��ȣ ���� " << endl;
		cout << "3. ���� ����" << endl;
		cout << "4.����" << endl;
		cout << "�Է� : " << endl;
		cin >> sel;
		switch (sel)
		{
		case 1:
			for (int i = 0; i < People; i++)
			{
				if (Card[i] == NULL)
					continue;
				ShowNameCardInfo(Card[i]);
			}
			system("pause");
			break;

		case 2:
			flag = false;
			cout << "��ȣ�� ������ �̸��� �Է����ֽʽÿ�" << endl;
			cin >> Name;
			for (int i = 0; i < People; i++)
			{
				if (NameCompare(Card[i], Name))
				{
					cout << "������ ��ȣ�� �Է��ϼ���" << endl;
					cin >> Number;
					ChangePhoneNum(Card[i], Number);
					flag = true;
				}
			}
			if(flag==false)
			{
				cout << "�ش� �̸��� ī�尡 �������� �ʽ��ϴ�" << endl;
				system("pause");
			}
			break;

		case 3:
			flag = false;
			cout << "���� �� ī���� �̸��� �Է����ֽʽÿ�" << endl;
			cin >> Name;
			for (int i = 0; i < People; i++)
			{
				if (NameCompare(Card[i], Name))
				{
					DeleteData(Card[i]);
					Card[i] = NULL;
					flag = true;
					cout << Name << "�� ī�带 �����߽��ϴ�" << endl;
					system("pause");
				}
			}
			if(flag==false)
			{
				cout << "�ش� �̸��� ī�尡 �������� �ʽ��ϴ�" << endl;
				system("pause");
			}
			break;

		case 4:
			return;
		}
	}
}