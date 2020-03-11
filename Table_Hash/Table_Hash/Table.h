#ifndef _TABLE_
#define _TABLE_
#define ARRMAX 100

#include"Slot.h"

typedef int(*keyfunc)(int);

//테이블
typedef struct _table
{
	keyfunc func;
	Slot tblarr[ARRMAX];
}Table;

//테이블 초기화
void TBLinit(Table *tbl, keyfunc func);

//삽입
void TBLinsert(Table *tbl, Value data);

//조회
Value TBLresearch(Table *tbl, int ssn);

//삭제
Value TBLremove(Table *tbl, int ssn);


#endif // !_TABLE_
