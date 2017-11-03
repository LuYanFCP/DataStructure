//
// Created by luyanfcp on 17-11-3.
//
#include "DisjSets.h"

static Node isContain(ElemType);
static void link(Node /*root1*/,Node /*root2*/);
static Node findSet(Node /*n*/);

static DijSets dijSets;

DijSets createDijSet()
{
    DijSets new = malloc(sizeof(struct DijSetStruct));
    new->forests = createList();
    new->setCounter = 0;
    dijSets = new;
    return new;
} //返回一个空的不相交集
void insertNode(DijSets dijSets,ElemType x)
{
    if (isContain(x)!=NULL){
        error("element is exist");
        return;
    }
    Node newx = (Node)malloc(sizeof(struct node));
    newx->rank = 0;
    newx->parent = newx;
    newx->x = x;
    insertElem(dijSets->forests,newx);
    dijSets->setCounter++;
}
void setUnion(DijSets dijSets, ElemType x, ElemType y) //包含两个元素的集合合并
{
    if(x==y) {
        error("两元素不能相等");
    }
    Node xNode = isContain(x);
    Node yNode = isContain(y);
    if (!xNode && !yNode){
        link(findSet(xNode),findSet(yNode));
    }

}
static Node findSet(Node n)
{
    if (n!=n->parent)
        n->parent = findSet(n->parent); // 路径压缩
    return n->parent;
}

Node find(ElemType x)
{
    Node n = isContain(x);
    if (n==NULL){
        error("不含该节点");
        return NULL;
    }
    return findSet(n);
}

static Node isContain(ElemType x)
{
    Node tmp;
    ArrayList list =dijSets->forests;
    for (int i = 0; i < list->length ; ++i) {
        tmp = (Node)list->elem[i];
        if (tmp ->x == x)
            return tmp;
    }
    return false;
}
static void link(Node root1,Node root2)
{
    if (root1->rank > root2->rank)
        root2->parent = root1;
    else {
        root1->parent = root2;
        if(root1 == root2)
            root2->rank++;
    }
}
