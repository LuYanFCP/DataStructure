//
// Created by luyanfcp on 17-10-21.
//

#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#endif //DATASTRUCTURE_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define AnyType void*

typedef struct SqQueue *Queue;
struct SqQueue{
    AnyType *elem;
    int front;
    int rear;
    int volume;
    int length;
};

Queue createQueue(int/*容量*/);
bool destroyQueue(Queue);
bool clearQueue(Queue);
bool isQueueEmpty(Queue);
bool isQueueFull(Queue);
int queueLength(Queue);
bool EnQueue(Queue,AnyType);
AnyType DeQueue(Queue);
