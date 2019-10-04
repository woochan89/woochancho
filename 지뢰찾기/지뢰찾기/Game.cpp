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
		Drawmanager.DrawMidTextWithBox("�� �� ã ��",WIDTH,HEIGHT*0.5-4);
		Drawmanager.DrawMidText("�� �� �� ��",WIDTH,HEIGHT*0.5);
		Drawmanager.DrawMidText("�� ��",WIDTH,HEIGHT*0.5+2);
		Drawmanager.DrawMidText("�� ŷ",WIDTH,HEIGHT*0.5+4);
		Drawmanager.DrawMidText("�� ��",WIDTH,HEIGHT*0.5+6);
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
		Drawmanager.DrawMidText("�� �� ��", WIDTH, HEIGHT*0.5-6);
		Drawmanager.DrawMidText("�� ��( 9 X 9 , ���� 10�� )", WIDTH, HEIGHT*0.5-2);
		Drawmanager.DrawMidText("�� ��( 16 X 16 , ���� 40�� )", WIDTH, HEIGHT*0.5);
		Drawmanager.DrawMidText("�� ��( 16 X 30 , ���� 99�� )", WIDTH, HEIGHT*0.5+2);
		select = Drawmanager.DrawArrow(WIDTH*0.5 - 10, HEIGHT*0.5 - 2, 3);
		if (select == 1 || select == 2 || select == 3)
			return select;
	}
}

void Game::Play(int level)
{
	int width,height;
	if (level == EASY)
		width = 9, height = 9;
	else if (level == NOMAL)
		width = 16, height = 16;
	else if(level==HARD)
		width = 16, height = 30;
	cout << "�÷���";
	system("pause");
	return;
}

Game::~Game()
{
}
