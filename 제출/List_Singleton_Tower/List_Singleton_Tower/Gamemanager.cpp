#include "Gamemanager.h"

Gamemanager* Gamemanager::m_tThis = NULL;

Gamemanager::Gamemanager()
{
}


void Gamemanager::stacktower()
{
	int num;
	cout << "쌓을 숫자를 입력해주세요" << endl;
	cin >> num;


	if (m_sTower.size() >= TOWER_MAX)
	{
		cout << "탑을 더이상 쌓을수 없습니다!" << endl;
	}
	if (num < 0 || num>9)
	{
		cout << "0에서 9사이의 숫자를 입력해주세요" << endl;
	}
	m_sTower.push_back(num);
	Draw.DrawTower(m_sTower,TOWER_MAX);

}


void Gamemanager::removetower()
{
	int num;
	cout << "제거할 숫자를 입력해주세요" << endl;
	cin >> num;

	if (m_sTower.empty())
	{
		cout << "삭제할 숫자가 없습니다" << endl;
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
