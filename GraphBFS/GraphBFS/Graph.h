#ifndef _GRAPH_��
#define _GRAPH_
#include"LinkedList.h"
#include"CircleQueue.h"

enum
{
	A=0,B,C,D,E,F,G,H,I,J
};

typedef struct _graph
{
	int numV;
	int numE;
	List *edgeList;
	bool *visitInfo;
}Graph;

//�ʱ�ȭ
void GraphInit(Graph* g, int nv);

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
