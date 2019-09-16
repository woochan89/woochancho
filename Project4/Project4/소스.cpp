#include<iostream>
#include<string>
using namespace std;

int i = 1;
struct word
{
	int Num1;//�Է¹��� ����
	int Num2;//��° ����
	word *next = NULL;
};

void Input(word *test)
{
	word *add;
	word *tmp = test;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	system("cls");
	if (i == 1)
	{
		cout << i << "��° ����" << endl;
		cout << "���� �Է� : ";
		cin >> tmp->Num1;
		tmp->Num2 = i++;
	}
	else
	{
		add = new word;
		cout << i << "��° ����" << endl;
		cout << "���� �Է� : ";
		cin >> add->Num1;
		add->Num2 = i++;
		tmp->next = add;
	}
}

void Show(word *test)
{
	system("cls");
	word *tmp = test;
	if (!(tmp->Num2 > 0 && tmp->Num2 < 100))
	{
		cout << "�Էµ� ���ڰ� �����ϴ�";
		system("pause");
		return;
	}
	while (1)
	{
		cout << tmp->Num2 << "��° ���ڴ� " << tmp->Num1 << endl;
		if (tmp->next == NULL)
			break;
		tmp = tmp->next;
	}
	system("pause");
}

int Erase(word *test)
{
	word *tmp = test;
	word *tmp2;//�ؽ�Ʈ ������ �ӽ� ����
	word *tmp3;
	int select;
	int tmpNum;
	system("cls");
	cout << "���° �����͸� ����ðڽ��ϱ�?" << endl;
	cin >> select;
	if (select == 1)
		return 1;
	if (select > i || select < 0)
		return 0;
	while (1)
	{
		if (select == tmp->Num2)
		{
			tmpNum = tmp->Num2;
			tmp2 = tmp->next;
			delete tmp;
			tmp = test;
			while (1)
			{
				if (tmp->next != NULL)//next�� NULL�� �ƴҶ�
				{
					tmp3 = tmp->next;
					if (tmp3->Num2 > 0 && tmp3->Num2 < 100)//next Num2�� 0�ʰ� 100�̸��̸� ����ø�
					{
						tmp = tmp->next;
						continue;
					}
					else//�����Ⱚ�̸� break
						break;
				}
				tmp = tmp->next;
			}
			tmp->next = tmp2;
			if (tmp->next != NULL)//next�� NULL�� �ƴҶ��� ����
			{
				while (1)//��° ���� �ϳ��� ���̱�
				{
					tmp = tmp->next;
					tmp->Num2--;
					if (tmp->next == NULL)
						break;
				}
			}
			cout << tmpNum << "��° �����Ϸ�!";
			i--;
			system("pause");
			return 0;
		}
		tmp = tmp->next;
	}
}

void main()
{
	int select;
	word *test;
	word *tmp3;
	test = new word;
	while (1)
	{
		system("cls");
		cout << "1. �Է�" << endl;
		cout << "2. ǥ��" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			Input(test);
			break;
		case 2:
			Show(test);
			break;
		case 3:
			if (Erase(test))
			{
				tmp3 = test;
				test = test->next;
				delete tmp3;
				i--;
			}
			break;
		case 4:
			return;
		}
	}
}