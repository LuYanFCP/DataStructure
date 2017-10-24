//
// Created by luyanfcp on 17-10-20.
//
#include "ArrayList.h"

ArrayList createList()
{
    ArrayList list = (ArrayList)malloc(sizeof(struct List));
    list->elem = malloc(DEFAULT_VOLUME*sizeof(AnyType));
    list->length = 0;
    list->listSize = DEFAULT_VOLUME;
    return list;
}

bool destroy(ArrayList list)
{
    free(list->elem);
    free(list);
    return true;
}

bool insertElem(ArrayList list,AnyType x)
{
    //首先判断是否到最大边界，如果到了返回false
    if (list->length == MAX_VOLUME) {
        printf("go beyond the limit \n");
        return false;
    }
    //判断是否没有容量，如果没有按增量大小申请
    if(list->length==list->listSize) {
        list->elem = realloc(list->elem, (list->listSize + INCREMENT)*sizeof(AnyType));
        list->listSize += INCREMENT;
    }

    list->elem[list->length++] = x;
    return true;
}

static void copy(AnyType *src, AnyType *dest, int len)
{
    // 把 src 中的len个元素复制到 dest 中
    while (--len)
        *dest++ = *src++;
}

bool deleteElem(ArrayList list,int pos)
{
    if (pos < list->length){
        /* 第一个参数为复制的数组指针，应该从post的下一个开始，
         * 第二个参数为复制到的数组指针，应该从post开始
         * 长度为 length - pos + 1
         */
        // 如果刚好最后一个在边界可能会溢出 √ 已解决
        copy(list->elem+pos+1, list->elem+pos, (list->length - pos + 1));
        list->length--;
        return true;
    }
    return false;
}
int length(ArrayList list)
{
    return list->length;
}
bool clear(ArrayList list)
{
    list->length = 0;
    return true;
}
AnyType getElem(ArrayList list,int pos)
{
    return list->elem[pos];

}
bool isEmpty(ArrayList list)
{
    return !list->length;
}
int searchElem(ArrayList list,AnyType x)
{
    for (int i = 0; i < list ->length ; ++i)
        if (list->elem[i] == x)
            return i;
    return -1;
}
void printList(ArrayList list)
{
    printf("[ ");
    for (int i = 0; i < list->length ; ++i) {
        printf("0x%p, ",list->elem[i]);
    }
    printf("]\n");
}