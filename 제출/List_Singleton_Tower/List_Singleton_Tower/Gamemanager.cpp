#include "Gamemanager.h"



Gamemanager::Gamemanager()
{
}


void Gamemanager::stacktower(int num)
{

	if (num < 0 || num>9)
	{
		cout << "0���� 9������ ���ڸ� �Է����ּ���" << endl;
		system("pause");
	}
	m_sTower.push_back(num);
}


void Gamemanager::removetower(int num)
{
	if (m_sTower.empty())
	{
		cout << "������ ���ڰ� �����ϴ�" << endl;
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
