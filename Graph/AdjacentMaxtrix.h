//
// Created by luyanfcp on 17-10-28.
//

#ifndef DATASTRUCTURE_ADJACENTMAXTRIX_H
#define DATASTRUCTURE_ADJACENTMAXTRIX_H
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define weightType int
#define INF INT_MAX
#define Vertex int


typedef struct ENode *Edge;
typedef struct matrix *MGraph;

struct matrix{
    weightType **elem;
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
bool insertEdge2(MGraph,Vertex ,Vertex, weightType);
bool insertEdgeBoth(MGraph,Edge);
bool insertEdgeBoth2(MGraph,Vertex ,Vertex, weightType);
bool BFS(MGraph,Vertex /*begin*/);
bool DFS(MGraph,Vertex /*begin*/);
void dijkstra(MGraph, Vertex /*begin*/, int*/*disk*/, int* /*path*/);
bool flody(MGraph,weightType**,Vertex**);
MGraph kruskal(MGraph);
void prim(MGraph,Vertex *parent);
bool destroyGraph(MGraph);
#endif //DATASTRUCTURE_ADJACENTMAXTRIX_H
