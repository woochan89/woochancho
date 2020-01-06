#include "Draw.h"



Draw::Draw()
{
}

void Draw::DrawPoint(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void Draw::ErasePoint(int x, int y)
{
	gotoxy(x, y);
	cout << "  ";
}


void Draw::DrawMidText(string str, int width, int y)
{
	gotoxy((width - str.length()*0.5), y);
	cout << str;
}

int Draw::DrawArrow(int x, int y, int max, int space)
{
	char ch;
	int Num = 1;
	DrawPoint("▷", x, y);
	while (true)
	{
		if (kbhit())
		{
			ch = getch();
			if (ch == 'w' || ch == 's' || ch == 13)
			{
				ErasePoint(x, y + (Num - 1)*space);
				switch (ch)
				{
				case 'w':
					if (Num != 1)
						Num--;
					break;
				case 's':
					if (Num != max)
						Num++;
					break;
				case 13:
					return Num;
				}
				DrawPoint("▷", x, y + (Num - 1)*space);
			}
		}
	}
}

void Draw::DrawBox(int width, int height,int x,int y)
{
	if (x == NULL && y == NULL)
	{
		x = width * 0.5;
		y = height * 0.5;
	}

	for (int extra_y = 0; extra_y < height; extra_y++)
	{
		for (int extra_x = 0; extra_x < width; extra_x++)
		{
			gotoxy((x - (width * 0.5) + extra_x)*2, y - (height * 0.5) + extra_y);
			if (extra_y == 0 && extra_x == 0)
				cout << "┌";
			else if (extra_y == 0 && (extra_x != 0 && extra_x != width - 1))
				cout << "─";
			else if (extra_y == 0 && extra_x == width - 1)
			{
				cout << "┐";
				break;
			}
			if ((extra_y != 0 && extra_y != height-1) && extra_x == 0)
				cout << "│";
			else if ((extra_y != 0 && extra_y != height - 1) && (extra_x != 0 && extra_x != width - 1))
				cout << "  ";
			else if ((extra_y != 0 && extra_y != height - 1) && extra_x == width-1)
			{
				cout << "│";
				break;
			}
			if (extra_y == height-1 && extra_x == 0)
				cout << "└";
			else if (extra_y == height - 1 && (extra_x != 0 && extra_x != width - 1))
				cout << "─";
			else if (extra_y == height - 1 && extra_x == width - 1)
			{
				cout << "┘";
				break;
			}
		}
	}
}

void Draw::DrawMidTextWithBox(string str, int width, int y)
{
	DrawBox(str.length(), 3, width*0.5, y+1);
	DrawMidText(str, width, y);
}

void Draw::DrawInterface(int width,int y,int level,int mine)
{
	string Level;
	if (level == EASY)
	Level = "초 급";
	else if (level == NOMAL)
	Level = "중 급";
	else
	Level = "고 급";

	DrawMidText("< 조 작 >", width, y);
	gotoxy(15, y + 1);
	cout << "W A S D : 조작";
	gotoxy(25, y + 1);
	cout << "ENTER : 확인";
	gotoxy(15, y + 2);
	cout << "난이도 : " << Level;
	DrawTurn(y+2,0);
	DrawRemainMine(y + 2, mine);
}

void Draw::DrawTurn(int y,int turn)
{
	gotoxy(30, y);
	cout << "턴 : " << turn;
}

void Draw::DrawRemainMine(int y, int mine)
{
	gotoxy(60, y);
	cout << "남은지뢰 : " << mine;
}

void Draw::DrawTable(int width, int height, int x, int y)
{
	for (int Y = y; Y < y+height; Y++)
	{
		for (int X = x; X < x+width; X++)
		{
			gotoxy(X * 2, Y);
			cout << "■";
		}
	}
}

Draw::~Draw()
{
}
