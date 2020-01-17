#include "Move.h"



Move::Move(int stonemax)
{
	m_itNum = 0;
	m_isNum = 0;
	m_iStoneMax = stonemax;
	checkmanager = new Check(stonemax);
}

void Move::controlstone(int target, int *tower[])
{
	int tnum, snum;

	checkmanager->findstone(target, tower, &tnum, &snum);

	movestone(tower[tnum][snum], tower, snum, tnum);

	tower[2][checkmanager->findtowertopstone(tower, 2)] = tower[tnum][snum];
	tower[tnum][snum] = NULL;
	cout << tnum + 1 << "번 기둥의 " << tower[2][checkmanager->findtowertopstone(tower, 2)] << "번 돌을 " << 3 << "번 기둥으로 이동" << endl;


}

void Move::movestone(int target,int *tower[], int evade, int sNum,int tNum)
{
	int TargetTower[2];
	int evadeL = -1;
	int MoveTower;

	if (tower[tNum][sNum + 1] != 0)//동적할당 범위 초과로 오류 위험
	{
		if (m_iStoneMax % 2 == 1 && target == 1 && tNum==0 && sNum == m_iStoneMax - 1)//1번 돌이 1번 기둥의 맨 위에 있을때 2번 기둥이 아닌 3번기둥으로 이동
			evadeL == 1;
		movestone(tower[tNum][sNum + 1], tower, evadeL, sNum, tNum);//타겟돌을 움직이기
	}

	MoveTower = checkmanager->checktower(tower, tNum, sNum);//회피할 자리 변수 만들어 넣기



	if (MoveTower == -1)
	{
		if(tNum==0)
		{
			if (tower[1][checkmanager->findtowertopstone(tower, 1)] > tower[2][checkmanager->findtowertopstone(tower, 2)])
				movestone(tower[1][checkmanager->findtowertopstone(tower, 1)], tower, checkmanager->findtowertopstone(tower, 1), 1);
			else
				movestone(tower[2][checkmanager->findtowertopstone(tower, 2)], tower, checkmanager->findtowertopstone(tower, 2), 2);
		}
		else if (tNum == 1)
		{

		}
		else
		{

		}
		//타겟돌이 있는 기둥 제외 나머지 두돌의 크기를 비교하고 
		//원하는 자리 제외한 다른 기둥으로 옮기기
		//

	}

}

Move::~Move()
{
}
