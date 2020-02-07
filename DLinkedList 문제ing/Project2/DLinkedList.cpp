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
	//�� Point����
	list->numOfdata++;
	Node *newNode = new Node;
	newNode->data = data;
	//�ӽ� Point ���� ���� head->next ����
	Node *tmpNode = list->head->next;
	//while�� ���� ã��
	if (tmpNode == NULL) {
		newNode->next = tmpNode;
		list->head->next = newNode;
		return;
	}
	
	//������ ����(�̾� ������)
	if (Lfirst(list, &data))
	{
		Lnext(list, &data);
		while (list->comp(list->cur, list->cur->next))
		{
			Lnext(list, &data);
		}
		newNode->next = list->cur->next;
		list->cur = newNode;
	}
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
