#include"DLinkedList.h"

void init(List *list)//�ʱ�ȭ
{
	list->head = new Node;
	list->head->next = NULL;
	list->before = NULL;
	list->cur = NULL;
	list->comp = NULL;
	list->numOfdata = 0;
}

void InputData(List *list, Point data)//����
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->numOfdata++;
}

void ArrayInputData(List *list, Point data)//���� ����
{
	Node *newNode = new Node;	//�� Point����
	newNode->data = data;
	Node *tmpNode = list->head;	//�ӽ� Node ���� ���� head->next ����
	while (tmpNode->next != NULL && list->comp(tmpNode->next, newNode))
		tmpNode = tmpNode->next;
	newNode->next = tmpNode->next;
	tmpNode->next = newNode;
	list->numOfdata++;
}

bool Lfirst(List *list, Point *data)//����
{
	if (list->numOfdata == 0)
		return 0;
	list->cur = list->head->next;//ù��� ����Ŵ
	list->before = list->head;//���� ��� ī��Ŵ
	*data = list->cur->data;
	return 1;
}

bool Lnext(List *list, Point *data)//����
{
	if (list->cur->next == NULL)
		return 0;
	list->before = list->cur;
	list->cur = list->cur->next;
	*data = list->cur->data;
	return 1;
}

void Lremove(List *list, Point *data)//����
{
	Node *dNode = list->cur;
	*data = list->cur->data;

	list->cur = list->before;
	list->cur->next = dNode->next;
	delete dNode;
	list->numOfdata--;
}

void SetFunc(List *list, int(*comp)(Node*, Node*))
{
	list->comp = comp;
}
