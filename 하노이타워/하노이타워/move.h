#pragma once
#include"Check.h"
#define DEFAULT 4
class Move
{
private:
	Check checkmanager;
	int m_itNum;
	int m_isNum;
public:
	void movestone(int target, int *tower[],int sNum = DEFAULT,int tNum = DEFAULT);

	Move();
	~Move();
};

