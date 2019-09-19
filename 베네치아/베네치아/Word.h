#pragma once
#include"Draw.h"
#define SLOW 1
#define FAST 2
#define STOP 3

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
	int Dropword();
	void EraseWord(Wordtree *Word);
	int HitWord(string typingword, int *wordlength);
	int FirstWordErase(int *length);
	void WordReset();
	void WordReset(Wordtree *Word);
	Word();
	~Word();
};

