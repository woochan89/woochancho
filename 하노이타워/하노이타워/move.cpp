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
	cout << tnum + 1 << "�� ����� " << tower[2][checkmanager->findtowertopstone(tower, 2)] << "�� ���� " << 3 << "�� ������� �̵�" << endl;


}

void Move::movestone(int target,int *tower[], int evade, int sNum,int tNum)
{
	int TargetTower[2];
	int evadeL = -1;
	int MoveTower;

	if (tower[tNum][sNum + 1] != 0)//�����Ҵ� ���� �ʰ��� ���� ����
	{
		if (m_iStoneMax % 2 == 1 && target == 1 && tNum==0 && sNum == m_iStoneMax - 1)//1�� ���� 1�� ����� �� ���� ������ 2�� ����� �ƴ� 3��������� �̵�
			evadeL == 1;
		movestone(tower[tNum][sNum + 1], tower, evadeL, sNum, tNum);//Ÿ�ٵ��� �����̱�
	}

	MoveTower = checkmanager->checktower(tower, tNum, sNum);//ȸ���� �ڸ� ���� ����� �ֱ�



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
		//Ÿ�ٵ��� �ִ� ��� ���� ������ �ε��� ũ�⸦ ���ϰ� 
		//���ϴ� �ڸ� ������ �ٸ� ������� �ű��
		//

	}

}

Move::~Move()
{
}
