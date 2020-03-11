#ifndef __DLINKEDLIST__
#define __DLINKEDLIST__
#include"Slot.h"

typedef struct _node {
	Slot data;
	struct _node *prev;
	struct _node *next;
}Node;

typedef struct _dlinkedlist {
	Node *head;
	Node *tail;
	Node *cur;
	int numOfdata;

}DLinkedList;

typedef DLinkedList List;

//초기화
void listInit(List *list);

//삽입
void InsertData(List *list, Slot data);

//체크
bool LIsEmpty(List list);

//퍼스트조회
Slot Lfirst(List *list, Slot data);

//넥스트조회
Slot Lnext(List *list, Slot data);

//삭제
void Lremove(List *list,Slot data);

#endif // !__DLINKEDLIST__
