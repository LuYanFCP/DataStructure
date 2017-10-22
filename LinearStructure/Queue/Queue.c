//
// Created by luyanfcp on 17-10-21.
//

#include "Queue.h"

Queue createQueue(int volume)
{
    Queue queue = (Queue)malloc(sizeof(struct SqQueue));
    queue->elem = (AnyType)malloc(volume*sizeof(AnyType));
    queue->volume = volume;
    queue->front = 0;
    queue->rear = 0;   // 尾指针指向最后一个元素的后一位
    queue->length = 0;
}

bool destroyQueue(Queue queue)
{
    free(queue->elem);
    free(queue);
    return true;
}

bool clearQueue(Queue queue)
{
    queue->front = 0;
    queue->rear = 0;
    queue->length = 0;
    return true;
}

bool isEmpty(Queue queue)
{
    // 空的时候长度为0
    return !queue->length;
}

bool isFull(Queue queue)
{
    // 直接判断长度是否等于容量
    return queue->length == queue->volume;
}

int queueLength(Queue queue)
{
    return queue->length;
}

bool EnQueue(Queue queue,AnyType x)
{
    // 判断是否满
    if (isFull(queue))
        return false;
    // 获取下一个位置的索引值
    // 如果超过valume-1 直接做 mod 得到新的索引
    (++queue->front)%=queue->volume;
    queue->elem[queue->front] = x;
    queue->length++;
    return true;

}

AnyType DeQueue(Queue queue)
{
    if (isEmpty(queue))
        return false;
    // 直接做和入队同样的操作
    (++queue->rear) %= queue->volume;
    queue->length--;
    return queue->elem[queue->rear];
}
