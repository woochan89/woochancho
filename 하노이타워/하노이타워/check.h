#pragma once
#include"mecro.h"

class Check
{
private:
	int m_iStoneMax;
public:
	void findstone(int target, int *tower[],int *tNum,int *sNum);
	int checkstone(int *tower[],int tNum, int sNum);
	int checktower(int *tower[], int tNum, int sNum);//�� �������� ���� ���� �����
	int findtowertopstone(int *tower[], int tNum);//�ش� ����� ���� �����ִ� �� ã�� �Լ� �����ߵ�,��� ���° ��ġ�� �ִ��� Ȯ���ϰ� ���� �����̸� Ư���� ��ȯ�ϰ� �ϱ�

	Check(int stonemax);
	~Check();
};

