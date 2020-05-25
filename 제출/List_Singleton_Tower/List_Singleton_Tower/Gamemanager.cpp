#include "Gamemanager.h"

Gamemanager* Gamemanager::m_tThis = NULL;

Gamemanager::Gamemanager()
{
}


void Gamemanager::stacktower()
{
	int num;
	if (m_sTower.size() >= TOWER_MAX)
	{
		cout << "ž�� ���̻� ������ �����ϴ�!" << endl;
		system("pause");
		Draw.DrawInterface(TOWER_MAX);
		return;
	}

	cout << "���� ���ڸ� �Է����ּ���" << endl;
	cin >> num;
	m_sTower.push_back(num);
	Draw.DrawTower(m_sTower,TOWER_MAX);

}


void Gamemanager::removetower()
{
	bool flag = false;
	int num;
	cout << "������ ���ڸ� �Է����ּ���" << endl;
	cin >> num;

	if (m_sTower.empty())
	{
		cout << "������ ���ڰ� �����ϴ�" << endl;
		system("pause");
		system("cls");
		Draw.DrawInterface(TOWER_MAX);
		return;
	}
	list<int>::iterator iter = m_sTower.begin();

	for (; iter != m_sTower.end(); iter++)
	{
		if (*iter == num)
		{
			m_sTower.erase(iter);
			flag = true;
			break;
		}
	}
	if (flag == false)
	{
		cout << "������ ���ڰ� �����ϴ�" << endl;
		system("pause");
	}


	Draw.DrawTower(m_sTower, TOWER_MAX);

}


Gamemanager::~Gamemanager()
{
}
