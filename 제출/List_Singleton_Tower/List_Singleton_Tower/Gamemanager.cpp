#include "Gamemanager.h"

Gamemanager* Gamemanager::m_tThis = NULL;

Gamemanager::Gamemanager()
{
}


void Gamemanager::stacktower()
{
	int num;
	cout << "���� ���ڸ� �Է����ּ���" << endl;
	cin >> num;


	if (m_sTower.size() >= TOWER_MAX)
	{
		cout << "ž�� ���̻� ������ �����ϴ�!" << endl;
	}
	if (num < 0 || num>9)
	{
		cout << "0���� 9������ ���ڸ� �Է����ּ���" << endl;
	}
	m_sTower.push_back(num);
	Draw.DrawTower(m_sTower,TOWER_MAX);

}


void Gamemanager::removetower()
{
	int num;
	cout << "������ ���ڸ� �Է����ּ���" << endl;
	cin >> num;

	if (m_sTower.empty())
	{
		cout << "������ ���ڰ� �����ϴ�" << endl;
		system("pause");
	}
	
	for (list<int>::iterator iter = m_sTower.begin(); iter != m_sTower.end(); iter++)
	{
		if (*iter == num)
		{
			m_sTower.erase(iter);
			break;
		}
	}
	Draw.DrawTower(m_sTower, TOWER_MAX);

}


Gamemanager::~Gamemanager()
{
}
