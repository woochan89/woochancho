#include "Move.h"



Move::Move(int stonemax)
{
	m_itNum = 0;
	m_isNum = 0;
	checkmanager = new Check(stonemax);
}

void Move::controlstone(int target, int *tower[], int sNum, int tNum, int targettower)//Ȯ���غ���
{
	int TargetTower[2];
	int movetower = targettower;
	int tnum, snum;

	checkmanager->findstone(tower[tNum][sNum], tower, &tnum, &snum);

	if (tower[tNum][sNum + 1] != 0)//�����Ҵ� ���� �ʰ��� ���� ����
	{
		//m_isNum = checkmanager.checkstone(tower, m_itNum, m_isNum);Ÿ�ٵ��� �����ϼ��ִ� �������� Ȯ��
		movestone(tower[tNum][sNum + 1], tower, sNum, tNum);//Ÿ�ٵ��� �����̱�
	}

}

void Move::movestone(int target,int *tower[],int sNum,int tNum,int targettower)
{
	int TargetTower[2];
	int movetower=targettower;
	int tnum,snum;

	checkmanager->findstone(tower[tNum][sNum],tower, &tnum, &snum);

	if (tower[tNum][sNum + 1] != 0)//�����Ҵ� ���� �ʰ��� ���� ����
	{
		//m_isNum = checkmanager.checkstone(tower, m_itNum, m_isNum);Ÿ�ٵ��� �����ϼ��ִ� �������� Ȯ��
		movestone(tower[tNum][sNum + 1], tower, sNum, tNum);//Ÿ�ٵ��� �����̱�
	}
	if(targettower!=-2)
		movetower = checkmanager->checktower(tower, tNum, sNum);
	int movestone = checkmanager->findtowertopstone(tower, movetower);


	if (movetower == -1)
	{

		//Ÿ�ٵ��� �ִ� ��� ���� ������ �ε��� ũ�⸦ ���ϰ� 
		//���ϴ� �ڸ� ������ �ٸ� ������� �ű��
		//


		if (checkmanager->checktower(tNum, tower[tNum][sNum]) == -1)//Ÿ�� ���� �ű� �ٸ� ����� �ִ��� Ȯ���غ���

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
		tower[movetower][movestone] = tower[tNum][sNum];
		tower[tNum][sNum] = NULL;

		cout << tNum + 1 << "�� ����� " << tower[movetower][movestone] << "�� ���� " << movetower + 1 << "�� ������� �̵�" << endl;
	}
}


Move::~Move()
{
}
