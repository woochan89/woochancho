#include "Monster.h"



Monster::Monster()
{
}

void Monster::InputData(int Class, int Num)
{
	//ÆÄÀÏ¿ÀÇÂ
	m_iClass = 0;
	m_sName = "±Ã¼ö";
	m_iLv = 1;
	m_iAtk = 1;
	m_iDef = 1;
	m_iRange = 3;
	m_iMaxHp = 10;
	m_iCurHp = m_iMaxHp;
	//ÆÄÀÏ´İ±â

}

Monster::~Monster()
{
}
