#include "Play.h"



Play::Play()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 5, (WIDTH * 2) + 1);
	system(buf);
	Menu();

}

void Play::Menu()
{
	int Select;
	while (true)
	{
		Drawmanager.Drawinterface();
		Drawmanager.DrawTextWithBox("�� �� �� �� ġ �� �� ��", WIDTH, HEIGHT*0.2);
		Drawmanager.DrawMidText("1. ���� ����", WIDTH, HEIGHT*0.5 - 2);
		Drawmanager.DrawMidText("2. ��ŷ", WIDTH, HEIGHT*0.5);
		Drawmanager.DrawMidText("3. ������", WIDTH, HEIGHT*0.5 + 2);
		Select = Drawmanager.DrawCursor(3, WIDTH*0.5 - 6, HEIGHT*0.5 - 2);
		cout << Select;
		switch (Select)
		{
		case 1:
			Intro();
			Getname();
			Gameplay(1);
			break;
		case 2:
			Rankmanager.Showrank();
			break;
		case 3:
			return;
		}
	}
}

void Play::Intro()
{

}

void Play::Getname()
{

}

void Play::Gameplay(int stage)
{

}

Play::~Play()
{
}
