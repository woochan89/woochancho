#include"DLinkedList.h"

void init(List *list)//초기화
{
	list->head = new Node;
	list->head->next = NULL;
	list->before = NULL;
	list->cur = NULL;
	list->comp = NULL;
	list->numOfdata = 0;
}

void InputData(List *list, Point data)//삽입
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->numOfdata++;
}

void ArrayInputData(List *list, Point data)//정렬 삽입
{
	Node *newNode = new Node;	//새 Point생성
	newNode->data = data;
	Node *tmpNode = list->head;	//임시 Node 변수 만들어서 head->next 지정
	while (tmpNode->next != NULL && list->comp(tmpNode->next, newNode))
		tmpNode = tmpNode->next;
	newNode->next = tmpNode->next;
	tmpNode->next = newNode;
	list->numOfdata++;
}

bool Lfirst(List *list, Point *data)//참조
{
	if (list->numOfdata == 0)
		return 0;
	list->cur = list->head->next;//첫노드 가리킴
	list->before = list->head;//더미 노드 카리킴
	*data = list->cur->data;
	return 1;
}

bool Lnext(List *list, Point *data)//참조
{
	if (list->cur->next == NULL)
		return 0;
	list->before = list->cur;
	list->cur = list->cur->next;
	*data = list->cur->data;
	return 1;
}

void Lremove(List *list, Point *data)//삭제
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
