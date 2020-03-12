#include "Table.h"
#include"DLinkedList.h"
#include<stdlib.h>

//초기화
void TBLinit(Table* tbl, func f)
{
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&tbl->tbl[i]);
	tbl->hf = f;
}

//삽입
void TBLinsert(Table *tbl, Key k, Value v)
{
	int hv = tbl->hf(k);
	Slot ns = { v, k };

	FInsert(&(tbl->tbl[hv]), ns);

}

//삭제
Value TBLdelete(Table* tbl, Key k)
{
	int hk = tbl->hf(k);
	Slot cSlot;

	if (LFirst(&tbl->tbl[hk], &cSlot))
	{
		if (cSlot.key = k && cSlot.v->ssn == k)
		{
			LRemove(&tbl->tbl[hk]);
			return cSlot.v;
		}
		else
		{
			while (LNext(&tbl->tbl[hk], &cSlot))
			{
				if (cSlot.key == k && cSlot.v->ssn == k)
				{
					LRemove(&tbl->tbl[hk]);
					return cSlot.v;
				}
			}
		}
	}
	return NULL;
}

void TBLdeleteALL(Table* tbl)
{
	Slot cSlot;
	for (int i = 0; i < MAX_TBL; i++) 
	{
		if (LFirst(&tbl->tbl[i], &cSlot))
		{
			LRemove(&tbl->tbl[i]);
			PrintPerson(*cSlot.v);
			free(cSlot.v);
			printf("삭제완료\n\n");
			while (LNext(&tbl->tbl[i], &cSlot))
			{
				LRemove(&tbl->tbl[i]);
				PrintPerson(*cSlot.v);
				free(cSlot.v);
				printf("삭제완료\n\n");
			}
		}
	}
}


//검색
Value TBLsearch(Table* tbl, Key k)
{
	int hk = tbl->hf(k);
	Slot cSlot;

	if (LFirst(&tbl->tbl[hk], &cSlot))
	{
		if (cSlot.key = k&&cSlot.v->ssn==k)
			return cSlot.v;
		else
		{
			while (LNext(&tbl->tbl[hk], &cSlot))
			{
				if (cSlot.key == k&&cSlot.v->ssn == k)
					return cSlot.v;
			}
		}
	}
	return NULL;
}
