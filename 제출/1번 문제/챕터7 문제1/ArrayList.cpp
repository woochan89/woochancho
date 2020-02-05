#include "ArrayList.h"



ArrayList::ArrayList()
{

}

void ArrayList::Listinit(List *list)
{
	list->CurPosition = -1;
	list->NumOfData = 0;
}

void ArrayList::Linsert(List *list, Ldata data)
{
	list->List[list->NumOfData++] = data;
}

Ldata ArrayList::Lfirst(List *list, Ldata *data)
{
	if (list->NumOfData == 0)
		return 0;
	list->CurPosition = 0;
	*data = list->List[list->CurPosition];
	return 1;
}

Ldata ArrayList::Lnext(List *list, Ldata *data)
{
	if (list->NumOfData <= list->CurPosition+1)
		return 0;
	*data = list->List[++list->CurPosition];
	return 1;
}

void ArrayList::Lremove(List *list)
{
	list->List[list->CurPosition] = NULL;
	for (int i = list->CurPosition; i < list->NumOfData; i++) {
		list->List[i] = list->List[i + 1];
	}
	list->NumOfData--;
	list->CurPosition--;
}

ArrayList::~ArrayList()
{
}
