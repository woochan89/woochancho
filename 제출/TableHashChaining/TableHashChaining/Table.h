#ifndef __TABLE__
#define __TABLE__
#define MAX_TBL 100
#include"Slot.h"
#include"DLinkedList.h"

typedef Key (func)(Key);

typedef struct _table 
{
	List tbl[MAX_TBL];
	func *hf;
}Table;

//�ʱ�ȭ
void TBLinit(Table* tbl, func f);
//����
void TBLinsert(Table *tbl, Key k, Value v);
//����
Value TBLdelete(Table* tbl, Key k);
//���� ������ ���� ����
void TBLdeleteALL(Table* tbl);
//�˻�
Value TBLsearch(Table* tbl, Key k);


#endif // !__TABLE__
