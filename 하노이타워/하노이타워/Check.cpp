#include "Check.h"



Check::Check(int stonemax)
{
	m_iStoneMax = stonemax;
}

void Check::findstone(int target, int *tower[],int *tNum,int *sNum)//���ϴ� �� ��ġ ã��
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


int Check::checktower(int *tower[],int tNum, int sNum)//�� �������� ���� ���� �����
{
	int Num[2];
	//�� ���� �ִٸ� �� ������ �켱 �̵�
	for (int i = 0,j = 0; i < 3; i++)
	{
		if (i == tNum)
			continue;
		Num[j++] = i;
	}
	
	int Tower[2][2] = {0};
	for (int i = 0, j = 0, k = 0; i < 3; i++)
	{
		if (i == tNum)
			continue;
		Tower[j][k] = i;
		Tower[j++][k+1]= findtowertopstone(tower, i);
	}


	if (tower[Num[0]][findtowertopstone(tower, Num[0])] == 0 || tower[Num[1]][findtowertopstone(tower, Num[1])] == 0)//���ڸ��� ������ ���ڸ��� �켱 �̵�
	{
		if (tower[Num[0]][findtowertopstone(tower, Num[0])] == 0)
		{
			return Num[0];
		}
		else if (tower[Num[1]][findtowertopstone(tower, Num[1])] == 0)
		{
			return Num[1];
		}
	}


	if (tower[tNum][sNum] < tower[Tower[0][0]][Tower[0][1]])
	{
		return Tower[0][0];
	}
	else if (tower[tNum][sNum] < tower[Tower[1][0]][Tower[1][1]])
	{
		return Tower[1][0];
	}
	else
		return -1;



	//�ٸ� �α�� ���� ���� �� ũ�⸦ ���Ͽ� ũ������ ���� ������ �̵�

	if (tower[Num[0]][findtowertopstone(tower, Num[0])]-tower[tNum][sNum] <= tower[Num[1]][findtowertopstone(tower, Num[1])] - tower[tNum][sNum])
	{
		return Num[0];
	}
	else
	{
		return Num[1];
	}

}


int Check::findtowertopstone(int *tower[], int tNum)//�ش� ����� ���� �����ִ� �� ã�� �Լ� �����ߵ�,��� ���° ��ġ�� �ִ��� Ȯ���ϰ� ���� �����̸� Ư���� ��ȯ�ϰ� �ϱ�
{
	int num = 0;

	while (tower[tNum][num] != 0)
	{
		num++;
		if (num > m_iStoneMax-1)
			return -1;
	}
	return num;
}

Check::~Check()
{
}
