#pragma once
#include"mecro.h"

class Check
{
private:
	int m_iStoneMax;
public:
	void findstone(int target, int *tower[],int *tNum,int *sNum);
	int checkstone(int *tower[],int tNum, int sNum);
	int checktower(int *tower[], int tNum, int sNum);//총 돌갯수에 따라 변수 만들기
	int findtowertopstone(int *tower[], int tNum);//해당 기둥의 제일 위에있는 돌 찾는 함수 만들어야됨,기둥 몇번째 위치에 있는지 확인하고 제일 위쪽이면 특정값 반환하게 하기

	Check(int stonemax);
	~Check();
};

