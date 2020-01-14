#include "Check.h"



Check::Check()
{
	
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


int Check::checktower(int tNum, int stone)//�� �������� ���� ���� �����
{
	if (Tower[0][0] == NULL && tNum != 0)
		return 0;
	if (Tower[1][0] == NULL && tNum != 1)
		return 1;
	if (Tower[2][0] == NULL && tNum != 2)
		return 2;
	return -1;
}


int Check::findtowertopstone(int tower)//�ش� ����� ���� �����ִ� �� ã�� �Լ� �����ߵ�,��� ���° ��ġ�� �ִ��� Ȯ���ϰ� ���� �����̸� Ư���� ��ȯ�ϰ� �ϱ�
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
