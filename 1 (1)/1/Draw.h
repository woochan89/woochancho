#pragma once
#include"Mecro.h"
class Draw
{
private:
	int m_iWidth;
	int m_iHeight;
public:
	void DrawPoint(string str, int x, int y);
	void DrawNum(int Num, int x, int y);
	void DrawMidText(string str, int x, int y);
	void TextDraw(string str, int x, int y);
	void ErasePoint(int x, int y);
	void DrawBox();
	int DrawCursor(int Volume,int StartX,int StartY);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	Draw();
	~Draw();
};

