//
// Created by luyanfcp on 17-10-22.
//
//#include "LinkedQueue.h"
#include <stdio.h>
#include "Queue.h"

int main()
{
//    LinkedQueue  queue = createQueue();
//    for (int i = 0; i < 10 ; ++i) {
//        EnQueue(queue, i*i);
//    }
//    printf("length--> %d \n",queueLength(queue));
//    for (int j = 0; j < 10; ++j) {
//        printf("%d-->%d \n",j,DeQueue(queue));
//    }
//    printf("length--> %d \n",queueLength(queue));
//
//    destroyQueue(queue);
/*
 * Test cycleQueue
 */
    Queue queue = createQueue(10);
    for (int i = 0; i <11 ; ++i) {
        EnQueue(queue,i*i);
    }
    printf("isFull:%d \n",isFull(queue));
    for (int j = 0; j <10 ; ++j) {
        printf("%d->%d \n",j,DeQueue(queue));
    }
    printf("isFull:%d \n",isFull(queue));
    printf("isEmpty:%d \n",isEmpty(queue));

    destroyQueue(queue);
}
