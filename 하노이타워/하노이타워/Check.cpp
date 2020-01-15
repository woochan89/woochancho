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
	if (m_iStoneMax % 2 == 1)
	{
		//1�� ���� 3�� ������� ���� �̵�
	}

	int Tower[2][2] = {0};
	for (int i = 0, j = 0, k = 0; i < 3; i++)
	{
		if (i == tNum)
			continue;
		Tower[j][k] = i;
		Tower[j++][k+1]= findtowertopstone(tower, i);
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


	//if (tower[0][0] == NULL && tNum != 0)
	//	return 0;
	//if (tower[1][0] == NULL && tNum != 1)
	//	return 1;
	//if (tower[2][0] == NULL && tNum != 2)
	//	return 2;
	//return -1;
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
