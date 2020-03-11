#include "Table.h"
#define NULL 0

//테이블 초기화
void TBLinit(Table *tbl, keyfunc func)
{
	for (int i = 0; i < ARRMAX; i++) {
		tbl->tblarr[i].status = EMPTY;
	}
	tbl->func = func;
}

//삽입
void TBLinsert(Table *tbl, Value data)
{
	int key = tbl->func(data->ssn);
	tbl->tblarr[key].value = data;


	tbl->tblarr[key].key = key;
}

//조회
Value TBLresearch(Table *tbl, int ssn)
{

}

//삭제
Value TBLremove(Table *tbl, int ssn)
{

}
