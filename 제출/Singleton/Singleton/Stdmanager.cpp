#include "Stdmanager.h"

Stdmanager* Stdmanager::m_pThis = NULL;

Stdmanager::Stdmanager()
{
	for (int i = 0; i < STD_MAX; i++)
	{
		std[i] = new Student;
		std[i]->num = NULL;
	}
}


void Stdmanager::Setstudent()
{
	for (int i = 0; i < STD_MAX; i++)
	{
		if (std[i]->num == NULL)
		{
			cout << "�̸��� �Է� �Ͻÿ� : ";
			cin >> std[i]->name;
			cout << "3������ ������ �Է��Ͻÿ�" << endl;
			cout << "���� : ";
			cin >> std[i]->kor;
			cout << "���� : ";
			cin >> std[i]->eng;
			cout << "���� : ";
			cin >> std[i]->math;
			std[i]->sum = std[i]->kor + std[i]->eng + std[i]->math;
			std[i]->avg = (float)std[i]->sum / 3;
			std[i]->num = i + 1;
			if (std[i]->avg >= 90)
				std[i]->Class = 'A';
			else if (std[i]->avg >= 80)
				std[i]->Class = 'B';
			else if (std[i]->avg >= 70)
				std[i]->Class = 'C';
			else if (std[i]->avg >= 60)
				std[i]->Class = 'D';
			else
				std[i]->Class = 'F';
			return;

		}
	}
	cout << "�л��� ���� ��� �Ǿ����ϴ�" << endl;
}

void Stdmanager::Display()
{
	int std_count = 0;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->num != 0)
		{
			ShowStudent(std[i]);
			std_count++;
		}
	}
	if (std_count == 0)
		cout << "��ϵ� �л��� �����ϴ�" << endl;
	system("pause");

}

void Stdmanager::Findnumber()
{
	int find_num;
	cout << "ã�� �л��ǹ�ȣ�� �Է� �Ͻÿ�";
	cin >> find_num;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->num == find_num)
		{
			ShowStudent(std[i]);
			system("pause");
			return;
		}
	}
	cout << endl << "�ش� ��ȣ�� �л��� �����ϴ�." << endl;
	system("pause");

}

void Stdmanager::Findname()
{
	string find_name;
	int find_num = 0;
	cout << "ã�� �л����̸��� �Է� �Ͻÿ�" << endl;
	cin >> find_name;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->name == find_name)
		{
			ShowStudent(std[i]);
			find_num++;
		}
	}
	if (!find_num)
		cout << "�ش� �̸��� �л��� �����ϴ�." << endl;
	system("pause");

}

void Stdmanager::Findclass()
{
	int _find = 0;


	cout << "========= [ A ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'A')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ B ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'B')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ C ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'C')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ D ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'D')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	_find = 0;
	cout << "========= [ F ] =========" << endl;
	for (int i = 0; i < 30; i++)
	{
		if (std[i]->Class == 'F')
		{
			ShowStudent(std[i]);
			_find++;
		}
	}
	cout << "�� " << _find << "��" << endl;
	cout << "=========================" << endl;
	system("pause");

}

void Stdmanager::ShowStudent(Student *std)
{
	cout << "----------------------" << endl;
	cout << std->num << "�� �л�" << endl;
	cout << "�̸� : " << std->name << endl;
	cout << "���� ���� : " << std->kor << endl << "���� ���� : " << std->math << endl << "���� ���� : " << std->eng << endl;
	cout << "�հ� ���� : " << std->sum << "\t ������� : " << std->avg << endl;
	cout << "��� : [ " << std->Class << "]" << endl << endl;
}


Stdmanager::~Stdmanager()
{
	for (int i = 0; i < STD_MAX; i++)
		delete std[i];
}
