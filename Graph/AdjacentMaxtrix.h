//
// Created by luyanfcp on 17-10-28.
//

#ifndef DATASTRUCTURE_ADJACENTMAXTRIX_H
#define DATASTRUCTURE_ADJACENTMAXTRIX_H

#define AnyType void*

#include <stdlib.h>
#include <stdio.h>

typedef struct matrix *Graph;
struct matrix{
    AnyType *elem;
    int row;
    int rank;
};

Graph createMatrix(int/*rank*/ , int/*row*/, int[][]);
bool BFS(Graph,bool (*f)(AnyType));
bool DFS(Graph,bool (*f)(AnyType));
Graph dijkstra(Graph);
Graph flody(Graph);
Graph kruskal(Graph);
Graph prim(Graph);
bool destroyGraph(Graph);
#endif //DATASTRUCTURE_ADJACENTMAXTRIX_H
