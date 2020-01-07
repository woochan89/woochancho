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
		m_iX = 1;
		m_iY = 1;
	}
	else if (level == HARD)
	{
		m_iMineMax = 99;
		m_iX = 1;
		m_iY = 1;
	}
	m_iTable = new int*[height];
	m_iLiveTable = new int*[height];
	for (int i = 0; i < height; i++)
	{
		m_iTable[i] = new int[width];
		m_iLiveTable[i] = new int[width];
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
	TableSetting(width,height);
	Drawmanager.DrawTable(width, height,m_iX,m_iY);
	m_iCursorX = width * 0.5;
	m_iCursorY = height * 0.5;
	Drawmanager.DrawPoint("▣", (m_iCursorX+m_iX) * 2, m_iCursorY+m_iY);
}

void Play::MakeMine(int level,int width,int height)
{
	bool flag=true;
	m_mList = new Mine[m_iMineMax];

	for (int i=0;i< m_iMineMax;i++)
	{
		m_mList[i].X = rand() % width;
		m_mList[i].Y = rand() % height;
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

void Play::TableSetting(int width, int height, int x, int y)
{
	int X, Y;
	for (int i = 0; i < m_iMineMax; i++)
	{
		m_iTable[m_mList[i].Y][m_mList[i].X] = MINE;
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
					if (m_iTable[X][Y] == MINE || X < 0 || Y < 0 || X>=width || Y>=height)//여기서 오류발생
						continue;
					m_iTable[X][Y]++;
				}
			}
		}
	}
}

int Play::ControlCursor(int width, int height, int *mine, int x, int y)
{
	char ch;
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
				if (m_iLiveTable[m_iCursorX][m_iCursorY] == BLOCK && *mine > 0)
				{
					Drawmanager.DrawPoint("¶", (m_iCursorX + m_iX) * 2, m_iCursorY + m_iY);
					m_iLiveTable[m_iCursorX ][m_iCursorY] = FLAG;
					Drawmanager.DrawRemainMine(HEIGHT + 3, --(*mine));
				}
				else if (m_iLiveTable[m_iCursorX][m_iCursorY] == FLAG)
				{
					Drawmanager.DrawPoint("■", (m_iCursorX + m_iX) * 2, m_iCursorY + m_iY);
					m_iLiveTable[m_iCursorX][m_iCursorY] = BLOCK;
					Drawmanager.DrawRemainMine(HEIGHT + 3, ++(*mine));
				}
			}
			if (ch == 'w' || ch == 'a' || ch == 's' || ch == 'd')
			{
				Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[m_iCursorX]
					[m_iCursorY]),(m_iCursorX+m_iX)*2, m_iCursorY+m_iY);
				switch (ch)
				{
				case 'w':
					if(m_iCursorY >= x)
					m_iCursorY--;
					break;
				case 'a':
					if (m_iCursorX >= y)
						m_iCursorX--;
					break;
				case 's':
					if (m_iCursorY < height-1)
					m_iCursorY++;
					break;
				case 'd':
					if (m_iCursorX < width-1)
					m_iCursorX++;
					break;
				}
				Drawmanager.DrawPoint("▣", (m_iCursorX+ m_iX)*2, m_iCursorY+ m_iY);
			}
		}
	}
}

string Play::DrawAssist(int X)
{
	if (X == NULL)
		return "□";
	else if (X == 1)
		return"①";
	else if (X == 2)
		return"②";
	else if (X == 3)
		return"③";
	else if (X == 4)
		return"④";
	else if (X == 5)
		return"⑤";
	else if (X == 6)
		return"⑥";
	else if (X == 7)
		return"⑦";
	else if (X == 8)
		return"⑧";
	else if (X == MINE)
		return"★";
	else if (X == BLOCK)
		return"■";
	else if (X == FLAG)
		return"¶";
}

bool Play::CheckBlock(int width,int height)
{
	m_iLiveTable[m_iCursorX][m_iCursorY] 
		= m_iTable[m_iCursorX][m_iCursorY];
	Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[m_iCursorX][m_iCursorY]), (m_iCursorX+m_iX)*2, m_iCursorY+m_iY);//판에 그리기
	if (m_iLiveTable[m_iCursorX][m_iCursorY] == MINE)//지뢰면 0반환
		return false;
	if (m_iLiveTable[m_iCursorX][m_iCursorY] == NULL)//지뢰가 아니면 BlankCheck로
	{
		BlankCheck(width, height,m_iCursorX, m_iCursorY);
	}
	return true;
}

