#include "Game.h"



Game::Game()
{
	srand((unsigned)time);
	MainMenu();
}

void Game::MainMenu()
{
	SetSize(HEIGHT, WIDTH, 5, 1);
	int select;
	while (true)
	{
		system("cls");
		Drawmanager.DrawBox(WIDTH, HEIGHT);
		Drawmanager.DrawMidTextWithBox("지 뢰 찾 기",WIDTH,HEIGHT*0.5-4);
		Drawmanager.DrawMidText("게 임 실 행",WIDTH,HEIGHT*0.5);
		Drawmanager.DrawMidText("종 료",WIDTH,HEIGHT*0.5+4);
		select = Drawmanager.DrawArrow (WIDTH * 0.5 - 4, HEIGHT * 0.5, 4);
		switch (select)
		{
		case 1:
			Play(Option());
			break;
		case 2:
			return;
		}
	}
}

void Game::SetSize(int height,int width,int extra_y,int extra_x)
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", height + extra_y, (width * 2) + extra_x);
	system(buf);
}

int Game::Option()
{
	int select;
	system("cls");
	while (true)
	{
		Drawmanager.DrawBox(WIDTH, HEIGHT);
		Drawmanager.DrawMidText("난 이 도", WIDTH, HEIGHT*0.5-6);
		Drawmanager.DrawMidText("초 급( 9 X 9 , 지뢰 10개 )", WIDTH, HEIGHT*0.5-2);
		Drawmanager.DrawMidText("중 급( 16 X 16 , 지뢰 40개 )", WIDTH, HEIGHT*0.5);
		Drawmanager.DrawMidText("고 급( 16 X 30 , 지뢰 99개 )", WIDTH, HEIGHT*0.5+2);
		select = Drawmanager.DrawArrow(WIDTH*0.5 - 10, HEIGHT*0.5 - 2, 3);
		switch (select)
		{
		case EASY:
			m_iWidth = 9, m_iHeight = 9;
			break;
		case NOMAL:
			m_iWidth = 16, m_iHeight = 16;
			break;
		case HARD:
			m_iWidth = 16, m_iHeight = 30;
			break;
		}
			return select;
	}
}

void Game::Play(int level)
{
	int mine;
	if (level == EASY)
		mine = 10;
	else if (level == NOMAL)
		mine = 40;
	else
		mine = 99;
	int turn = 0;
	int select;
	system("cls");
	Drawmanager.DrawBox(WIDTH, HEIGHT);
	Drawmanager.DrawInterface(WIDTH, HEIGHT, level,mine);
	Play::Setting(level, m_iWidth, m_iHeight);
	while (true)
	{
		select=Play::ControlCursor(m_iWidth, m_iHeight, &mine);
		if (select == 13)
		{
			Drawmanager.DrawTurn(HEIGHT + 3, ++turn);
			if (!Play::CheckBlock(m_iWidth,m_iHeight))
			{
				Drawmanager.DrawMidTextWithBox("Game Over!", WIDTH, HEIGHT*0.5);
				Drawmanager.gotoxy(0, HEIGHT + 4);
				system("pause");
				Play::Reset(m_iHeight);
				return;
			}
			if(Play::WinCheck(m_iWidth, m_iHeight)==1)
			{
				Drawmanager.DrawTurn(HEIGHT + 3, ++turn);
				Drawmanager.DrawMidTextWithBox("Stage Clear!", WIDTH, HEIGHT*0.5);
				Drawmanager.gotoxy(0, HEIGHT + 4);
				system("pause");
				Play::Reset(m_iHeight);
				return;
			}
		}
	}
}

Game::~Game()
{
}
