#include "Table.h"
#define NULL 0

//���̺� �ʱ�ȭ
void TBLinit(Table *tbl, keyfunc func)
{
	for (int i = 0; i < ARRMAX; i++) {
		tbl->tblarr[i].status = EMPTY;
	}
	tbl->func = func;
}

//����
void TBLinsert(Table *tbl, Value data)
{
	int key = tbl->func(data->ssn);
	tbl->tblarr[key].value = data;


	tbl->tblarr[key].key = key;
}

//��ȸ
Value TBLresearch(Table *tbl, int ssn)
{

}

//����
Value TBLremove(Table *tbl, int ssn)
{

}
