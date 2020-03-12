#include "Table.h"
#include"DLinkedList.h"
#include<stdlib.h>

//�ʱ�ȭ
void TBLinit(Table* tbl, func f)
{
	for (int i = 0; i < MAX_TBL; i++)
		ListInit(&tbl->tbl[i]);
	tbl->hf = f;
}

//����
void TBLinsert(Table *tbl, Key k, Value v)
{
	int hv = tbl->hf(k);
	Slot ns = { v, k };

	FInsert(&(tbl->tbl[hv]), ns);

}

//����
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
			printf("�����Ϸ�\n\n");
			while (LNext(&tbl->tbl[i], &cSlot))
			{
				LRemove(&tbl->tbl[i]);
				PrintPerson(*cSlot.v);
				free(cSlot.v);
				printf("�����Ϸ�\n\n");
			}
		}
	}
}


//�˻�
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
