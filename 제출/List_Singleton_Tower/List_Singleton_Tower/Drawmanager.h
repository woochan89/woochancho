#pragma once
#include<iostream>
#include<list>
#include<Windows.h>
using namespace std;


class Drawmanager
{
public:
	void DrawTower(list<int> tower,int tower_max);
	void DrawInterface(int tower_max);
	inline void gotoxy(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	Drawmanager();
	~Drawmanager();
};

