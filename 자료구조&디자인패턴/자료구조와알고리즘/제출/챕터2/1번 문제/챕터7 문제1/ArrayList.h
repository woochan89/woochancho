#pragma once
#include<iostream>
#include<stdio.h>
#define LEN	100

typedef int Ldata;

typedef struct _ArrayList
{
	Ldata List[LEN];
	int NumOfData;
	int CurPosition;
}List;

class ArrayList
{
private:
public:
	void Listinit(List *list);
	void Linsert(List *list,Ldata data);
	Ldata Lfirst(List *list, Ldata *data);
	Ldata Lnext(List *list, Ldata *data);
	void Lremove(List *list);
	ArrayList();
	~ArrayList();
};

