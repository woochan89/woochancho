#pragma once
#include"mecro.h"

class Check
{
private:
public:
	void findstone(int target, int *tower[],int *tNum,int *sNum);
	int checkstone(int *tower[],int tNum, int sNum);
	int checktower(int tNum, int stone);//�� �������� ���� ���� �����
	int findtowertopstone(int tower);//�ش� ����� ���� �����ִ� �� ã�� �Լ� �����ߵ�,��� ���° ��ġ�� �ִ��� Ȯ���ϰ� ���� �����̸� Ư���� ��ȯ�ϰ� �ϱ�

	Check();
	~Check();
};

