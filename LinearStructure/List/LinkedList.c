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
        destroy(list->next); //从第一个开始， 不停的往下一个递归，先free了最后一个
        free(list);
    }
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
    LinkedList  p = list;
    int i = 0;
    while (p != NULL && i < pos) {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return false;

    LinkedList newList = newNode(p,NULL, x);
    if (p->next!=NULL)
        p->next->prev = newList->next; //如果后面有节点，则把后面节点的前指针指向新节点
    p->next = newList;
    return true;
}

bool insertBefore(LinkedList list,int pos /* 索引 */,AnyType x)
{
    // 判断是否出界
    if (pos>length(list))
        return false;

    LinkedList p = list;
    int i = 0;
    // 找第 i-1 个节点
    while (p!=NULL && i < pos-1){
        p = p->next;
        i++;
    }
    if (p == NULL)
        return false;


    // 后面有节点
    LinkedList newList = newNode(p,NULL, x);
    p->next->prev = newList->next;
    p->next = newList;
    return true;
}

bool deleteElem(LinkedList list,int pos)
{
    LinkedList p =list;
    while (pos-->=0)
        p = p->next;
    /*
     * 首先先把前面的Node存在临时变量
     * 上一个Node指针指向下一个
     */
    LinkedList  tmp = list->prev;
    p->prev->next= p->next;
    p->next->prev= tmp;
    free(p);
}
int length(LinkedList list)
{
    int length = 0;
    LinkedList tmp = list;
    while ((tmp = tmp->next))
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
    LinkedList p = list;
    while(pos-->=0)
        p = p->next;
    return p->elem;
}

bool isEmpty(LinkedList list)
{
    return  ! list->next;
}

int searchElem(LinkedList list,AnyType x)
{
    int pos= 0;
    LinkedList p =list->next;
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
    LinkedList p = list->next;
    while (p !=NULL){
        printf("%d,",p->elem);
        p = p->next;
    }
}