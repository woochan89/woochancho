#include "Character.h"



Character::Character()
{
}

int Character::RandClass()
{
	int Class;

	Class = rand() % 100;
	if (Class < 40)
		Class = 5;
	else if (Class < 70)
		Class = 4;
	else if (Class < 85)
		Class = 3;
	else if (Class < 95)
		Class = 2;
	else
		Class = 1;

	return Class;
}

void Character::ShowStat(int X, int Y)
{
	DrawManager.gotoxy(X, Y);
	cout << "┌─────────────────┐" ;
	DrawManager.gotoxy(X, Y+1);
	cout << "  이름 : " << m_sName << "\t 등급 : " << m_iClass << "\t레벨 : " << m_iLv<<endl;
	DrawManager.gotoxy(X, Y+2);
	cout << "  ATK : " << m_iAtk << "\t DEF : " << m_iDef << endl;
	DrawManager.gotoxy(X, Y+3);
	cout << "  사정거리 : " << m_iRange << "\t" << m_iCurHp <<"/"<<m_iMaxHp<< endl;
	DrawManager.gotoxy(X, Y+4);
	cout << "└─────────────────┘" << endl;
}

Character::~Character()
{
}
