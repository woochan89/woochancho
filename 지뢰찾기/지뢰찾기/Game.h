#pragma once
#include"Draw.h"
#include"Play.h"

class Game
{
private :
	Draw Drawmanager;
	Play *Playmanager;
	int m_iWidth;
	int m_iHeight;
public :
	void MainMenu();
	void SetSize(int height, int width, int extra_x=0, int extra_y=0);
	int Option();
	void PlayGame(int level);
	Game();
	~Game();
};


void main()
{
	Game Gamemanager;
}