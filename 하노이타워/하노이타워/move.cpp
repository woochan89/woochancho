#include "Move.h"



Move::Move()
{
}


void Move::movestone(int target,int *tower[],int sNum,int tNum)
{
	int TargetTower[2];

	if (tNum == DEFAULT)//�Լ� ù �����϶� ���ϴ� Ÿ���� ��ġ ã��
		checkmanager.findstone(target, tower, &m_itNum, &m_isNum);

	while (tower[m_itNum][m_isNum + 1] != 0)//�����Ҵ� ���� �ʰ��� ���� ����
	{
		m_isNum = checkmanager.checkstone(tower, m_itNum, m_isNum);//Ÿ�ٵ��� �����ϼ��ִ� �������� Ȯ��
		movestone(tower[m_itNum][m_isNum], tower, sNum, tNum);//Ÿ�ٵ��� �����̱�
	}
	int movetower = checkmanager.checktower(tNum,target);


	if (movetower == -1)
	{
		if (checkmanager.checktower(tNum, tower[tNum][sNum]) == -1)//Ÿ�� ���� �ű� �ٸ� ����� �ִ��� Ȯ���غ���

		{
			if (tower[1][FindTowerTopStone(1)] > tower[2][FindTowerTopStone(2)])//�ش� ����� ���� �����ִ� �� ã�� �Լ� �����ߵ�
			{
				tower[1][1] = tower[2][0];
				tower[2][0] = NULL;
				cout << tNum + 1 << "�� ����� " << tower[movetower][0] << "�� ���� " << MoveTower + 1 << "�� ������� �̵�" << endl;
			}
			else
			{
				tower[2][1] = tower[1][0];
				tower[1][0] = NULL;
				cout << tNum + 1 << "�� ����� " << tower[movetower][0] << "�� ���� " << MoveTower + 1 << "�� ������� �̵�" << endl;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (tNum == i)
			{
				for (int j = 0, k = 0; j < 3; j++)
				{
					if (j != tNum)
						TargetTower[k++] = j;
				}
				if (tower[TargetTower[0]][0] == NULL)
				{
					tower[Targettower[0]][0] = tower[tNum][sNum];
				}
				else if (tower[TargetTower[1]][0] == NULL)
				{
					tower[TargetTower[1]][0] = tower[tNum][sNum];
				}
				cout << tNum + 1 << "�� ����� " << tower[tNum][sNum] << "�� ���� " << TargetTower[1] + 1 << "�� ������� �̵�" << endl;
				tower[tNum][sNum] = NULL;
			}
		}
	}
	else
	{
		tower[MoveTower][0] = tower[tNum][sNum];
		tower[tNum][sNum] = NULL;

		cout << tNum + 1 << "�� ����� " << tower[MoveTower][0] << "�� ���� " << MoveTower + 1 << "�� ������� �̵�" << endl;
	}
}


Move::~Move()
{
}
