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
	DrawPoint("¢¹", x, y);
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
				DrawPoint("¢¹", x, y + (Num - 1)*space);
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
				cout << "¦£";
			else if (extra_y == 0 && (extra_x != 0 && extra_x != width - 1))
				cout << "¦¡";
			else if (extra_y == 0 && extra_x == width - 1)
			{
				cout << "¦¤";
				break;
			}
			if ((extra_y != 0 && extra_y != height-1) && extra_x == 0)
				cout << "¦¢";
			else if ((extra_y != 0 && extra_y != height - 1) && (extra_x != 0 && extra_x != width - 1))
				cout << "  ";
			else if ((extra_y != 0 && extra_y != height - 1) && extra_x == width-1)
			{
				cout << "¦¢";
				break;
			}
			if (extra_y == height-1 && extra_x == 0)
				cout << "¦¦";
			else if (extra_y == height - 1 && (extra_x != 0 && extra_x != width - 1))
				cout << "¦¡";
			else if (extra_y == height - 1 && extra_x == width - 1)
			{
				cout << "¦¥";
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

Draw::~Draw()
{
}
