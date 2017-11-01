//
// Created by luyanfcp on 17-10-30.
//
#include "AdjacentList.h"

/*
 * 测试用
 */
void printLGraph(LGraph lGraph)
{
    int Nn = lGraph->Nn;
    PtrToAdjVNode tmp ;
    printf("打印LGraph:\n");
    for (int i = 0; i < Nn; ++i) {
        tmp = lGraph->list[i].FirstEdge;
        printf("%d:",tmp->AdjV);
        for (tmp=tmp->next ; tmp!=NULL ; tmp = tmp->next)
            printf("%d,",tmp->AdjV);
        printf("\n");
    }
    printf("--------------------------------\n");
}

void printArray(int *arr,int Num)
{
    while(Num-->0)
        printf("%d,",*(arr++));
    printf("\n");
}

int main()
{
//    LGraph lGraph = buildLGraph(insertEdge2);
//    printLGraph(lGraph);
//    BFS(lGraph,NULL,0);
//    DFS(lGraph,NULL,1);
//    printf("----------测试dijkstra------------ \n");
//    int dist[lGraph->Nn];
//    int path[lGraph->Nn];
//    dijkstra(lGraph,0,dist,path);
//    printf("dist: ");printArray(dist,lGraph->Nn);
//    printf("path: ");printArray(path,lGraph->Nn);
    printf("------------请输入测试prim算法使用的图---------------\n");
    LGraph NVGraph = buildLGraph(insertEdgeBoth2);
    printLGraph(NVGraph);
    printLGraph(prim(NVGraph,0));

}