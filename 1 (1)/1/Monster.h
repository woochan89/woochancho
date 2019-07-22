#pragma once
#include"Character.h"

class Monster:public Character
{
public:
	Monster();
	void InputData(int Class=NULL,int Num=NULL);
	~Monster();
};

