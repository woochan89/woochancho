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

	cout << "1. ž �ױ�" << endl;
	cout << "2. ž ����" << endl;
	cout << "3. ����" << endl;
}


Drawmanager::~Drawmanager()
{
}
