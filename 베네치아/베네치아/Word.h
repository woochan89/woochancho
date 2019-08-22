#pragma once
#include"Draw.h"
#define SLOW 1
#define FAST 2
#define STOP 3
#define BLIND 4

struct Wordtree
{
	string word;
	int Xcoordinate;
	int Ycoordinate;
	int effect;
	Wordtree *next;
};

class Word
{
private:
	int m_iWordmax;
	int m_iMax;
	string *m_sWordlist;
	Wordtree *m_wDroppingword;
	Wordtree *m_wTmp;
	Draw Drawmanager;
protected:

public:
	void Getdata();
	void Makeword();
	void Dropword();
	void EraseWord(Wordtree *Word);
	int HitWord(string typingword);
	Word();
	~Word();
};

