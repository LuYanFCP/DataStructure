//
// Created by luyanfcp on 17-10-28.
//

#ifndef DATASTRUCTURE_ADJACENTLIST_H
#define DATASTRUCTURE_ADJACENTLIST_H

#define AnyType void*

#include <stdlib.h>
#include <stdio.h>
#include "../LinearStructure/List/LinkedList.h"

typedef struct List *Graph;
struct List{
    char *vertex;//顶点集合
    LinkedList *list;
};

Graph createMatrix(int/*rank*/ , int/*row*/, int[][]);
bool BFS(Graph,bool (*f)(AnyType));
bool DFS(Graph,bool (*f)(AnyType));
Graph dijkstra(Graph);
Graph flody(Graph);
Graph kruskal(Graph);
Graph prim(Graph);

#endif //DATASTRUCTURE_ADJACENTLIST_H
