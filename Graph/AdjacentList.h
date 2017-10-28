//
// Created by luyanfcp on 17-10-28.
//

#ifndef DATASTRUCTURE_ADJACENTLIST_H
#define DATASTRUCTURE_ADJACENTLIST_H

#define AnyType void*

#include <stdlib.h>
#include <stdio.h>
#include "../LinearStructure/List/LinkedList.h"

typedef struct AL *LGraph;
struct AL{
    char *vertex;//顶点集合
    LinkedList *list;
};
typedef struct {
    char vertex_from;
    char vertex_to;
    int weight;
} edge, *pEdge;

LGraph createMatrix(int/*node number*/,char[], int[][]);
bool insertEdge(LGraph,pEdge);
bool BFS(LGraph,bool (*f)(AnyType));
bool DFS(LGraph,bool (*f)(AnyType));
LGraph dijkstra(LGraph);
LGraph flody(LGraph);
LGraph kruskal(LGraph);
LGraph prim(LGraph);

#endif //DATASTRUCTURE_ADJACENTLIST_H
