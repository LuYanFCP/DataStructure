//
// Created by luyanfcp on 17-10-11.
//
#include "heap.h"
#include <stdio.h>
/*
 * 此处实现一个堆
 */
static void sink(Heap  /*h*/, int /*k*/);

/*
 * Q：为什么把comp函数（compare）封装到 heap的结构中，而不是赋值给一个私
 * 有全局变量（赋值给私有变量，下面就可以直接调用不用在去heap里引用）？
 * A： comp是判定heap是否是最大堆或者最小堆的标志，付给heap更符合逻辑要求。
 */
Heap create(int size, int (*comp)(void*,void*))
{
    if (size<=0) {
        error("size less than 1");
        return NULL;
    }
    Heap heap = (Heap)malloc(sizeof(struct node));
    heap->heap = malloc((size+1)* sizeof(AnyType));
    heap->len = 0;
    heap->maxSize = size;
    heap->heap[0]= NULL;
    heap->comp = comp;
    return heap;
}

bool isFull(Heap heap)
{
    if(heap->maxSize == heap->len)
        return true;
    error("Heap is full!");
    return false;
};

bool isEmpty(Heap heap)
{
    return (bool) heap->len;
};

//static bool swim(AnyType)
//{
//
//};
// 下滤的实现
static void sink(Heap h, int k)
{
    int i = k*2;
    int j = k*2+1;
    int (*compare)(void*,void*)= h->comp;
    if (i > h->len)
        return ;
    if (compare(h->heap[i], h->heap[j])>=0) {
        h->heap[k] = h->heap[i];
        sink(h, i);
    }
    else{
        h->heap[k] = h->heap[j];
        sink(h,k);
    }
    // 如何判断停止
};


bool insert(Heap h,AnyType x)
{
    int (*compare)(void*,void*)= h->comp;
    if (isFull(h))
        return false;

    int i = ++h->len;
    for (;compare(x,h->heap[i/2])>=0;i/=2) {
        h->heap[i] = h->heap[i/2];
    }
    h->heap[i] = x;
    return true;
};

AnyType deleteRoot(Heap h)
{
    AnyType x = h->heap[1];
    sink(h,1);
    h->len--;
    return x;
};

bool destroyHeap(Heap heap)
{
    free(heap->heap);
    free(heap);
}

//void print(Heap h)
//{
//    for (int i = 1; i<=h->len ; ++i) {
//        printf("%d,",h->heap[i]);
//    }
//};