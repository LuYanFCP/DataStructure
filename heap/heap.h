//
// Created by luyanfcp on 17-10-11.
//

#ifndef TCPL_HEAP_H
#define TCPL_HEAP_H

#endif //TCPL_HEAP_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define AnyType int
#define MAXDATA 1000

typedef struct node *MaxHeap;
struct node
{
    AnyType* heap;
    int len;
    int maxSize;
};

static void sink(MaxHeap , int);
MaxHeap create(int /*size*/);
bool isFull(MaxHeap);
bool insert(MaxHeap ,AnyType);
bool isEmpty(MaxHeap);
AnyType deleteMax(MaxHeap);
void print(MaxHeap);