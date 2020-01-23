#pragma once
#include<iostream>
using namespace std;
#define LEN	100

typedef int Ldata;

typedef struct _ArrayList
{
	int Array[LEN];
	int Max;
	int CurrentP;
}List;

class ArrayList
{
private:
	List *list;
public:
	void ListInit(List *list);
	void LInsert(List *list,Ldata data);
	int LFirst(List *list, Ldata *data);
	int LNext(List *list, Ldata *data);
	void RCurrentP(List *list);
	int LCheck(List list);
	void LRemove(List *list);
	void AddCurrentP(List *list);
	bool ShowData(List *list);

	ArrayList();
	~ArrayList();
};

