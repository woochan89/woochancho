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
		Drawmanager.DrawMidText("설 정",WIDTH,HEIGHT*0.5+2);
		Drawmanager.DrawMidText("랭 킹",WIDTH,HEIGHT*0.5+4);
		Drawmanager.DrawMidText("종 료",WIDTH,HEIGHT*0.5+6);
		select=Drawmanager.DrawArrow(WIDTH*0.5 - 4, HEIGHT*0.5, 4);
		switch (select)
		{
		case 1:
			Play(Option());
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
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
		if (select == 1 || select == 2 || select == 3)
		{
			if (select == EASY)
				m_iWidth = 9, m_iHeight = 9;
			else if (select == NOMAL)
				m_iWidth = 16, m_iHeight = 16;
			else if (select == HARD)
				m_iWidth = 16, m_iHeight = 30;

			return select;
		}
	}
}

void Game::Play(int level)
{
	int select;
	system("cls");
	Drawmanager.DrawBox(WIDTH, HEIGHT);

	Play::Setting(level, m_iWidth, m_iHeight);
	while (true)
	{
		select=Play::ControlCursor(m_iWidth, m_iHeight);
		if (select == 13)
		{
			Play::CheckBlock();
		}
	}
}

Game::~Game()
{
}
