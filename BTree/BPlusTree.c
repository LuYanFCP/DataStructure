//
// Created by luyanfcp on 17-10-14.
//

#include "bpTree.h"

btp search(typekey,btp);
btp insert(typekey,btp);
btp delete(typekey,btp);
int height(btp);
int count(btp);
double payload(btp);
btp deltree(btp);
//用于插入的方法
static void InternalInsert(typekey /*key*/,btp /*t*/);
static void InsInNode(btp,int);
static void splitNode(btp,int);
static btp NewRoot(btp);
//用于删除的方法
static void InternalDelete(typekey,btp);
static void JoinNode(btp,int);
static void MoveLefrNode(btp,int);
static void MoveRightNode(btp,int);
static void DelFromNode(btp,int);
static btp FreeRoot(btp);

static btp delall(btp);
static void Error(int,typekey);

// 相关的变量
char *InsValue = NULL;
static int flag; //节点增减标志
static int btree_level = 0; //树的高度
static int btree_count = 0; //多路树的键总数
static int node_sum = 0; // 多路树的节点总数
static int level;//当前访问节点的高度
static btp newTree; //在节点分割的时候指向新建的节点
static typekey InsKey;//要插入的键

//查找


//插入
btp insert(typekey key,btp t)
{
    level=btree_level;
    InternalInsert(key,t); //?
    if (flag)           //跟节点满之后，它被分割成两个半满节点
        t = NewRoot(t);
    return t;
}

static void InternalInsert(typekey key,btp t)
{

}