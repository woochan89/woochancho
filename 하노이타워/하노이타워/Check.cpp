#include "Check.h"



Check::Check()
{
	
}

void Check::findstone(int target, int *tower[],int *tNum,int *sNum)//원하는 돌 위치 찾기
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tower[i][j] == target)
			{
				*tNum = i;
				*sNum = j;
				return;
			}
		}
	}
}

int Check::checkstone(int *tower[],int tNum, int sNum)
{
	int movestonenum;
	if (sNum != 2)
	{
		if (tower[tNum][sNum + 1] != 0)
			movestonenum = checkstone(tower,tNum, sNum + 1);
	}
	else
		movestonenum = sNum;
	return movestonenum;
}


int Check::checktower(int tNum, int stone)//총 돌갯수에 따라 변수 만들기
{
	if (Tower[0][0] == NULL && tNum != 0)
		return 0;
	if (Tower[1][0] == NULL && tNum != 1)
		return 1;
	if (Tower[2][0] == NULL && tNum != 2)
		return 2;
	return -1;
}


int Check::findtowertopstone(int tower)//해당 기둥의 제일 위에있는 돌 찾는 함수 만들어야됨,기둥 몇번째 위치에 있는지 확인하고 제일 위쪽이면 특정값 반환하게 하기
{
	int num = 0;

	while (Tower[tower][num] != 0)
	{
		num++;
		if (num > 2)
			return -1;
	}
	return num;
}

Check::~Check()
{
}
