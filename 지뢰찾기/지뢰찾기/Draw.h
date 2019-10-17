#pragma once
#include"mecro.h"
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define YELLOW SetConsoleTextAttribute( col,0x000e );

class Draw
{
public:
	void DrawPoint(string str, int x, int y);
	void ErasePoint(int x, int y);
	void DrawMidText(string str, int width, int y);
	int DrawArrow(int x,int y,int max,int space=2);
	void DrawBox(int width, int height, int x=NULL, int y=NULL);
	void DrawMidTextWithBox(string str, int width, int y);
	void DrawInterface(int width, int y, int level,int mine);
	void DrawTurn(int y,int turn);
	void DrawRemainMine(int y, int mine);
	void DrawTable(int width, int height, int x, int y);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

	Draw();
	~Draw();
};

