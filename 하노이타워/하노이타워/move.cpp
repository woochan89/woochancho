#include "Move.h"



Move::Move()
{
}


void Move::movestone(int target,int *tower[],int sNum,int tNum)
{
	int TargetTower[2];

	if (tNum == DEFAULT)//함수 첫 진입일때 원하는 타겟의 위치 찾기
		checkmanager.findstone(target, tower, &m_itNum, &m_isNum);

	while (tower[m_itNum][m_isNum + 1] != 0)//동적할당 범위 초과로 오류 위험
	{
		m_isNum = checkmanager.checkstone(tower, m_itNum, m_isNum);//타겟돌이 움직일수있는 상태인지 확인
		movestone(tower[m_itNum][m_isNum], tower, sNum, tNum);//타겟돌을 움직이기
	}
	int movetower = checkmanager.checktower(tNum,target);


	if (movetower == -1)
	{
		if (checkmanager.checktower(tNum, tower[tNum][sNum]) == -1)//타겟 돌을 옮길 다른 기둥이 있는지 확인해보고

		{
			if (tower[1][FindTowerTopStone(1)] > tower[2][FindTowerTopStone(2)])//해당 기둥의 제일 위에있는 돌 찾는 함수 만들어야됨
			{
				tower[1][1] = tower[2][0];
				tower[2][0] = NULL;
				cout << tNum + 1 << "번 기둥의 " << tower[movetower][0] << "번 돌을 " << MoveTower + 1 << "번 기둥으로 이동" << endl;
			}
			else
			{
				tower[2][1] = tower[1][0];
				tower[1][0] = NULL;
				cout << tNum + 1 << "번 기둥의 " << tower[movetower][0] << "번 돌을 " << MoveTower + 1 << "번 기둥으로 이동" << endl;
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
				cout << tNum + 1 << "번 기둥의 " << tower[tNum][sNum] << "번 돌을 " << TargetTower[1] + 1 << "번 기둥으로 이동" << endl;
				tower[tNum][sNum] = NULL;
			}
		}
	}
	else
	{
		tower[MoveTower][0] = tower[tNum][sNum];
		tower[tNum][sNum] = NULL;

		cout << tNum + 1 << "번 기둥의 " << tower[MoveTower][0] << "번 돌을 " << MoveTower + 1 << "번 기둥으로 이동" << endl;
	}
}


Move::~Move()
{
}
