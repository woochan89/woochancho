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

//�ʱ�ȭ
void listInit(List *list);

//����
void InsertData(List *list, Slot data);

//üũ
bool LIsEmpty(List list);

//�۽�Ʈ��ȸ
Slot Lfirst(List *list, Slot data);

//�ؽ�Ʈ��ȸ
Slot Lnext(List *list, Slot data);

//����
void Lremove(List *list,Slot data);

#endif // !__DLINKEDLIST__
