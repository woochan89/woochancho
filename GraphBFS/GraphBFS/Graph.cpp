#include "Graph.h"
#include<iostream>


void VertexInit(Graph* g)
{
	int num;
	g->numV = 0;
	ListInit(&g->NameList);
	SetSortRule(&g->NameList, WhoIsPrecede);
	while (1)
	{
		system("cls");
		printf("���� �Է� : ");
		scanf("%d", &num);
		if (num == NULL)
			break;
		LInsert(&g->NameList, num);
		g->numV++;
	}
}

//�ʱ�ȭ
void GraphInit(Graph* g)
{
	g->edgeList = (List*)malloc(sizeof(List)*g->numV);
	g->numE = 0;


	for (int i = 0; i < g->numV; i++)
	{
		ListInit(&g->edgeList[i]);
		SetSortRule(&g->edgeList[i], WhoIsPrecede);
	}
	g->visitInfo = (bool*)malloc(sizeof(bool)*g->numV);
	memset(g->visitInfo, 0, sizeof(bool)*g->numV);




	//*g->name = (char*)malloc(sizeof(char)*g->numV);
	//for (int i = 0; i < nv; i++)
	//{
	//	g->name[i] = (char*)malloc(sizeof(char)*NAME_LEN);
	//	g->name[i] = NULL;
	//}

}

//�Ҵ� ����
void GraphDestroy(Graph* g)
{
	if (g->edgeList != NULL)
		free(g->edgeList);
	if (g->visitInfo != NULL)
		free(g->visitInfo);

}

//���� ����
void AddEdge(Graph* g, int fromV, int toV)
{
	int fromIDX = 0, toIDX = 0;
	Data num;
	LFirst(&g->NameList, num);
	if (num != fromV)
		while (fromIDX < g->numV)
		{
			fromIDX++;
			LNext(&g->NameList, num);
			if (num == fromV)break;
		}
	LFirst(&g->NameList, num);
	if (num != toV)
		while (toIDX < g->numV)
		{
			toIDX++;
			LNext(&g->NameList, num);
			if (num == toV)break;
		}
	if (fromIDX >= g->numV|| toIDX >= g->numV)
	{
		printf("�������� �ʴ� ���� �Դϴ�\n");
		system("pause");
		return;
	}

	LInsert(&g->edgeList[fromIDX], toV);
	LInsert(&g->edgeList[toIDX], fromV);
	g->numE++;
}

//���� ���� ���
void ShowEdge(Graph* g)
{
	int vx;
	int x;
	LFirst(&g->NameList, x);
	for (int i = 0; i < g->numV; i++)
	{
		printf("%d�� ����� ����: ", x);
		LNext(&g->NameList, x);
		if (LFirst(&(g->edgeList[i]), vx))
		{
			printf("%d ", vx);

			while (LNext(&(g->edgeList[i]), vx))
				printf("%d ", vx);
		}
		printf("\n");
	}

}



//���� ���� ���
void BFSshowGraphVertex(Graph* g, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QInit(&queue);

	VisitVertex(g, visitV);

	while (LFirst(&(g->edgeList[GetIDX(g,visitV)]), nextV) == true)
	{
		if (VisitVertex(g, nextV) == true)
			Enqueue(&queue, nextV);

		while (LNext(&(g->edgeList[GetIDX(g, visitV)]), nextV) == true)
		{
			if (VisitVertex(g, nextV) == true)
				Enqueue(&queue, nextV);
		}

		if (QIsEmpty(queue))    // ť�� ��� BFS ����
			break;
		else
			visitV = Dequeue(&queue);
	}

	// Ž�� ���� �ʱ�ȭ
	memset(g->visitInfo, 0, sizeof(bool) * g->numV);

}

int GetIDX(Graph* g,int visitV)
{
	int idx = 0;
	int num;

	LFirst(&g->NameList, num);
	if(num!=visitV)
		while (visitV < g->numV)
		{
			idx++;
			LNext(&g->NameList, num);
			if (num == visitV)break;
		}
	return idx;
}

int VisitVertex(Graph * g, int visitV)
{
	if (g->visitInfo[GetIDX(g,visitV)] == 0)
	{
		g->visitInfo[GetIDX(g, visitV)] = true;
		printf("%d ", visitV);    // �湮 ���� ���
		return true;
	}

	return false;
}

//���Լ�
int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}
