//
// Created by luyanfcp on 17-10-22.
//

#ifndef DATASTRUCTURE_LINKEDQUEUE_H
#define DATASTRUCTURE_LINKEDQUEUE_H

#endif //DATASTRUCTURE_LINKEDQUEUE_H

#define AnyType void*

#include <stdbool.h>
#include <stdlib.h>



typedef struct QNode *QueuePtr;
typedef struct Queue *LinkedQueue;
struct QNode {
    AnyType data;
    QueuePtr next;
};
struct Queue{
    QueuePtr front;
    QueuePtr rear;
    int length;
};

LinkedQueue  createQueue();
bool destroyQueue(LinkedQueue);
bool clearQueue(LinkedQueue);
bool isQueueEmpty(LinkedQueue);
//bool isFull(LinkedQueue); LinkedQueue 不会满
int queueLength(LinkedQueue);
bool EnQueue(LinkedQueue,AnyType);
AnyType DeQueue(LinkedQueue);