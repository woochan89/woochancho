#include "Draw.h"



Draw::Draw()
{
	m_iWidth = 40;
	m_iHeight = 40;
}

void Draw::ErasePoint(int x, int y)
{
	gotoxy(x * 2, y);
	cout << "  ";
	gotoxy(-1, -1);
	return;
}

void Draw::DrawPoint(string str, int x, int y)
{
	gotoxy(x * 2, y);
	cout << str;
	gotoxy(-1, -1);
	return;
}

void Draw::DrawNum(int Num, int x, int y)
{
	gotoxy(x * 2, y);
	cout << Num;
	gotoxy(-1, -1);
	return;
}

void Draw::DrawMidText(string str, int x, int y)
{
	if (x > str.size() / 2)
		x -= str.size() / 2;
	gotoxy(x, y);
	cout << str;
	gotoxy(x + str.length(), y);
	return;
}
void Draw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void Draw::DrawBox()
{
	for (int height = 0; height < HEIGHT; height++)
	{
		for (int width = 0; width < WIDTH; width++)
		{
			gotoxy(width*2 , height);
			if (height == 0)
			{
				if (width == 0)
					cout << "┌";
				else if (width == WIDTH - 1)
					cout << "┐";
				else
					cout << "─";
			}
			else if (height == HEIGHT - 1)
			{
				if (width == 0)
					cout << "└";
				else if (width == WIDTH - 1)
					cout << "┘";
				else
					cout << "─";
			}
			else
			{
				if (width == 0)
					cout << "│";
				else if(width ==WIDTH-1)
					cout << "│";
			}
		}
	}
}

int Draw::DrawCursor(int Volume, int StartX, int StartY)
{
	int Y = StartY;
	char ch;

	DrawPoint("▷", StartX, Y);
	while (1)
	{
		if (ch = getch())
		{
			ErasePoint(StartX, Y);//기존 커서 지우기
			switch (ch)
			{
			case 'w':
				if (Y > StartY)
					Y -= 2;
				break;
			case 's':
				if (Y+2 < StartY + (Volume * 2))
					Y += 2;
				break;
			case 13://엔터
				return ((Y - StartY)*0.5) + 1;
			}
			DrawPoint("▷", StartX, Y);
		}
	}
}

Draw::~Draw()
{
}
