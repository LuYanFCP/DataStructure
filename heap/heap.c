//
// Created by luyanfcp on 17-10-11.
//
#include "heap.h"
#include <stdio.h>
/*
 * 此处实现一个最小堆
 */



MaxHeap create(int size)
{
    if (size<=0)
        return NULL;
    MaxHeap heap = (MaxHeap)malloc(sizeof(struct node));
    heap->heap = malloc((size+1)* sizeof(AnyType));
    heap->len = 0;
    heap->maxSize = size;
    heap->heap[0]= MAXDATA;

    return heap;
}

bool isFull(MaxHeap heap)
{
    if(heap->maxSize == heap->len)
        return true;
    return false;
};

bool isEmpty(MaxHeap heap)
{
    return (bool) heap->len;
};

//static bool swim(AnyType)
//{
//
//};
// 下滤的实现
static void sink(MaxHeap h, int k)
{
    int i = k*2;
    int j = k*2+1;
    if (i > h->len)
        return ;
    if (h->heap[i] >= h->heap[j]) {
        h->heap[k] = h->heap[i];
        sink(h, i);
    }
    else{
        h->heap[k] = h->heap[j];
        sink(h,k);
    }
    // 如何判断停止
};


bool insert(MaxHeap h,AnyType x)
{
    if (isFull(h))
        return false;
    int i = ++h->len;
    for (; h->heap[i/2]<x;i/=2) {

        h->heap[i] = h->heap[i/2];
    }
    h->heap[i] = x;
    return true;
};

AnyType deleteMax(MaxHeap h)
{
    AnyType x = h->heap[1];
    sink(h,1);
    h->len--;
    return x;
};

void print(MaxHeap h)
{
    for (int i = 1; i<=h->len ; ++i) {
        printf("%d,",h->heap[i]);
    }
};