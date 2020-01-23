#include "ArrayList.h"



ArrayList::ArrayList()
{

}

void ArrayList::ListInit(List *list)
{
	list->CurrentP = -1;
	list->Max = 0;
}

void ArrayList::LInsert(List *list, Ldata data)
{
	if (list->Max + 1 < LEN)
		list->Array[(list->Max)++] = data;
}

int ArrayList::LFirst(List *list, Ldata *data)
{
	if (list->CurrentP == -1)
	{
		list->CurrentP++;
		*data = list->Array[list->CurrentP];
	}
	return 0;
}

int ArrayList::LNext(List *list, Ldata *data)
{
	if (list->Max-1 == list->CurrentP)
	{
		return false;
	}
	list->CurrentP++;
	*data = list->Array[list->CurrentP];
	return true;
}

void ArrayList::RCurrentP(List *list)
{
	list->CurrentP = 0;
}


int ArrayList::LCheck(List list)
{
	return list.Array[list.CurrentP];
}


void ArrayList::LRemove(List *list)
{
	Ldata tmp;
	int tmpCurrentP;

	tmp = list->Array[list->CurrentP];
	tmpCurrentP = list->CurrentP;
	while (list->CurrentP < list->Max)
	{
		list->Array[list->CurrentP] = list->Array[list->CurrentP+1];
		list->CurrentP++;
	}
	list->Max--;
	list->CurrentP=tmpCurrentP;
}

void ArrayList::AddCurrentP(List *list)
{
	list->CurrentP++;
}

bool ArrayList::ShowData(List *list)
{
	if (list->Max == list->CurrentP)
		return false;
	else
	{
		cout << " [ " << list->Array[list->CurrentP++] << " ] ";
		return true;
	}
}


ArrayList::~ArrayList()
{
}
