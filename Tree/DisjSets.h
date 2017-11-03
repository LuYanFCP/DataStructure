//
// Created by luyanfcp on 17-11-3.
//

#ifndef DATASTRUCTURE_DISJSETS_H
#define DATASTRUCTURE_DISJSETS_H

//#define AnyType void*
#define ElemType int
#define error(x) printf("error: %s\n",x)
#include <malloc.h>
#include <printf.h>
#include "../LinearStructure/List/ArrayList.h"

typedef struct DijSetStruct *DijSets;
typedef struct node *Node;
struct node{
    Node parent;
    AnyType x;
    int rank;
};struct DijSetStruct{
    ArrayList forests;
    int setCounter;
};

DijSets createDijSet(); //返回一个空的不相交集
void insertNode(DijSets,ElemType);
void setUnion(DijSets,ElemType,ElemType);//包含两个元素的集合合并

Node find(ElemType);

#endif //DATASTRUCTURE_DISJSETS_H
