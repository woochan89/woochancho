#include "DLinkedList.h"

//초기화
void listInit(List *list) {

}

//삽입
void InsertData(List *list, Slot data);

//체크
bool LIsEmpty(List list);

//퍼스트조회
Slot Lfirst(List *list, Slot data);

//넥스트조회
Slot Lnext(List *list, Slot data);

//삭제
void Lremove(List *list, Slot data);
