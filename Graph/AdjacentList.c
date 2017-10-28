//
// Created by luyanfcp on 17-10-28.
//
#include "AdjacentList.h"

static int searchVertex(LGraph lGraph,char key)
{
    int index;
    char *keys = lGraph->vertex;
    for (index = 0;keys[index]!=key;++index);
    return index;
}

LGraph createMatrix(int nn, char *nl, int (*pInt) []) {
    LGraph graph = (LGraph)malloc(sizeof(struct AL));
    graph->vertex = nl;
    graph->list = (LinkedList *)malloc(nn * sizeof(struct List));
}
bool insertEdge(LGraph lGraph,pEdge edge){
    int from = searchVertex(lGraph,edge->vertex_from);
    int to = searchVertex(lGraph,edge->vertex_to);

}

bool BFS(LGraph,bool (*f)(AnyType));
bool DFS(LGraph,bool (*f)(AnyType));
LGraph dijkstra(LGraph lGraph);
LGraph flody(LGraph lGraph);
LGraph kruskal(LGraph lGraph);
LGraph prim(LGraph lGraph);
