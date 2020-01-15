#include "Move.h"



Move::Move(int stonemax)
{
	m_itNum = 0;
	m_isNum = 0;
	checkmanager = new Check(stonemax);
}

void Move::controlstone(int target, int *tower[], int sNum, int tNum, int targettower)//확인해보기
{
	int TargetTower[2];
	int movetower = targettower;
	int tnum, snum;

	checkmanager->findstone(tower[tNum][sNum], tower, &tnum, &snum);

	if (tower[tNum][sNum + 1] != 0)//동적할당 범위 초과로 오류 위험
	{
		//m_isNum = checkmanager.checkstone(tower, m_itNum, m_isNum);타겟돌이 움직일수있는 상태인지 확인
		movestone(tower[tNum][sNum + 1], tower, sNum, tNum);//타겟돌을 움직이기
	}

}

void Move::movestone(int target,int *tower[],int sNum,int tNum,int targettower)
{
	int TargetTower[2];
	int movetower=targettower;
	int tnum,snum;

	checkmanager->findstone(tower[tNum][sNum],tower, &tnum, &snum);

	if (tower[tNum][sNum + 1] != 0)//동적할당 범위 초과로 오류 위험
	{
		//m_isNum = checkmanager.checkstone(tower, m_itNum, m_isNum);타겟돌이 움직일수있는 상태인지 확인
		movestone(tower[tNum][sNum + 1], tower, sNum, tNum);//타겟돌을 움직이기
	}
	if(targettower!=-2)
		movetower = checkmanager->checktower(tower, tNum, sNum);
	int movestone = checkmanager->findtowertopstone(tower, movetower);


	if (movetower == -1)
	{

		//타겟돌이 있는 기둥 제외 나머지 두돌의 크기를 비교하고 
		//원하는 자리 제외한 다른 기둥으로 옮기기
		//


		if (checkmanager->checktower(tNum, tower[tNum][sNum]) == -1)//타겟 돌을 옮길 다른 기둥이 있는지 확인해보고

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
		tower[movetower][movestone] = tower[tNum][sNum];
		tower[tNum][sNum] = NULL;

		cout << tNum + 1 << "번 기둥의 " << tower[movetower][movestone] << "번 돌을 " << movetower + 1 << "번 기둥으로 이동" << endl;
	}
}


Move::~Move()
{
}
