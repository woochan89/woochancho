#include "Village.h"



Village::Village()
{
	int Width= (WIDTH * 2) + 1;
	int Height= HEIGHT + 5;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);
	m_iDay = 1;
	m_iMoney = 0;
	m_bFacilityFlag = true;
	tmp[0] = { NULL };
	GameStart();
}

void Village::GameStart()
{
	DrawManager.DrawBox();
	DrawManager.DrawMidText("모험을 함께할 동료를 선택해주세요!",WIDTH,HEIGHT*0.5);
	DrawManager.gotoxy(0, HEIGHT);
	system("pause");
	AssemblyFacility();
	Menu();
}

void Village::Menu()
{
	int Select;
	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		ShowStatus();
		for (int i = -3; i <= 3; i++)
		{
			if (i == -3)
				DrawManager.DrawMidText("< 마 을 >",WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				DrawManager.DrawMidText("던 전", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -1)
				DrawManager.DrawMidText("상 점", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 0)
				DrawManager.DrawMidText("집 회 구 역", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 1)
				DrawManager.DrawMidText("여 관", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == 2)
				DrawManager.DrawMidText("조 정", WIDTH, HEIGHT*0.5 + 2 * i);
			else
				DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
		}
		Select = DrawManager.DrawCursor(6, WIDTH*0.5-4, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
			DungeonManager.Menu();
			break;
		case 2:
			break;
		case 3://집회구역
			AssemblyFacility();
			break;
		case 4://여관
			if (m_iMoney >= 100)
			{
				m_iDay++;
				m_iMoney -= 100;
				//캐릭터 체력회복
			}
			else
			{
				system("cls");
				DrawManager.DrawBox();
				DrawManager.DrawMidText("소지금이 부족합니다!",WIDTH,HEIGHT*0.5);
				DrawManager.gotoxy(0, HEIGHT);
				system("pause");
			}
			break;
		case 5:
			break;
		case 6:
			return;
		}
	}
}

void Village::ShowStatus()
{
	DrawManager.gotoxy(WIDTH-10,HEIGHT+1);
	cout << "Day : " << m_iDay << "\t 소지금 : " << m_iMoney<<" G";
}

void Village::AssemblyFacility()
{
	int Select;
	if (m_bFacilityFlag = true)
	{
		if (tmp[0] != NULL)
		{
			for (int i = 0; i < 5; i++)
			{
				delete tmp[i];
				tmp[i] = NULL;
			}
		}
		for (int i = 0,j; i < 5; i++)
		{
			j = rand() % 3;
			if (j== 0)
				tmp[i] = new Archer();
			else if (j == 1)
				tmp[i] = new Magician();
			else
				tmp[i] = new Warrior();
		}
	}

	while (true)
	{
		system("cls");
		DrawManager.DrawBox();
		for (int i = -3; i <= 3; i++)
		{
			DrawManager.gotoxy(WIDTH*0.5+15,HEIGHT*0.5+2*i);
			if (i == -3)
				DrawManager.DrawMidText("< 집 회 구 역 >", WIDTH, HEIGHT*0.5 + 2 * i);
			else if (i == -2)
				tmp[0]->ShowCharacter();
			else if (i == -1)
				tmp[1]->ShowCharacter();
			else if (i == 0)
				tmp[2]->ShowCharacter();
			else if (i == 1)
				tmp[3]->ShowCharacter();
			else if (i == 2)
				tmp[4]->ShowCharacter();
			else
				DrawManager.DrawMidText("나가기", WIDTH, HEIGHT*0.5 + 2 * i);
		}
		Select = DrawManager.DrawCursor(6, WIDTH*0.5 - 5, HEIGHT*0.5 - 4);
		switch (Select)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			return;
		}
	}
	m_bFacilityFlag=false;
}

Village::~Village()
{
	if (tmp[0] != NULL)
	{
		for (int i = 0; i < 5; i++)
			delete tmp[i];
	}
}
