#pragma once
#include"mecro.h"
#include"Draw.h"
#define WIDTH 40
#define HEIGHT 40
enum level
{
	EASY=1,NOMAL,HARD
};
class Game
{
private :
	Draw Drawmanager;
public:
	void MainMenu();
	void SetSize(int height, int width, int extra_x=0, int extra_y=0);
	int Option();
	void Play(int level);
	Game();
	~Game();
};

