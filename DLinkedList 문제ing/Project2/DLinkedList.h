#include"Point.h"
#ifndef _D_LINKED_LIST_
#define _D_LINKED_LIST_

typedef struct _node {
	Point data;
	struct _node *next;
}Node;

typedef struct _d_linked_list {
	Node *head;//�Ӹ�->����
	Node *cur;//���� ���� ��ġ
	Node *before;//���� ��ġ �ٷ� �� ���>>������ �̾� ������ �ʿ�
	int numOfdata;
	int(*comp)(Node* Before, Node* After);
}List;

void init(List *list);//�ʱ�ȭ

void InputData(List *list, Point data);//����

void ArrayInputData(List *list, Point data);//���� ����

bool Lfirst(List *list, Point *data);//����

bool Lnext(List *list, Point *data);//����

void Lremove(List *list, Point *data);//����

void SetFunc(List *list, int(*comp)(Node*, Node*));//���Լ� ����





#endif // !_d_linked_list_
