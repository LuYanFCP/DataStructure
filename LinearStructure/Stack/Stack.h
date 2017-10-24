//
// Created by luyanfcp on 17-10-20.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#endif //DATASTRUCTURE_STACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define AnyType void*
#define DEFAULT_VOLUME 20 //default_volume = 20
#define INCREMENT 10 // increment = 10
typedef struct sqStack *Stack;
struct sqStack{
    int top;
    int stackSize;
    AnyType *base;
};

Stack createStack();
bool destroyStack(Stack);
bool isEmpty(Stack);
int stackLength(Stack);
bool push(Stack, AnyType);
AnyType top(Stack);
AnyType pop(Stack);