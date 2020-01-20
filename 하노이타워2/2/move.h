#pragma once
#include"draw.h"
#include <windows.h>

class Move
{
private:
	int m_iStoneMax;
	int *m_iTower[3];
	draw *drawmanager;

public:
	void TowerMove(int Num, int from = 0, int by = 0, int to = 0);
	void MoveStone(int Num, int from, int to);
	int FindTowerTopStone(int *tower[], char tNum);
	int FindTarget(int target, int tNum);

	Move(int Num);
	~Move();
};

