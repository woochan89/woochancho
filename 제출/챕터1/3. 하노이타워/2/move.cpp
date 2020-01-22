#include "move.h"

Move::Move(int Num)
{
	m_iStoneMax = Num;
	m_iLine = 1;
	drawmanager=new draw(Num);

	for (int i = 0; i < 3; i++)
	{
		m_iTower[i] = new int[Num];
		for (int j = 0; j < Num; j++)
		{
			if (i == 0)
				m_iTower[i][j] = Num - j;
			else
				m_iTower[i][j] = 0;
		}
	}
	drawmanager->DrawTower(m_iTower);
	TowerMove(Num);
}

void Move::TowerMove(int Num, int from, int by, int to)
{
	if (Num == 1)
	{
		MoveStone(Num, from, to);
		drawmanager->gotoxy(0, m_iLine++);
		cout << Num << "번 돌을 " << from+1 << "번 기둥에서 " << to+1 << "번 기둥으로 이동" << endl;
		Sleep(300);
	}
	else
	{
		TowerMove(Num - 1, from, to, by);
		MoveStone(Num, from, to);
		drawmanager->gotoxy(0, m_iLine++);
		cout << Num << "번 돌을 " << from+1 << "번 기둥에서 " << to+1 << "번 기둥으로 이동" << endl;
		Sleep(300);
		TowerMove(Num - 1, by, from, to);
	}
}

void Move::MoveStone(int Num, int from, int to)
{
	int tNum1 = FindTowerTopStone(m_iTower, to);
	int tNum2 = FindTarget(Num, from);

	m_iTower[to][tNum1] = m_iTower[from][tNum2];
	m_iTower[from][tNum2] = NULL;
	drawmanager->EraseStone(from, tNum2);
	drawmanager->DrawStone(m_iTower, to, tNum1);
}


int Move::FindTowerTopStone(int *tower[], char tNum)
{
	int num = 0;

	while (tower[tNum][num] != 0)
	{
		num++;
		if (num > m_iStoneMax - 1)
			return -1;
	}
	return num;
}

int Move::FindTarget(int target, int tNum)
{
	for (int i = 0; i < m_iStoneMax; i++)
	{
		if (m_iTower[tNum][i] == target)
			return i;
	}
}

Move::~Move()
{
	for (int i = 0; i < 3; i++)
		delete[] m_iTower[i];

	delete drawmanager;
}
