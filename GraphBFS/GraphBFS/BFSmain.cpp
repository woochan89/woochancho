#include <stdio.h>
#include "Graph.h"

int main(void)
{
	Graph graph;

	VertexInit(&graph);
	GraphInit(&graph);

	AddEdge(&graph, 1, 2);
	AddEdge(&graph, 1, 4);
	AddEdge(&graph, 2, 3);
	AddEdge(&graph, 4, 3);
	AddEdge(&graph, 4, 5);
	AddEdge(&graph, 5, 6);
	AddEdge(&graph, 5, 7);

	ShowEdge(&graph);

	BFSshowGraphVertex(&graph, 1); printf("\n");
	BFSshowGraphVertex(&graph, 2); printf("\n");
	BFSshowGraphVertex(&graph, 3); printf("\n");
	BFSshowGraphVertex(&graph, 4); printf("\n");

	GraphDestroy(&graph);
	return 0;
}