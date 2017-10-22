//
// Created by luyanfcp on 17-10-22.
//

#include "LinkedQueue.h"

LinkedQueue  createQueue()
{
    LinkedQueue queue = (LinkedQueue) malloc(sizeof(struct Queue));
    queue->length = 0;
    queue->rear = queue->rear =NULL;
    return queue;
}
bool destroyQueue(LinkedQueue queue)
{
    QueuePtr rear = queue->rear;
    QueuePtr tmp;
    while (rear){
        tmp = rear;
        rear = rear->next;
        free(tmp);
    }
    free(queue);
}
/*
 *  问题: clearQueue 方法到底回收不回收 Node
 */
bool clearQueue(LinkedQueue);
bool isEmpty(LinkedQueue queue)
{
    return queue->front == queue->rear;
}
//bool isFull(LinkedQueue);
int queueLength(LinkedQueue queue)
{
    return queue->length;
}
bool EnQueue(LinkedQueue queue,AnyType x)
{
    
}
AnyType DeQueue(LinkedQueue);