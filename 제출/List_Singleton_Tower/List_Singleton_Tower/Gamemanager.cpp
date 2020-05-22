#include "Gamemanager.h"



Gamemanager::Gamemanager()
{
}


void Gamemanager::stacktower(int num)
{

	if (num < 0 || num>9)
	{
		cout << "0에서 9사이의 숫자를 입력해주세요" << endl;
		system("pause");
	}
	m_sTower.push_back(num);
}


void Gamemanager::removetower(int num)
{
	if (m_sTower.empty())
	{
		cout << "삭제할 숫자가 없습니다" << endl;
		system("pause");
	}
	
	for (list<int>::reverse_iterator riter = m_sTower.rbegin(); riter != m_sTower.rend(); riter++)
	{
		if(*riter==num)

	}
}


Gamemanager::~Gamemanager()
{
}
