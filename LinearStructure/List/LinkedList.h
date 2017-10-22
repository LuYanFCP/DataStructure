//
// Created by luyanfcp on 17-10-20.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#endif //DATASTRUCTURE_LINKEDLIST_H

#define MAXVALUE 2147483647 // 哨兵
#define AnyType int

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node *LinkedList;
struct Node{
    LinkedList next;
    LinkedList prev;
    AnyType elem;
};
/*
 * 传入的LinkedList一直为初始那个
 */

LinkedList createList();
bool destroy(LinkedList);
bool insertElem(LinkedList,AnyType);
bool deleteElem(LinkedList,int);
int length(LinkedList);
bool clear(LinkedList);
AnyType getElem(LinkedList,int);
bool isEmpty(LinkedList);
int searchElem(LinkedList,AnyType);
bool insertAfter(LinkedList,int,AnyType);
bool insertBefore(LinkedList,int,AnyType);

void printList(LinkedList);