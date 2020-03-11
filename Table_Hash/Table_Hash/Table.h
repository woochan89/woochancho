#ifndef _TABLE_
#define _TABLE_
#define ARRMAX 100

#include"Slot.h"

typedef int(*keyfunc)(int);

//���̺�
typedef struct _table
{
	keyfunc func;
	Slot tblarr[ARRMAX];
}Table;

//���̺� �ʱ�ȭ
void TBLinit(Table *tbl, keyfunc func);

//����
void TBLinsert(Table *tbl, Value data);

//��ȸ
Value TBLresearch(Table *tbl, int ssn);

//����
Value TBLremove(Table *tbl, int ssn);


#endif // !_TABLE_
