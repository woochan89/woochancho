#pragma once
#include"Armor.h"
#include"Bag.h"
#include"Weapon.h"
#include"Ring.h"
#include"Mecro.h"
#include<Windows.h>
#include<conio.h>

class Gamemanager
{
public:
	void drawitem(Item* shop, Item* player);
	int controlcursor(int item_max);
	inline void gotoxy(int x, int y)
	{	COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);}
	Gamemanager();
	~Gamemanager();
};

