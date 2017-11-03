//
// Created by luyanfcp on 17-10-11.
//

#ifndef TCPL_HEAP_H
#define TCPL_HEAP_H


#define error(x) printf("%s \n",x)

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define AnyType void*
#define MAXDATA 1000

typedef struct node *Heap;
struct node
{
    AnyType* heap;
    int len;
    int maxSize;
    int (*comp)(void *,void *);
};

Heap create(int /*size*/, int (*comp)(void*,void*));
bool isFull(Heap);
bool insert(Heap ,AnyType);
bool isEmpty(Heap);
AnyType deleteRoot(Heap);
void print(Heap);
bool destroyHeap(Heap);

#endif //TCPL_HEAP_H
