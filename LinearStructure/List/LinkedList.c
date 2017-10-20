//
// Created by luyanfcp on 17-10-20.
//

#include "LinkedList.h"
static LinkedList newNode(LinkedList prev, LinkedList next, AnyType elem)
{
    LinkedList newnode = (LinkedList)malloc(sizeof(struct Node));
    newnode->elem = elem;
    newnode->next = next;
    newnode->prev = prev;
}

LinkedList createList()
{
    // 初始节点 elem 应该是哨兵
    return newNode(NULL,NULL,MAXVALUE);
}
bool destroy(LinkedList list)
{
    if (list->next) {
        destroy(list->next); //从第一个开始， 不停的望下一个递归，先free了最后一个
        free(list);
    }
    return true;
}
bool insertElem(LinkedList list,AnyType x)
{
    LinkedList newList = newNode(list,NULL,x);
    list->next = newList;
    return true;
}
bool deleteElem(LinkedList list,int pos)
{
    while (pos-->=0)
        list = list->next;
    /*
     * 首先先把前面的Node存在临时变量
     * 上一个Node指针指向下一个
     */
//    LinkedList  tmp = list->prev;
    list->prev= list->next;
    list->next= list->prev;
    free(list);
}
int length(LinkedList list)
{
    int length = 0;
    while (list->next)
        length++;
    return length;
}

// clear 在链表中是什么意思
//bool clear(LinkedList)
//{
//
//}

AnyType getElem(LinkedList list,int pos)
{
    while(pos-->=0)
        list = list->next;
    return list->elem;
}

bool isEmpty(LinkedList list)
{
    return (bool) list->next;
}

int searchElem(LinkedList list,AnyType x)
{
    int pos= -1;
    while(list->next && list->elem != x)
        pos++;
    /*
     * 退出循环有两种情况
     * 1. 可能找到元素
     * 2. 到了最后一个元素，判断list->next退出
     * 解决方法： 在判断一下当前节点的element是否是要查找的值
     * 如果是返回
     * 不是返回-1
     */
    if (list->elem == x)
        return pos;
    return -1;
}