void Play::BlankCheck(int width, int height,int x,int y)//빈칸 선택시 주변 빈칸 전부 확인후 밝히기, 대각선 체크필요
{
	bool flagR = 0, flagL = 0, flagU = 0, flagD = 0;
	if (m_iLiveTable[x + 1][y] != NULL && x + 1 != width/*원래 9였음 작동 확인요*/)
	{
		if (m_iTable[x + 1][y] != NULL)
		{
			m_iLiveTable[x + 1][y] = m_iTable[x + 1][y];
			Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x+1][y]), (x + 1 + m_iX) * 2, y + m_iY);
			flagR = true;
		}
		else
		{
			m_iLiveTable[x + 1][y] = NULL;
			Drawmanager.DrawPoint("□", (x + 1 + m_iX) * 2, y + m_iY);
			BlankCheck(width,height,x + 1, y);
		}
	}
	if (m_iLiveTable[x - 1][y] != NULL&&x-1!=-1)
	{
		if (m_iTable[x - 1][y] != NULL)
		{
			m_iLiveTable[x - 1][y] = m_iTable[x - 1][y];
			Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x - 1][y]), (x - 1 + m_iX) * 2, y + m_iY);
			flagL = true;
		}
		else
		{
			m_iLiveTable[x - 1][y] = NULL;
			Drawmanager.DrawPoint("□", (x - 1 + m_iX) * 2, y + m_iY);
			BlankCheck(width, height, x - 1, y);
		}
	}
	if (m_iLiveTable[x][y + 1] != NULL&&y+1!=height)
	{
		if (m_iTable[x][y + 1] != NULL)
		{
			m_iLiveTable[x][y+1] = m_iTable[x][y+1];
			Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x][y+1]), (x+ m_iX) * 2, y +1+ m_iY);
			flagD = true;
		}
		else
		{
			m_iLiveTable[x][y + 1] = NULL;
			Drawmanager.DrawPoint("□", (x + m_iX) * 2, y + 1 + m_iY);
			BlankCheck(width, height, x, y + 1);
		}
	}
	if (m_iLiveTable[x][y - 1] != NULL&&y-1!=-1)
	{
		if (m_iTable[x][y - 1] != NULL)
		{
			m_iLiveTable[x][y - 1] = m_iTable[x][y - 1];
			Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x][y - 1]), (x + m_iX) * 2, y - 1 + m_iY);
			flagU = true;
		}
		else
		{
			m_iLiveTable[x][y - 1] = NULL;
			Drawmanager.DrawPoint("□", (x + m_iX) * 2, y - 1 + m_iY);
			BlankCheck(width, height, x, y - 1);
		}
	}
	bool diagonalFlag=FALSE;
	if (flagR == true && flagU == true && m_iTable[x + 1][y - 1] != MINE)//대각선 체크
	{
		m_iLiveTable[x + 1][y - 1] = m_iTable[x + 1][y - 1];
		Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x + 1][y - 1]), (x + 1 + m_iX) * 2, y - 1 + m_iY);
		if (m_iLiveTable[x + 1][y - 1] == NULL)//대각선 위치가 빈공간일때 함수 재진입
		{BlankCheck(width, height, x + 1, y - 1);}
	}
	if (flagR == true && flagD == true && m_iTable[x + 1][y + 1] != MINE)
	{
		m_iLiveTable[x + 1][y + 1] = m_iTable[x + 1][y + 1];
		Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x + 1][y + 1]), (x + 1 + m_iX) * 2, y + 1 + m_iY);
		if (m_iLiveTable[x + 1][y + 1] == NULL)
		{BlankCheck(width, height, x + 1, y + 1); }
	}
	if (flagL == true && flagU == true && m_iTable[x - 1][y - 1] != MINE)
	{
		m_iLiveTable[x - 1][y - 1] = m_iTable[x - 1][y - 1];
		Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x - 1][y - 1]), (x - 1 + m_iX) * 2, y - 1 + m_iY);
		if (m_iLiveTable[x - 1][y - 1] == NULL)
		{BlankCheck(width, height, x - 1, y - 1);}

	}
	if (flagL == true && flagD == true && m_iTable[x - 1][y + 1] != MINE)
	{
		m_iLiveTable[x - 1][y + 1] = m_iTable[x - 1][y + 1];
		Drawmanager.DrawPoint(DrawAssist(m_iLiveTable[x - 1][y + 1]), (x - 1 + m_iX) * 2, y + 1 + m_iY);
		if (m_iLiveTable[x - 1][y + 1] == NULL)
		{BlankCheck(width, height, x - 1, y + 1);}
	}

}

bool Play::WinCheck(int width,int height)
{
	int num = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (m_iLiveTable[x][y] != BLOCK&& m_iLiveTable[x][y] != FLAG)
				num++;
			if (num == m_iBlankMax)
				return true;
		}
	}
	return false;
}

void Play::Reset(int height)
{
	delete[] m_mList;//지뢰 할당해제
	for (int i = 0; i < height; i++)//테이블 할당해제
	{
		delete[] m_iTable[i];
		delete[] m_iLiveTable[i];

	}
	delete[] m_iTable;
	delete[] m_iLiveTable;
}

Play::~Play()
{
}