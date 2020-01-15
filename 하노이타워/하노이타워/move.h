#pragma once
#include"Check.h"
#define DEFAULT 4
class Move
{
private:
	Check *checkmanager;
	int m_itNum;
	int m_isNum;
public:
	void controlstone(int target, int *tower[], int sNum = 0, int tNum = 0, int targettower = -2);
	void movestone(int target, int *tower[],int sNum = 0,int tNum = 0,int targettower=-2);

	Move(int stonemax);
	~Move();
};

