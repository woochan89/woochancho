#pragma once
#include"Check.h"
#define DEFAULT 4
class Move
{
private:
	Check *checkmanager;
	int m_itNum;
	int m_isNum;
	int m_iStoneMax;
public:
	void TowerMove(int Num, char from='A', char by='B', char to='C');

	void controlstone(int target, int *tower[]);
	void movestone(int target, int *tower[], int evade = -2,int sNum = 0,int tNum = 0);

	Move(int stonemax);
	~Move();
};

