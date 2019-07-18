#pragma once
#include"Mecro.h"
#include"Draw.h"

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
public:
	Character();
	virtual void InputData(int Class=NULL)=0;
	int RandClass();
	void ShowStat(int X,int Y);
	string OutputName() { return m_sName; }
	int OutputClass() { return m_iClass; }
	virtual ~Character();
};