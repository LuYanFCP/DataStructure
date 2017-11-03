//
// Created by luyanfcp on 17-10-28.
//

#ifndef DATASTRUCTURE_ADJACENTLIST_H
#define DATASTRUCTURE_ADJACENTLIST_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include "../Tree/DijSets.c"
#include "../heap/heap.h"


#define DataType void*
#define Vertex int
#define WeigthType int
#define error(x) printf("%s \n",x)
#define INF INT_MAX

//#include "../LinearStructure/List/LinkedList.h"


typedef struct AL *LGraph;
typedef struct Vnode  AdjList;
typedef struct AdjVNode *PtrToAdjVNode;
typedef struct ENode *Edge;

struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data;
};

struct AL{
    int Nn;//顶点数
    int Ne; //边数
    AdjList *list;
};
struct AdjVNode{
    Vertex AdjV;
    WeigthType weight;
    PtrToAdjVNode next;
};

struct ENode{
    Vertex v1,v2;
    WeigthType weight;
};


LGraph createLGraph(int/*node number*/);
LGraph buildLGraph(bool (*insert)(LGraph,Vertex,Vertex,WeigthType)); // 从console中输入的数据进行构建
bool insertEdge(LGraph,Edge);
bool insertEdgeBoth(LGraph,Edge);
bool insertEdge2(LGraph, Vertex, Vertex, WeigthType );
bool insertEdgeBoth2(LGraph, Vertex, Vertex, WeigthType);
bool BFS(LGraph,bool (*f)(DataType), Vertex /*begin*/);
bool DFS(LGraph,bool (*f)(DataType), Vertex /*begin*/);

Heap getEdgesHeap(LGraph lGraph,int (*compare)(void*,void*));

void dijkstra(LGraph, Vertex /*begin*/, int*/*disk*/, int* /*path*/);
//LGraph flody(LGraph); 临街链表主存储稀疏图 这里不用flody算法更好
DijSets kruskal(LGraph);
LGraph prim(LGraph, Vertex /*begin*/);

#endif //DATASTRUCTURE_ADJACENTLIST_H
