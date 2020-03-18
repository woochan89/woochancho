#ifndef _GRAPH_
#define _GRAPH_

#define NAME_LEN 30
#include"LinkedList.h"
#include"CircleQueue.h"


typedef struct _graph
{
	int numV;
	int numE;
	//char **name;
	List NameList;
	List *edgeList;
	bool *visitInfo;
}Graph;

int GetIDX(Graph* g, int visitV);


void VertexInit(Graph* g);

//�ʱ�ȭ
void GraphInit(Graph* g);

//�Ҵ� ����
void GraphDestroy(Graph* g);

//���� ����
void AddEdge(Graph* g, int fromV, int toV);

//���� ���� ���
void ShowEdge(Graph* g);

//���� ���� ���
void BFSshowGraphVertex(Graph* g, int startV);
int VisitVertex(Graph * g, int visitV);

//���Լ�
int WhoIsPrecede(int data1, int data2);


#endif // !_GRAPH_
