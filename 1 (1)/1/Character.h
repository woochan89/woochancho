#pragma once
#include"Mecro.h"

class Character
{
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
	string OutputName() { return m_sName; }
	int OutputClass() { return m_iClass; }
	virtual ~Character();
};