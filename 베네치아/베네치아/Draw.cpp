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
	gotoxy(0, HEIGHT);
	return;
}

void Draw::TextDraw(string str, int x, int y)
{
	gotoxy(x, y);
	cout << str;
}

void Draw::DrawTextWithBox(string str, int x, int y)
{
	DrawMidText(str,x,y);
	DrawSmallBox((x*0.5)-(str.size()*0.5)-1,y-1,str.size()+2,3);
	gotoxy(0, HEIGHT);
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

void Draw::DrawSmallBox(int x, int y, int Width, int Height)
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			gotoxy((x+j) * 2, y+i);
			if (i == 0)
			{
				if (j == 0)
					cout << "┌";
				else if (j == Width - 1)
					cout << "┐";
				else
					cout << "─";
			}
			else if (i == Height - 1)
			{
				if (j == 0)
					cout << "└";
				else if (j == Width - 1)
					cout << "┘";
				else
					cout << "─";
			}
			else
			{
				if (j == 0)
					cout << "│";
				else if (j == Width - 1)
					cout << "│";
			}
		}
	}
}

int Draw::DrawCursor(int Volume, int StartX, int StartY,int Space)
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
					Y -= Space;
				break;
			case 's':
				if (Y+Space < StartY + (Volume * Space))
					Y += Space;
				break;
			case 13://엔터
				return ((Y - StartY)/Space) + 1;
			}
			DrawPoint("▷", StartX, Y);
		}
	}
}

void Draw::DrawHeart(int Heart)
{
	gotoxy(1, HEIGHT + 2);
	cout << "Life : ";
	for (int i = 0; i < Heart; i++)
	 cout << "♥";
	cout << "                  ";
}

void Draw::DrawScore(int Score)
{
	gotoxy(WIDTH*0.5 - 3, HEIGHT + 2);
	cout << "Score : " << Score<<"  ";
}

void Draw::DrawName(string Name)
{
	gotoxy(WIDTH - 15, HEIGHT + 2);
	cout << "Name : " << Name<<"      ";
}

void Draw::Drawinterface()
{
	system("cls");
	DrawBox();
	DrawHeart();
	DrawScore();
	DrawName();
}

Draw::~Draw()
{
}
