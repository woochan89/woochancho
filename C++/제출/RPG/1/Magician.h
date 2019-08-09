#pragma once
#include"Character.h"
class Magician :public Character
{
public:
	Magician();
	void InputData(int Class = NULL, int Num = NULL);
	void GetExp(int Exp);
	~Magician();
};

