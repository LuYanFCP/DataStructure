//
// Created by luyanfcp on 17-10-20.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#endif //DATASTRUCTURE_LINKEDLIST_H

#define AnyType int

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node *LinkedList;
struct Node{
    LinkedList next;
    LinkedList prev;
    AnyType elem;
};


LinkedList createList();
bool destroy(LinkedList);
bool insertElem(LinkedList,AnyType);
bool deleteElem(LinkedList,int);
int length(LinkedList);
bool clear(LinkedList);
AnyType getElem(LinkedList,int);
bool isEmpty(LinkedList);
int searchElem(LinkedList,AnyType);
