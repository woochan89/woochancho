#pragma once
#include<iostream>
using namespace std;

typedef struct _ppos
{
	int xpos;
	int ypos;
} Ppos;


class ArrayList
{
public:
	void ListInit();
	void LInsert();
	void LFirst();
	void LNext();
	void LRemove();

	ArrayList();
	~ArrayList();
};

