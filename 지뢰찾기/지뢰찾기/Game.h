#pragma once
#include"Draw.h"
#include"Play.h"
#define WIDTH 40
#define HEIGHT 40
class Game
{
private :
	Draw Drawmanager;
	int m_iWidth;
	int m_iHeight;
public:
	void MainMenu();
	void SetSize(int height, int width, int extra_x=0, int extra_y=0);
	int Option();
	void Play(int level);
	Game();
	~Game();
};

