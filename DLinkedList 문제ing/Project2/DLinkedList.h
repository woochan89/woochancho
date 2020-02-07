#include"Point.h"
#ifndef _D_LINKED_LIST_
#define _D_LINKED_LIST_

typedef struct _node {
	Point data;
	struct _node *next;
}Node;

typedef struct _d_linked_list {
	Node *head;//머리->더미
	Node *cur;//현제 참조 위치
	Node *before;//참조 위치 바로 전 노드>>삭제후 이어 붙힐때 필요
	int numOfdata;
	int(*comp)(Node* Before, Node* After);
}List;

void init(List *list);//초기화

void InputData(List *list, Point data);//삽입

void ArrayInputData(List *list, Point data);//정렬 삽입

bool Lfirst(List *list, Point *data);//참조

bool Lnext(List *list, Point *data);//참조

void Lremove(List *list, Point *data);//삭제

void SetFunc(List *list, int(*comp)(Node*, Node*));//비교함수 삽입





#endif // !_d_linked_list_
