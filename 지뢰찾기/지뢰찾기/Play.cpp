#include "Play.h"
#include"mecro.h"



Play::Play()
{
}

void Play::Setting(int level, int x, int y)
{
	MakeMine(level,x,y);
	Drawmanager.DrawTable(x, y);
	m_iCursorX = x * 0.5;
	m_iCursorY = y * 0.5;
}

void Play::MakeMine(int level,int x,int y)
{
	bool flag=true;
	int max;
	if (level == EASY)
		max = 10;
	else if (level == NOMAL)
		max = 40;
	else if (level == HARD)
		max = 99;
	m_mList = new Mine[max];

	for (int i=0;i<max;i++)
	{
		m_mList[i].X = rand() % x;
		m_mList[i].Y = rand() % y;
		for (int j = 0; j < i; j++)
		{
			if (m_mList[i].X == m_mList[j].X&&m_mList[i].Y == m_mList[j].Y)
			{
				flag = false;
				break;
			}
		}	
		if (flag == false)
		{
			flag = true;
			i--;
			continue;
		}
	}
}

void Play::ControlCursor(int x, int y)
{
	char ch;
	int Num = 1;
	Drawmanager.DrawPoint("бр", m_iCursorX, m_iCursorY);
	while (true)
	{
		if (kbhit())
		{
			ch = getch();
			if (ch == 'w' || ch == 's' || ch == 13)
			{
				Drawmanager.ErasePoint(x, y + (Num - 1)*space);
				switch (ch)
				{
				case 'w':
					if (Num != 1)
						Num--;
					break;
				case 'a':
					break;
				case 's':
					if (Num != max)
						Num++;
					break;
				case 'd':

					break;
				case 13:
					return Num;
				}
				Drawmanager.DrawPoint("в╣", x, y + (Num - 1)*space);
			}
		}
	}

}

void Play::CheckMine()
{
}

void Play::Reset()
{

}

Play::~Play()
{
}
