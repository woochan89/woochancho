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
	cout << "┌───────────────────────┐" ;
	DrawManager.gotoxy(X, Y+1);
	cout << "  이름 : " << m_sName << "\t레벨 : " << m_iLv << "\t경험치 " << m_iCurExp << "/" << m_iMaxExp;
	DrawManager.gotoxy(X, Y+2);
	cout << "  ATK : " << m_iAtk << "      \tDEF : " << m_iDef <<"    \t등급 "<<m_iClass;
	DrawManager.gotoxy(X, Y+3);
	cout << "  사거리 : " << m_iRange << "\tHP" << m_iCurHp <<"/"<<m_iMaxHp;
	DrawManager.gotoxy(X, Y+4);
	cout << "└───────────────────────┘" << endl;
}

void Character::ShowBattleStat(int Check,int Num)
{
	int x, y,add;
	y = HEIGHT * 0.5;
	if (Check == PLAYER)
	{
		x = 45;
		add = -16;
	}
	else
	{
		x = 65;
		add = 16;
	}
	DrawManager.gotoxy(x+(Num*add), y+1);
	cout << m_sName << "  LV : " << m_iLv;
	DrawManager.gotoxy(x + (Num*add), y+2);
	cout << "ATK:" << m_iAtk << "    DEF:" << m_iDef;
	DrawManager.gotoxy(x + (Num*add), y + 3);
	cout << "사거리 : "<<m_iRange<<"  ";
	DrawManager.gotoxy(x + (Num*add), y + 4);
	cout << "HP:" << m_iCurHp << "/" << m_iMaxHp<<"   ";
	DrawCharacter(x + (Num * add) +1,y-7);
}

void Character::DealToEnemy(int DmgToEnemy[],Character *EnemyList[])
{
	int Target;

	if (m_iCurHp == 0)
		return;

	if (m_iRange == 1)
		Target = P1;
	else if (m_iRange == 2)
		Target = P2;
	else
		Target = P3;

	if (EnemyList[Target]->m_iCurHp == 0)
	{
		if (Target == P1)
		{
			if(EnemyList[P2]->m_iCurHp!=0)
				DmgToEnemy[P2] += m_iAtk;
			else
				DmgToEnemy[P3] += m_iAtk;
		}
		else if (Target == P2)
		{
			if (EnemyList[P1]->m_iCurHp != 0)
				DmgToEnemy[P1] += m_iAtk;
			else
				DmgToEnemy[P3] += m_iAtk;

		}
		else if (Target == P3)
		{
			if (EnemyList[P1]->m_iCurHp != 0)
				DmgToEnemy[P1] += m_iAtk;
			else
				DmgToEnemy[P2] += m_iAtk;
		}
		return;
	}

	DmgToEnemy[Target] += m_iAtk;
}

void Character::GetDmg(int Dmg[],int Target)
{
	if (Dmg[Target] == 0)
		return;
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

void Character::Recovery(int Percent)
{
	if (Percent <= 0)
		return;
	m_iCurHp += (m_iMaxHp*Percent*0.01);
	if (m_iCurHp > m_iMaxHp)
		m_iCurHp = m_iMaxHp;
}

void Character::DrawCharacter(int x, int y)
{
	//색추가
	DrawManager.gotoxy(x, y);
	if (m_iCurHp == 0)
		cout << "(Ｘ.Ｘ)";
	else
		cout << "(ㅇ.ㅇ)";
	DrawManager.gotoxy(x, y+1);
	cout<<"─┼─";
	DrawManager.gotoxy(x, y+2);
	cout << "  Α  ";
	DrawManager.gotoxy(x, y+3);
	cout << " ／ ＼";
	//색제거
}

Character::~Character()
{
}