#pragma once
#include"Character.h"

class Monster:public Character
{
public:
	Monster();
	void InputData(int Class=NULL,int Num=NULL);
	void GetExp(int Exp=0);
	~Monster();
};

