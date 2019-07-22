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
	cout << "  이름 : " << m_sName << "\t등급 : " << m_iClass << "\t레벨 : " << m_iLv;
	DrawManager.gotoxy(X, Y+2);
	cout << "  ATK : " << m_iAtk << "\tDEF : " << m_iDef <<"\t경험치 "<<m_iCurHp<<"/"<<m_iMaxHp;
	DrawManager.gotoxy(X, Y+3);
	cout << "  사정거리 : " << m_iRange << "\tHP" << m_iCurHp <<"/"<<m_iMaxHp;
	DrawManager.gotoxy(X, Y+4);
	cout << "└─────────────────┘" << endl;
}

void Character::ShowBattleStat(int Check)
{
	int x, y,add;
	if (Check == PLAYER)
	{
		x = 20;
		y = 10;
		add = -5;
	}
	else
	{
		x = 25;
		y = 10;
		add = 5;
	}
	for (int i = 0; i < 3; i++)
	{
		DrawManager.gotoxy(x+(i*add), y);
		cout << m_sName << "    LV : " << m_iLv;
		DrawManager.gotoxy(x + (i*add), y+1);
		cout << "ATK : " << m_iAtk << "    DEF : " << m_iDef;
		DrawManager.gotoxy(x + (i*add), y + 1);
		cout << "HP : " << m_iCurHp << " / " << m_iMaxHp;
	}

}

void Character::DealToEnemy(int DmgToEnemy[])
{
	int Target;

	if (m_iRange == 1)
		Target = P1;
	else if (m_iRange == 2)
		Target = P2;
	else
		Target = P3;

	DmgToEnemy[Target] = m_iAtk;
}

void Character::GetDmg(int Dmg[],int Target)
{
	if (m_iCurHp == 0)
	{
		Dmg[Target + 1] += Dmg[Target];
		return;
	}
	int FinalDmg = Dmg[Target] - m_iDef;
	if (FinalDmg <= 0)
		FinalDmg = 1;
	m_iCurHp -= FinalDmg;
	if (m_iCurHp < 0)
		m_iCurHp = 0;
}

bool Character::WinCheck()
{
	if (m_iCurHp == 0)
		return true;
	return false;
}

void Character::LevelUp()
{

}

Character::~Character()
{
}