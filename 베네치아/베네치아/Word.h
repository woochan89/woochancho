#pragma once
#include"Draw.h"

struct Wordstat
{
	string word;
	int coordinate;
};

struct Wordtree
{
	string word;
	Wordtree *next;
};

class Word
{
private:
	int m_iMax;
	Wordstat *Wordlist;
	Wordtree *
protected:

public:
	void Getdata();
	void Makeword();
	void Dropword();
	Word();
	~Word();
};

