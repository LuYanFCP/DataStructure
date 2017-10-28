//
// Created by luyanfcp on 17-10-20.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H


#define error(x) printf("x \n",x)
#define AnyType void*

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node *LNode;
typedef struct List *LinkedList;
struct Node{
    LNode next;
    LNode prev;
    AnyType elem;
};

struct List{
    LNode head;
    LNode tail;
    int size;
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
#endif //DATASTRUCTURE_LINKEDLIST_H
