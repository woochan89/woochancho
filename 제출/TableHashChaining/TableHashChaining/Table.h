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

//초기화
void TBLinit(Table* tbl, func f);
//삽입
void TBLinsert(Table *tbl, Key k, Value v);
//삭제
Value TBLdelete(Table* tbl, Key k);
//남은 데이터 전부 삭제
void TBLdeleteALL(Table* tbl);
//검색
Value TBLsearch(Table* tbl, Key k);


#endif // !__TABLE__
