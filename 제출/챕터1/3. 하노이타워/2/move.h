#pragma once
#include"draw.h"

class Move
{
private:
	int m_iStoneMax;
	int *m_iTower[3];
	int m_iLine;
	draw *drawmanager;

public:
	void TowerMove(int Num, int from = 0, int by = 1, int to = 2);
	void MoveStone(int Num, int from, int to);
	int FindTowerTopStone(int *tower[], char tNum);
	int FindTarget(int target, int tNum);

	Move(int Num);
	~Move();
};

