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

Character::~Character()
{
}
