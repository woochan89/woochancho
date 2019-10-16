#include "Play.h"
#include"mecro.h"



Play::Play()
{
}

void Play::Setting(int level, int width, int height)
{

	if (level == EASY)
	{
		m_iMineMax = 10;
		m_iX = 1;
		m_iY = 1;
	}
	else if (level == NOMAL)
	{
		m_iMineMax = 40;
	}
	else if (level == HARD)
	{
		m_iMineMax = 99;
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			m_iTable[i][j] = NULL;
			m_iLiveTable[i][j] = BLOCK;
		}
	}
	m_iBlankMax = width * height - m_iMineMax;
	MakeMine(level, width, height);
	TableSetting();
	Drawmanager.DrawTable(width, height,m_iX+1,m_iY+1);
	m_iCursorX = width * 0.5;
	m_iCursorY = height * 0.5;
	Drawmanager.DrawPoint("��", (m_iCursorX+m_iX) * 2, m_iCursorY+m_iY);
}

void Play::MakeMine(int level,int x,int y)
{
	bool flag=true;
	m_mList = new Mine[m_iMineMax];

	for (int i=0;i< m_iMineMax;i++)
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

void Play::TableSetting(int x, int y)
{
	int X, Y;
	for (int i = 0; i < m_iMineMax; i++)
	{
		m_iTable[m_mList[i].X][m_mList[i].Y] = MINE;
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (m_iTable[i][j] == MINE)
			{
				for (int k = 0; k < 8; k++)
				{
					if (k == 0)
					{
						X = i - 1;
						Y = j;
					}
					else if (k == 1) 
					{
						X = i + 1;
						Y = j;
					}
					else if (k == 2)
					{
						X = i - 1;
						Y = j - 1;
					}
					else if (k == 3)
					{
						X = i;
						Y = j - 1;
					}
					else if (k == 4)
					{
						X = i + 1;
						Y = j - 1;
					}
					else if (k == 5)
					{
						X = i - 1;
						Y = j + 1;
					}
					else if (k == 6)
					{
						X = i;
						Y = j+1;
					}
					else if (k == 7)
					{
						X = i + 1;
						Y = j + 1;
					}
					if (m_iTable[X][Y] == MINE || X < 0 || Y < 0 || X>8 || Y>8)
						continue;
					m_iTable[X][Y]++;
				}
			}
		}
	}
}

int Play::ControlCursor(int width, int height, int x, int y)
{
	char ch;
	int Num = 1;
	while (true)
	{
		if (kbhit())
		{
			ch = getch();
			if (ch == 13)
			{
				return ch;
			}
			if (ch == 32)
			{
				if (m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1] == BLOCK)
				{
					Drawmanager.DrawPoint("��", (m_iCursorX + m_iX) * 2, m_iCursorY + m_iY);
					m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1] = FLAG;
				}
				else if (m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1] == FLAG)
				{
					Drawmanager.DrawPoint("��", (m_iCursorX + m_iX) * 2, m_iCursorY + m_iY);
					m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1] = BLOCK;
				}
			}
			if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
			{
				Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[m_iCursorX - 1]
					[m_iCursorY - 1]),(m_iCursorX+m_iX)*2, m_iCursorY+m_iY);
				switch (ch)
				{
				case 'w':
					if(m_iCursorY>y)
					m_iCursorY--;
					break;
				case 'a':
					if (m_iCursorX > x)
						m_iCursorX--;
					break;
				case 's':
					if (m_iCursorY < height)
					m_iCursorY++;
					break;
				case 'd':
					if (m_iCursorX < width)
					m_iCursorX++;
					break;
				}
				Drawmanager.DrawPoint("��", (m_iCursorX+ m_iX)*2, m_iCursorY+ m_iY);
			}
		}
	}
}

string Play::DrawAssist(int X)
{
	if (X == NULL)
		return "��";
	else if (X == 1)
		return"��";
	else if (X == 2)
		return"��";
	else if (X == 3)
		return"��";
	else if (X == 4)
		return"��";
	else if (X == 5)
		return"��";
	else if (X == 6)
		return"��";
	else if (X == 7)
		return"��";
	else if (X == 8)
		return"��";
	else if (X == MINE)
		return"��";
	else if (X == BLOCK)
		return"��";
	else if (X == FLAG)
		return"��";
}

bool Play::CheckBlock()
{
	m_iBlankMax--;
	m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1] 
		= m_iTable[m_iCursorX - 1][m_iCursorY - 1];
	Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1]), m_iCursorX*2, m_iCursorY);
	if (m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1] == MINE)
		return false;
	if (m_iLiveTable[m_iCursorX - 1][m_iCursorY - 1] == NULL)
	{
		BlankCheck(m_iCursorX - 1, m_iCursorY - 1);
	}
	return true;
}

void Play::BlankCheck(int x,int y)
{
	int X = x;
	int Y = y;
	if (m_iTable[X + 1][Y] == NULL && m_iLiveTable[X + 1][Y] != NULL&&X+1!=9)
	{
		m_iLiveTable[X + 1][Y] = NULL;
		Drawmanager.DrawPoint("��", (X + 1+1)*2, Y+1);
		m_iBlankMax--;
		BlankCheck(X + 1, Y);
	}
	if (m_iTable[X - 1][Y] == NULL && m_iLiveTable[X - 1][Y] != NULL&&X-1!=-1)
	{
		m_iLiveTable[X - 1][Y] = NULL;
		Drawmanager.DrawPoint("��", (X - 1+1)*2, Y+1);
		m_iBlankMax--;
		BlankCheck(X - 1, Y);
	}
	if (m_iTable[X][Y + 1] == NULL && m_iLiveTable[X][Y + 1] != NULL&&Y+1!=9)
	{
		m_iLiveTable[X][Y + 1] = NULL;
		Drawmanager.DrawPoint("��", (X+1)*2, Y + 1+1);
		m_iBlankMax--;
		BlankCheck(X, Y + 1);
	}
	if (m_iTable[X][Y - 1] == NULL && m_iLiveTable[X][Y - 1] != NULL&&Y-1!=-1)
	{
		m_iLiveTable[X][Y - 1] = NULL;
		Drawmanager.DrawPoint("��", (X+1)*2, Y - 1+1);
		m_iBlankMax--;
		BlankCheck(X, Y - 1);
	}

}

bool Play::WinCheck()
{
	if (m_iBlankMax <= 10)
		return false;
	if (m_iBlankMax==1)
		return true;
	return false;
}

void Play::Reset()
{

}

Play::~Play()
{
}