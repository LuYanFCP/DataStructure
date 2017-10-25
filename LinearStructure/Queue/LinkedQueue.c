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
    queue->rear = queue->front = (QueuePtr) malloc(sizeof(struct QNode));
    queue->front->next = NULL;
    return queue;
}

// - [x] 有问题 未测试
static bool freeNodes(LinkedQueue queue)
{
    QueuePtr next = queue->front->next;
    QueuePtr tmp;
    while (next){
        tmp = next;
        next = next->next;
        free(tmp);
    }
    return true;
}

bool destroyQueue(LinkedQueue queue)
{
    freeNodes(queue);
    free(queue->front);
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
    queue->rear = queue->front;
}
bool isQueueEmpty(LinkedQueue queue)
{
    return !queue->length;
}
//bool isFull(LinkedQueue);
int queueLength(LinkedQueue queue)
{
    return queue->length;
}

bool EnQueue(LinkedQueue queue,AnyType x)
{
    QueuePtr newNode = (QueuePtr)malloc(sizeof(struct QNode));
    queue->length++;
    newNode->next = NULL;
    newNode->data = x;
    queue->rear->next = newNode;
    queue->rear = newNode;
    return true;
}
AnyType DeQueue(LinkedQueue queue)
{
    if (isQueueEmpty(queue))
        return false;
    QueuePtr tmp = queue->front->next;
    queue->front->next = queue->front->next->next;
    AnyType result = tmp->data;
    free(tmp);
    queue->length--;
    /*
     * 如果最后长度为1的时候删去节点之后queue->rear要归位
     */
    if (isQueueEmpty(queue))
        queue->rear = queue->front;
    return result;
}