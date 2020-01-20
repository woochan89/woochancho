#include "draw.h"



draw::draw(int Tower)
{
	m_iTowerMax = Tower;
}

void draw::DrawTower()
{
	gotoxy(30, m_iTowerMax + 3);
	cout << "타워1";
	gotoxy(40, m_iTowerMax + 3);
	cout << "타워1";
	gotoxy(50, m_iTowerMax + 3);
	cout << "타워1";
}

void draw::EraseStone(int tNum, int sNum)
{
	int TowerX;
	if (tNum == 0)
		TowerX = 30;
	else if (tNum == 1)
		TowerX = 40;
	else
		TowerX = 50;
	gotoxy(TowerX, m_iTowerMax + 3 - sNum);
	cout << "  ";
}

void draw::DrawStone(int *tower[], int tNum, int sNum)
{
	int TowerX;
	if (tNum == 0)
		TowerX = 30;
	else if (tNum == 1)
		TowerX = 40;
	else
		TowerX = 50;
	gotoxy(TowerX, m_iTowerMax + 3 - sNum);
	cout << tower[tNum][sNum];

}

draw::~draw()
{
}
