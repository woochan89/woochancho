#include "Warrior.h"



Warrior::Warrior()
{
}

void Warrior::InputData(int Class, int Num)
{
	int ClassStat;
	if (Class == NULL)
		m_iClass = RandClass();
	else
		m_iClass = Class;
	if (Class == 1)
		ClassStat = 5;
	else if (Class == 2)
		ClassStat = 4;
	else if (Class == 3)
		ClassStat = 3;
	else if (Class == 4)
		ClassStat = 2;
	else
		ClassStat = 1;
	m_sName = "전사";
	m_iLv = 1;
	m_iAtk = 1 + ClassStat;
	m_iDef = 3 + ClassStat;
	m_iRange = 1;
	m_iMaxHp = 10 + ClassStat;
	m_iCurHp = m_iMaxHp;
	m_iMaxExp = 10;
	m_iCurExp = 0;
}

void Warrior::GetExp(int Exp)
{
	m_iCurExp += Exp;
	if (m_iCurExp >= m_iMaxExp)
	{
		m_iLv++;
		m_iCurExp -= m_iMaxExp;
		m_iMaxExp += 5;
		m_iAtk += 3;
		m_iDef += 1;
		m_iMaxHp += 3;
		Character::Recovery();//체력 회복
	}
}

Warrior::~Warrior()
{
}
