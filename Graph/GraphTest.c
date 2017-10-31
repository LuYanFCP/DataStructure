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

int main()
{
    LGraph lGraph = buildLGraph();
    printLGraph(lGraph);
    BFS(lGraph,NULL,0);
    DFS(lGraph,NULL,1);

}