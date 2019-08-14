#pragma once
#include"mecro.h"
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
	void DrawTextWithBox(string str, int x, int y);
	void ErasePoint(int x, int y);
	void DrawBox();
	void DrawSmallBox(int x, int y, int Width, int Height);
	int DrawCursor(int Volume, int StartX, int StartY, int Space = 2);
	void DrawHeart(int Heart=9);
	void DrawScore(int Score=0);
	void DrawName(string Name);
	void Drawinterface(string Name = "? ? ?");
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	Draw();
	~Draw();
};

