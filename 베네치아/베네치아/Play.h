#pragma once
#include"Draw.h"
#include"Rank.h"
#include"Word.h"
#define NAME 0
#define WORD 1

class Play:public Word
{
private:
	char m_cWord[11] = {NULL};
	int m_iHeart;
	int m_iScore;
	int m_iTypingWordNum;
	Draw Drawmanager;
	Rank Rankmanager;
	string m_sName;
public:
	void Menu();
	void Intro();
	void Introchange(string str[],int num);
	string Getname();
	bool GetWord();
	void Gameplay(int stage);
	Play();
	~Play();
};

