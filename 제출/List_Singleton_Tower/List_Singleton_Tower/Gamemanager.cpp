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
		cout << "탑을 더이상 쌓을수 없습니다!" << endl;
		system("pause");
		Draw.DrawInterface(TOWER_MAX);
		return;
	}

	cout << "쌓을 숫자를 입력해주세요" << endl;
	cin >> num;
	m_sTower.push_back(num);
	Draw.DrawTower(m_sTower,TOWER_MAX);

}


void Gamemanager::removetower()
{
	bool flag = false;
	int num;
	cout << "제거할 숫자를 입력해주세요" << endl;
	cin >> num;

	if (m_sTower.empty())
	{
		cout << "삭제할 숫자가 없습니다" << endl;
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
		cout << "삭제할 숫자가 없습니다" << endl;
		system("pause");
	}


	Draw.DrawTower(m_sTower, TOWER_MAX);

}


Gamemanager::~Gamemanager()
{
}
