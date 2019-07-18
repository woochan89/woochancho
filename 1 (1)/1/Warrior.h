#pragma once
#include"Character.h"
class Warrior :public Character
{
public:
	Warrior();
	void InputData(int Class = NULL);

	~Warrior();
};

