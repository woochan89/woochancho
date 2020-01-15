#pragma once
#include"Move.h"
#include"mecro.h"

class Main
{
public:
	void maketower(int stonemax,int *tower[]);
	Main();
	~Main();
};



void main()
{
	Main menu;
	Move *movemanager;
	int stonemax;
	int *tower[TOWERMAX];

	while (true)
	{
		system("cls");
		cout << "돌의 갯수를 입력해주세요 : ";
		cin >>stonemax;
		if (stonemax < 1)
		{
			cout << "0 이상의 정수를 입력해주세요" << endl;
			system("pause");
			continue;
		}
		menu.maketower(stonemax,&tower[TOWERMAX]);
		movemanager = new Move();
		for (int i = stonemax; i > 0; i--)
		{
			movemanager->movestone(i, tower);
		}
	}
















	//3번 돌 찾기
	//3번 돌 이 3번기둥 으로 갈 수 있는지 확인
	if (/*3번 돌 위에 다른 돌이 있다면*/)//3번 돌 이 이동 가능한 상태인지 확인
	{
		//3번 기둥에 없다면 3번돌 위에 다른돌이 있는지 확인
		//3번 돌 위의 다른돌 위에 다른돌이 있는지 확인
		//1번 돌을 다른 기둥으로 이동(이동시 이동하는 돌이 이동 자리에 있는 돌보다 크면 안됨)
		//3번 위의 2번돌을 다른 기둥으로 이동
	}

	if (비어있지않다면)//3번 기둥의 1번 자리가 비어있는지 확인
	{
		//3번기둥 비우기->3번 기둥과 2번 기둥 돌의 크기를 비교하여 작은 돌이 큰돌 위로 가게 이동
	}
	//1번 기둥의 3번 돌을 3번 기둥으로 이동


	//2번 돌 위치확인
	//2번 돌이 3번 기둥으로 갈수있는지 확인
	if ()//2번 돌 위에 다른돌이 있다면
	{
		//1번 돌을 이동해야할 기둥말고 다른 기둥으로 이동
	}
	if ()//3번 기둥의 마지막 돌이 2+1인지 아닌지 확인
	{
		//3번 기둥의 마지막 돌을 2번 돌이 있는곳이 아닌 다른 기둥으로 이동
	}
	//2번 돌을 3번 기둥으로 이동

	//1번 돌 위치 확인
	if ()//1번돌 위에 다른돌이 있는지 확인(1번돌 위엔 다른돌이 존재할수 없으므로 바로 리턴)
	{

	}
	if (아니라면)//3번 기둥의 마지막돌이 1+1돌인지 확인
	{
		//3번 기둥의 마지막돌을 다른 기둥으로 이동
	}
	//1번 돌을 3번돌 위로 이동



	while (StoneMax >= 0)
	{
		FindStone(StoneMax, &tNum, &sNum);
		sNum = CheckStone(tNum, sNum);
		StoneMax--;
	}
}