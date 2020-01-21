#pragma once
#include<iostream>
#include <Windows.h>
using namespace std;

class draw
{
private:
	int m_iTowerMax;
public:
	void DrawTower(int *tower[]);
	void EraseStone(int tNum,int sNum);
	void DrawStone(int *tower[], int tNum, int sNum);
	void inline gotoxy(int x, int y)
	{
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	draw(int Tower);
	~draw();
};

