#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

typedef struct _list
{
	Node *head;
	Node *tail;
	Node *cur;
	int numOfdata;
}List;

void Linit(List *list)
{
	list->head = new Node;
	list->head->next = NULL;
	list->cur = NULL;
	list->numOfdata = 0;
}

void Linsert(List *list, int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head->next;
	if (list->numOfdata == 0)
		list->tail = newNode;
	list->head->next = newNode;
	list->numOfdata++;
}


int main(void)
{
	List list;
	Node * newNode = NULL;
	int readData;

	Linit(&list);

	/**** �����͸� �Է� �޴� ���� ****/
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		Linsert(&list, readData);
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if (list.head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else
	{
		list.cur = list.head->next;
		printf("%d  ", list.cur->data);   // ù ��° ������ ���

		while (list.cur->next != NULL)    // �� ��° ������ ������ ���
		{
			list.cur = list.cur->next;
			printf("%d  ", list.cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if (list.head == NULL)
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node * delNode = list.head;
		Node * delNextNode = list.head->next;

		printf("���� ��带 �����մϴ�. \n");
		free(delNode);    // ���� ����� ����

		while (delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	system("pause");

	return 0;
}