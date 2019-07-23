#pragma once
#include"Mecro.h"
#include"Draw.h"
#define P1 0
#define P2 1
#define P3 2
#define PLAYER 0
#define MONSTER 1


class Character
{
private:
	Draw DrawManager;
protected:
	string m_sName;
	int m_iClass;
	int m_iLv;
	int m_iAtk;
	int m_iDef;
	int m_iRange;
	int m_iMaxHp;
	int m_iCurHp;
	int m_iMaxExp;
	int m_iCurExp;
	int m_iGiveExp;
public:
	Character();
	virtual void InputData(int Class=NULL, int Num = NULL)=0;
	virtual void GetExp(int Exp)=0;
	void DealToEnemy(int DmgToEnemy[]);
	void GetDmg(int Dmg[], int Target);
	int RandClass();
	void ShowStat(int X,int Y);
	void ShowBattleStat(int Check);
	bool WinCheck();
	void Recovery(int Percent=100);
	string OutputName() { return m_sName; }
	int OutputClass() { return m_iClass; }
	virtual ~Character();
};