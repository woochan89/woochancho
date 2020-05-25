#include "Drawmanager.h"



Drawmanager::Drawmanager()
{
}

void Drawmanager::DrawTower(list<int> tower, int tower_max)
{

	int x = 0;
	int y =tower_max;
	system("cls");
	for (list<int>::iterator iter = tower.begin(); iter != tower.end(); iter++,y--)
	{
		gotoxy(x, y);
		cout << *iter << endl;
	}
	DrawInterface(tower_max);
}

void Drawmanager::DrawInterface(int tower_max)
{
	
	gotoxy(0, tower_max+2);

	cout << "1. 탑 쌓기" << endl;
	cout << "2. 탑 제거" << endl;
	cout << "3. 종료" << endl;
}


Drawmanager::~Drawmanager()
{
}
