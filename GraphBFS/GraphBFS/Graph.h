#ifndef _GRAPH_µå
#define _GRAPH_
#include"LinkedList.h"

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



#endif // !_GRAPH_
