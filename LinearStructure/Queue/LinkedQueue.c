//
// Created by luyanfcp on 17-10-22.
//


#include "LinkedQueue.h"

//static struct QNode cache[5];  Node缓存

static bool freeNodes(LinkedQueue /*queue*/);

LinkedQueue  createQueue()
{
    LinkedQueue queue = (LinkedQueue) malloc(sizeof(struct Queue));
    queue->length = 0;
    queue->rear = queue->rear = (QueuePtr) malloc(sizeof(struct QNode));
    queue->front->next = NULL;
    return queue;
}

// - [x] 有问题 未测试
static bool freeNodes(LinkedQueue queue)
{
    QueuePtr rear = queue->rear->next;
    QueuePtr tmp;
    while (rear){
        tmp = rear;
        rear = rear->next;
        free(tmp);
    }
    return true;
}

bool destroyQueue(LinkedQueue queue)
{
    freeNodes(queue);
    free(queue);
}

/*
 *  问题: clearQueue 方法到底回收不回收 Node
 *  11.22 解决办法：回收
 */

bool clearQueue(LinkedQueue queue)
{
    freeNodes(queue);
    queue->length = 0;
    queue->front = queue->rear;
}
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
    QueuePtr newNode = malloc(sizeof(struct QNode));
    newNode->next = NULL;
    newNode->data = x;
    queue->front->next = queue->front = newNode;
    return true;
}
AnyType DeQueue(LinkedQueue queue)
{
    if (isEmpty(queue))
        return false;
    QueuePtr tmp = queue->rear->next;
    queue->rear->next = tmp->next;
    AnyType result = queue->rear->data;
    free(tmp);
    return result;
}