#include "Monster.h"



Monster::Monster()
{
}

void Monster::InputData(int Class, int Num)
{
	ifstream load;
	string tmp;
	char buf[20];
	sprintf(buf, "Floor%d.txt",Class);
	load.open(buf);
	for (int i = 0; i < (Num-1) * 6; i++)
	{
		load >> tmp;
	}
	m_iClass = 0;
	load>>m_sName;
	load >> m_iLv;
	load >> m_iAtk;
	load >> m_iDef;
	load >> m_iRange;
	load >> m_iMaxHp;
	m_iCurHp = m_iMaxHp;
	load.close();
}

void Monster::GetExp(int Exp)
{

}

Monster::~Monster()
{
}
