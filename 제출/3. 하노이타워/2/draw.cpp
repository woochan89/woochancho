#include "draw.h"



draw::draw(int Tower)
{
	m_iTowerMax = Tower;
}

void draw::DrawTower(int *tower[])
{
	gotoxy(60, m_iTowerMax + 3);
	cout << "타워1";
	gotoxy(70, m_iTowerMax + 3);
	cout << "타워2";
	gotoxy(80, m_iTowerMax + 3);
	cout << "타워3";

	for (int i = 0; i < m_iTowerMax; i++)
	{
		DrawStone(tower, 0, i);
	}
}

void draw::EraseStone(int tNum, int sNum)
{
	int TowerX;
	if (tNum == 0)
		TowerX = 62;
	else if (tNum == 1)
		TowerX = 72;
	else
		TowerX = 82;
	gotoxy(TowerX, m_iTowerMax + 2 - sNum);
	cout << "  ";
}

void draw::DrawStone(int *tower[], int tNum, int sNum)
{
	int TowerX;
	if (tNum == 0)
		TowerX = 62;
	else if (tNum == 1)
		TowerX = 72;
	else
		TowerX = 82;
	gotoxy(TowerX, m_iTowerMax + 2 - sNum);
	cout << tower[tNum][sNum];

}

draw::~draw()
{
}
