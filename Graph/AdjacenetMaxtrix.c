//
// Created by luyanfcp on 17-11-6.
//

#include "AdjacentMaxtrix.h"
MGraph createMatrix(int vertexNum/*MaxVertexNum*/)
{
    MGraph mGraph = malloc(sizeof(struct matrix));
    // 申请一个二维数组
    mGraph->elem = (weightType**)malloc(vertexNum*sizeof(weightType*));
    for (int i = 0; i < vertexNum; ++i) {
        mGraph->elem[i] = (weightType*)malloc(vertexNum* sizeof(weightType));
    }
    // 初始化赋值
    for (int i = 0; i < vertexNum; ++i) {
        for (int j = 0; j < vertexNum; ++j) {
            if (i==j)
                mGraph->elem[i][j]=0;
            mGraph->elem[i][j] = INF;
        }
    }

    mGraph->edgeNum = 0;
    mGraph->maxVertexNum = vertexNum;
    return mGraph;
}
MGraph buildMGraph()
{
    printf("please input number of Vertex:");
    int Vn,En;
    scanf("%d",&Vn);
    MGraph mGraph = createMatrix(Vn);
    printf("please input number of Edge:");
    scanf("%d",&En);
    printf("please input edges,(v1,v2,weight)\n");
    int v1,v2,weight;
    while (En -- >0){
        scanf("%d,%d,%d",&v1,&v2,&weight);
        insertEdge2(mGraph,v1,v2,weight);
    }
    printf("input over!\n");
}
bool insertEdge(MGraph mGraph,Edge edge){};
bool insertEdge2(MGraph mGraph,Vertex v1,Vertex v2, weightType weight)
{
    mGraph->elem[v1][v2] = weight;
    mGraph->edgeNum++;
    return true;
}
bool insertEdgeBoth(MGraph mGraph,Edge edge) {}

bool insertEdgeBoth2(MGraph mGraph,Vertex v1,Vertex v2, weightType weight)
{
    mGraph->elem[v1][v2] =weight;
    mGraph->elem[v1][v2] =weight;
    mGraph->edgeNum++;
    return true;
}

bool BFS(MGraph mGraph,Vertex begin /*begin*/);
bool DFS(MGraph mGraph,Vertex begin/*begin*/);

static int findMin(MGraph mGraph, const bool *collected,Vertex begin)
;

void dijkstra(MGraph mGraph, Vertex begin/*begin*/, int* dist/*dist*/, int* path/*path*/)
{
    int Vn = mGraph->maxVertexNum;
    Vertex v = begin;
    bool collected[Vn];
//    int collectedNum = 0;
    for (int i = 0; i < Vn ; ++i) {
        dist[i] = INF;
        path[i] = -1;
        collected[i] = false;
    }
    /*
     * 与begin节点相接的初始化
     *
     */
    collected[v] = true;
//    collectedNum = 0;
    /*    0 1 2 3 4 5 6 7 8
     *  0 0
     *  1   0
     *  2     0
     *  3       0
     *  4         0
     *  5           0
     *  6            0
     *  7              0
     *  8                0
     */
    for (int i = 0; i < mGraph->maxVertexNum; ++i) {
        if (mGraph->elem[v][i]<INF){
            dist[i] = mGraph->elem[v][i];
            path[i] = v;
        }
    }
    while (true){
        v = findMin(mGraph,collected,v);
        if (v==-1)
            break;
        collected[v]=true;
        for (int i = 0; i < mGraph->maxVertexNum; ++i) {
            if (collected[i]) // 由于在之前v已经被标记，会自动跳过v
                continue;
            if(dist[i]>dist[v]+mGraph->elem[v][i]){
                dist[i] = dist[v]+mGraph->elem[v][i];
                path[i] = v;
            }
        }
    }

}
static int findMin(MGraph mGraph, const bool *collected,Vertex begin)
{
    int min = INF;
    for (int i = 0; i < mGraph->maxVertexNum; ++i) {
        if (collected[i])// 由于在之前v已经被标记，会自动跳过v
            continue;
        min = mGraph->elem[begin][i]<min?mGraph->elem[begin][i]:min;
    }
    return min==INF?-1:min;
}

bool flody(MGraph mGraph,weightType **dist,Vertex **path)
{
    int Vn = mGraph->maxVertexNum;
    /*初始化两个二维数组*/
    for (int i = 0; i < Vn; ++i) {
        for (int j = 0; j < Vn ; ++j) {
            dist[i][j] = mGraph->elem[i][j];
            path[i][j] = -1;
        }
    }
    for (int k = 0; k < Vn; ++k) {
        for (int i = 0; i < Vn; ++i) {
            for (int j = 0; j < Vn; ++j) {
                if (dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                    if (i == j && dist[i][j]<0)  //发现负值圈
                        return false;
                    path[i][j] = k;
                }
            }
        }
    }
    return true;
}
/**
 *
 * @param mGraph
 * @param parent
 *
 * 事实上prim算法的返回值应该是一个 邻接表存储的图，但是由于邻接表的方法与邻接矩阵的方法名字相同
 * 编译通不过，因此我们才去parent[] 数组的方法保存
 */
void prim(MGraph mGraph,Vertex *parent)
{
    int Vn = mGraph->maxVertexNum;
    Vertex v = 0;
    bool collected[Vn];
    weightType dist[Vn];
//    int collectedNum = 0;
    for (int i = 0; i < Vn ; ++i) {
        parent[i] = -1;
        collected[i] = false;
        dist[i] = INF;
    }
    //存储与初始化0位置

    collected[v] = true;
    for (int j = 0; j < Vn; ++j) {
        if (!collected[j] && mGraph->elem[v][j] < INF){
            parent[j] = v;
            dist[j] = mGraph->elem[v][j];
        }
    }

    while (true){
        v = findMin(mGraph,collected,v);
        if (v == -1)
            break;
        collected[v] = true;
        for (int i = 0; i < Vn; ++i) {
            if (collected[i])
                continue;
            if (mGraph->elem[v][i]<dist[i]){
                dist[i] = mGraph->elem[v][i];
                parent[i] = v;
            }
        }
    }

}


bool destroyGraph(MGraph mGraph)
{
    for (int i = 0; i < mGraph->maxVertexNum; ++i) {
        free(mGraph->elem[i]);
    }
    free(mGraph->elem);
    free(mGraph);
    return true;
}
