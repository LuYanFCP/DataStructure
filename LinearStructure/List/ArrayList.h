//
// Created by luyanfcp on 17-10-20.
//

#ifndef DATASTRUCTURE_ARRAYLIST_H
#define DATASTRUCTURE_ARRAYLIST_H

#endif //DATASTRUCTURE_ARRAYLIST_H

#define DEFAULT_VOLUME 20 //default_volume = 20
#define INCREMENT 10 // increment = 10
#define MAX_VOLUME 1000
#define AnyType int
#define MAX_VALUE 2147483647

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List *ArrayList;
struct List{
    AnyType *elem;
    int length;
    int listSize;
};

ArrayList createList();
bool destroy(ArrayList);
bool insertElem(ArrayList,AnyType);
bool deleteElem(ArrayList,int);
int length(ArrayList);
bool clear(ArrayList);
AnyType getElem(ArrayList,int);
bool isEmpty(ArrayList);
int searchElem(ArrayList,AnyType);
void printList(ArrayList);
