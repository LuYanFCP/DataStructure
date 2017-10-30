//
// Created by luyanfcp on 17-10-28.
//

#include "AdjacentList.h"
#include "../LinearStructure/Queue/Queue.h"
#include "../LinearStructure/Stack/Stack.h"
#include "../heap/heap.h"
LGraph createLGraph(int nn/*node number*/){
    LGraph lGraph = malloc(sizeof(struct AL));
    lGraph->Nn = nn;
    lGraph->Ne = 0;

    lGraph->list = malloc(nn * sizeof(struct Vnode));
//    struct AdjVNode tmp;
//    for (int i = 0; i <nn ; ++i) {
//        tmp = lGraph->list;
//         = NULL;
//    }

    return lGraph;
};

bool insertEdge(LGraph lGraph,Edge edge)
{

    PtrToAdjVNode newNode = malloc(sizeof(struct AdjVNode));

    newNode->weight = edge->weight;
    newNode->AdjV = edge->v2;
    newNode->next = lGraph->list[edge->v1].FirstEdge->next;
    lGraph->list[edge->v1].FirstEdge->next = newNode;
    return true;


}
bool insertEdgeBoth(LGraph lGraph,Edge edge)
{
    PtrToAdjVNode newNode1 = malloc(sizeof(struct AdjVNode));

    newNode1->weight = edge->weight;
    newNode1->AdjV = edge->v2;
    newNode1->next = lGraph->list[edge->v1].FirstEdge->next;
    lGraph->list[edge->v1].FirstEdge->next = newNode1;
    /*
     * 第二次反过来插入一次
     */

    PtrToAdjVNode newNode2 = malloc(sizeof(struct AdjVNode));

    newNode2->weight = edge->weight;
    newNode2->AdjV = edge->v1;
    newNode2->next = lGraph->list[edge->v2].FirstEdge->next;
    lGraph->list[edge->v2].FirstEdge->next = newNode2;

    return true;
}

bool BFS(LGraph lGraph,bool (*f)(DataType), Vertex begin/*begin*/)
{
    printf("BFS: ["); //测试BFS用
    bool record[lGraph->Nn];
    int tmp_node = 0;

    /*
     * 待改名
     */
    int k = begin;

    Queue queue = createQueue(lGraph->Nn);

    PtrToAdjVNode p = lGraph->list[begin].FirstEdge->next;
    if (!p) {
        return false;
        error("begin node degree is 0!");
    }
    record[begin] = true;
    int recordNum = 1;
    EnQueue(queue,p);

    while (!isQueueEmpty(queue)) {
        p = DeQueue(queue);
        tmp_node = p->AdjV;
        p = lGraph->list[tmp_node].FirstEdge->next;
        while (p!=NULL){
            k = p->AdjV;
            if (!record[k]) {
                record[k] = true;
                recordNum++;
                printf("%d,",k);  // 测试用
                EnQueue(queue, p);
            }
            p = p->next;
        }
        if (recordNum == lGraph->Nn)
            return true;
    }
    printf("]\n"); // 测试用
}


bool DFS(LGraph lGraph,bool (*f)(DataType), Vertex v/*begin*/)
{
    printf("DFS: [");// 测试使用

    bool record[lGraph->Nn]; // 用于存储记录 , 如果不用栈的话，这个量应该是全局变量
    int recordNum = 1; // 已标记节点个数
    PtrToAdjVNode w = lGraph->list[v].FirstEdge->next; //临时指针
    if (!w) {
        error("begin node degree is 0!");
        return false;
    }
    int Nn = lGraph->Nn;
    printf("%d,",v);

    Stack stack = createStack();

    push(stack,w);

    while (w!=NULL && !isEmpty(stack)){
        while (w!=NULL && !record[w->AdjV])
        {
            push(stack,w);
            record[w->AdjV] = true;
            recordNum++;
            printf("%d,",w->AdjV);
            w = lGraph->list[w->AdjV].FirstEdge->next;
        }
        if (!isEmpty(stack)){
            w = pop(stack);
            w = w->next;
        }
        if (recordNum == Nn)
            return true;
    }
    printf("]/n"); //测试用
}
/*
 * 最小堆的比较函数
 */
int compare(void* param1, void* param2)
{
    int
}

    /*
     * 使用最小堆来进行更新和查找
     *
     */

int *dijkstra(LGraph lGraph,Vertex v/*begin*/)
{
    int Nn = lGraph->Nn;
    int collected[Nn];
    Vertex V,M;
    /*初始化*/
}
LGraph kruskal(LGraph);
LGraph prim(LGraph);
