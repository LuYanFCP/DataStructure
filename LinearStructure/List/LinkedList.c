//
// Created by luyanfcp on 17-10-20.
//
/*
 * 这是一个双链表
 */

#include "LinkedList.h"

//static int size = 0; //设置全局变量
static LNode getNode(LinkedList /*list*/,int /*index*/);
static LNode newNode(LNode prev, LNode next, AnyType elem)
{
    LNode newnode = (LNode)malloc(sizeof(struct Node));
    newnode->elem = elem;
    newnode->next = next;
    newnode->prev = prev;
}

LinkedList createList()
{
    // 初始节点 elem 应该有头有尾
    LNode head = newNode(NULL,NULL,NULL);
    LNode tail = newNode(head,NULL,NULL);
    LinkedList list = (LinkedList)malloc(sizeof(struct List));
    list->head = head;
    list->tail = tail;
    return list;
}
bool destroy(LinkedList list)
{
    LNode node = list->head;
    LNode tmp =NULL;
    while (node) {
        tmp = node;
        free(tmp);
        node = node->next;
    }
    free(list);
    return true;
}
bool insertElem(LinkedList list,AnyType x)
{
//    while (list) {
//        LinkedList newList = newNode(list, NULL, x);
//        list->next = newList;
//        list = list->next;
//    }
    insertAfter(list,length(list),x); //不用判断
    return true;
}
// 在第i个位置之前插入元素
bool insertAfter(LinkedList list,int pos,AnyType x)
{
    if (pos>length(list)){
        error("index overstep the boundary!");
        return false;
    }
    LNode p = getNode(list,pos);
    LNode new = newNode(p,p->next,x);
    p->next->prev =new;
    p->next = new;
    list->size++;
    return true;
//    LNode  p = list->head;
//    int i = 0;
//    while (p != NULL && i < pos) {
//        p = p->next;
//        i++;
//    }
//    if (p == NULL)
//        return false;
//
//    LNode newList = newNode(p,NULL, x);
//    if (p->next!=NULL)
//        p->next->prev = newList->next; //如果后面有节点，则把后面节点的前指针指向新节点
//    p->next = newList;
//    size++;
//    return true;
}

bool insertBefore(LinkedList list,int pos /* 索引 */,AnyType x)
{
    // 判断是否出界
    if (pos>length(list)) {
        error("index overstep the boundary!");
        return false;
    }
    LNode p = getNode(list,pos);
    LNode new = newNode(p->prev,p,x);
    p->prev->next = new;
    p->prev = new;
    list->size++;
//    LNode p = list->head;
//    int i = 0;
//    // 找第 i-1 个节点
//    while (p!=NULL && i < pos-1){
//        p = p->next;
//        i++;
//    }
//    if (p == NULL)
//        return false;
//
//
//    // 后面有节点
//    LNode newList = newNode(p,NULL, x);
//    p->next->prev = newList->next;
//    p->next = newList;
//    size++;
    return true;
}

bool deleteElem(LinkedList list,int pos)
{
//    LNode p =list->head;
//    while (pos-->=0)
//        p = p->next;
    LNode p = getNode(list,pos);
    /*
     * 首先先把前面的Node存在临时变量
     * 上一个Node指针指向下一个
     */
    LNode  tmp = p->prev;
    p->prev->next= p->next;
    p->next->prev= tmp;
    free(p);
    list->size--;
    return true;
}
int length(LinkedList list)
{
    return list->size;
}

// clear 在链表中是什么意思
//bool clear(LinkedList)
//{
//
//}

static LNode getNode(LinkedList list,int index)
{
    int i;
    LNode tmp = list->head;
    if (index <0 || index>length(list)-1) {
        error("index beyond the limit!");
        return NULL;
    }
    int mid = length(list)/2;
    if (index<mid) {
        for (i = 0; i <= index; ++i) {
            tmp = tmp->next;
        }

        return tmp;
    }

    tmp = list->tail;
    for (i = 0; i >= index; --i) {
            tmp = tmp->prev;
        }
    return tmp;
}


AnyType getElem(LinkedList list,int pos)
{
    return getNode(list, pos)->elem;
}

bool isEmpty(LinkedList list)
{
    return  ! list->size;
}

int searchElem(LinkedList list,AnyType x)
{
    int pos= 0;
    LNode p =list->head->next;
    while(p && p->elem != x){
        pos++;
        p = p->next;
    }
    /*
     * 退出循环有两种情况
     * 1. 可能找到元素
     * 2. 到了最后一个元素，判断list->next退出
     * 解决方法： 在判断一下当前节点的element是否是要查找的值
     * 如果是返回
     * 不是返回-1
     */
    if (p!=NULL && p->elem == x)
        return pos;
    return -1;
}

void printList(LinkedList list )
{
    /*
     * 实现 1
     */
//    int l = length(list);
//    printf("linkedList->length: %d \n",l);
//
//    for (int j = 0; j < l; ++j) {
//        printf("%d,",getElem(list,j));
//    }
    /*
     * 实现2
     */
    LNode p = list->head->next;
    while (p !=NULL){
        printf("%p,",p->elem);
        p = p->next;
    }
}

bool contain(LinkedList list,AnyType x, int (*compare)(AnyType x1,AnyType x2))
{
    /*  比较什么，只是X的地址吗？要不要传入一个比较函数
     *  暂时完成只是比较
     */
    LNode p= list->head->next;
    while (p){
        if (compare(p,x)==0)
            return true;
    }
    return false;
}
