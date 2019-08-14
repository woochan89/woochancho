#pragma once
#include"Draw.h"
#include"Rank.h"
#include"Word.h"
#define NAME 0
#define WORD 1

class Play:public Word
{
private:
	Draw Drawmanager;
	Rank Rankmanager;
	string m_sName;
public:
	void Menu();
	void Intro();
	void Introchange(string str[],int num);
	string Getword(bool check);
	void Gameplay(int stage);
	Play();
	~Play();
};

