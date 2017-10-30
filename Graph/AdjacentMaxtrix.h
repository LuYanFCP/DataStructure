//
// Created by luyanfcp on 17-10-28.
//

#ifndef DATASTRUCTURE_ADJACENTMAXTRIX_H
#define DATASTRUCTURE_ADJACENTMAXTRIX_H

#define weightType void*
#define INF
#define Vertex int
#include <stdlib.h>
#include <stdio.h>


typedef struct ENode *Edge;
typedef struct matrix *MGraph;

struct matrix{
    weightType *elem;
    int maxVertexNum;  // 节点名称
    /*
     *  缺少节点的数据
     */
    int edgeNum;
};
struct ENode{
    Vertex v1,v2;
    weightType weight;
};

MGraph createMatrix(int/*MaxVertexNum*/);
MGraph buildMGraph(); //通过I/O创建MGraph
bool insertEdge(MGraph,Edge);
bool BFS(MGraph,bool (*f)(weightType));
bool DFS(MGraph,bool (*f)(weightType));
MGraph dijkstra(MGraph);
MGraph flody(MGraph);
MGraph kruskal(MGraph);
MGraph prim(MGraph);
bool destroyGraph(MGraph);
#endif //DATASTRUCTURE_ADJACENTMAXTRIX_H
