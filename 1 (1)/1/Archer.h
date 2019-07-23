#pragma once
#include"Character.h"
class Archer:public Character
{
public:
	Archer();
	void InputData(int Class=NULL,int Num=NULL);
	void GetExp(int Exp);
	~Archer();
};

