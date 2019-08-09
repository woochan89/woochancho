#pragma once
#include"Draw.h"
#include"Rank.h"
class Play
{
private:
	Draw Drawmanager;
	Rank Rankmanager;

public:
	void Menu();
	void Intro();
	void Getname();
	void Gameplay(int stage);
	Play();
	~Play();
};

