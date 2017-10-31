//
// Created by luyanfcp on 17-10-28.
//

#include "AdjacentList.h"
#include "../LinearStructure/Queue/Queue.h"
#include "../LinearStructure/Stack/Stack.h"

LGraph createLGraph(int nn/*node number*/){
    LGraph lGraph = malloc(sizeof(struct AL));
    lGraph->Nn = nn;
    lGraph->Ne = 0;

    lGraph->list = malloc(nn * sizeof(struct Vnode));

    for (int i = 0; i <nn ; ++i) {
        PtrToAdjVNode newNode= malloc(sizeof(struct AdjVNode));
        newNode->AdjV = i;
        newNode->next =NULL;
        newNode->weight = 0;
        lGraph->list[i].FirstEdge=newNode;
    }

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

bool insertEdge2(LGraph lGraph, Vertex v1, Vertex v2, WeigthType weight)
{
    PtrToAdjVNode newNode = malloc(sizeof(struct AdjVNode));

    newNode->weight = weight;
    newNode->AdjV = v2;
    newNode->next = lGraph->list[v1].FirstEdge->next;
    lGraph->list[v1].FirstEdge->next = newNode;
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
    //初始化数组
    for (int i = 0; i <lGraph->Nn ; ++i) {
        record[i] = false;
    }
    int tmp_node = 0;

    /*
     * 待改名
     */
    int k = begin;

    Queue queue = createQueue(lGraph->Nn);

    PtrToAdjVNode head = lGraph->list[begin].FirstEdge;
    PtrToAdjVNode p;
    if (!head->next) {
        return false;
        error("begin node degree is 0!");
    }
    record[begin] = true;
    int recordNum = 1;
    EnQueue(queue,head);

    while (!isQueueEmpty(queue)) {
        p = DeQueue(queue);
        tmp_node = p->AdjV;
        p = p->next;
        while (p!=NULL){
            k = p->AdjV;
            if (!record[k]) {
                record[k] = true;
                recordNum++;
                printf("%d,",k);// 测试用
                head = lGraph->list[k].FirstEdge;
                EnQueue(queue, head);
            }
            p = p->next;
        }
        if (recordNum == lGraph->Nn){
            printf("]\n"); // 测试用
            return true;
        }
    }

}

static Edge newEdge()
{

}
LGraph buildLGraph()
{
    printf("请输入创建图的节点数：");
    int Nn;
    scanf("%d",&Nn);
    printf("\n请输入边的个数:");
    int Ne;
    scanf("%d",&Ne);
    printf("创建图成功！\n");
    LGraph lGraph = createLGraph(Nn);
    printf("\n 请输入边的信息,格式为：(V1,V2,Weight)\n");
    int v1;
    int v2;
    int weight;
    for (int i = 0; i < Ne ; ++i) {
        scanf("%d %d %d",&v1,&v2,&weight);
        insertEdge2(lGraph,v1,v2,weight);
    }
    printf("结束输入,创建图完成!\n");
    return lGraph;
}

bool DFS(LGraph lGraph,bool (*f)(DataType), Vertex v/*begin*/)
{
    printf("DFS: [");// 测试使用

    bool record[lGraph->Nn]; // 用于存储记录 , 如果不用栈的话，这个量应该是全局变量
    for (int i = 0; i < lGraph->Nn; ++i) {
        record[i] = false;
    }
    int recordNum = 0 ;// 已标记节点个数
    PtrToAdjVNode w = lGraph->list[v].FirstEdge->next; //临时指针
    if (!w) {
        error("begin node degree is 0!");
        return false;
    }
    int Nn = lGraph->Nn;
    printf("%d,",v);

    Stack stack = createStack();

    push(stack,w);
    record[v] = true;
    recordNum++;
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
        if (recordNum == Nn) {
            printf("]\n"); //测试用
            return true;
        }
    }
}
/*
 * 最小堆的比较函数
 */
int compare(void* param1, void* param2)
{
//    int
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
