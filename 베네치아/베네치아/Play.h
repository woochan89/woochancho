#pragma once
#include"Draw.h"
#include"Rank.h"
class Play
{
private:
	Draw Drawmanager;
	Rank Rankmanager;
	string m_sName;
public:
	void Menu();
	void Intro();
	void Introchange(string str[],int num);
	void Getname();
	void Gameplay(int stage);
	Play();
	~Play();
};

