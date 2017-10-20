//
// Created by luyanfcp on 17-10-20.
//
#include "ArrayList.h"




static arraycopy(void *src, void *dest, int length); // 拷贝数组的指定位置 到指定数组

ArrayList createList()
{
    ArrayList list = (ArrayList)malloc(sizeof(struct ArrayList));
    list->elem = malloc(DEFAULT_VOLUME*sizeof(AnyType));
    *list->elem++ = MAX_VALUE; //第一个设置为哨兵 ， 从第二个开始 第二个位置索引是0
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
    if (list->length == MAX_VOLUME)
        return false;
    //判断是否没有容量，如果没有按增量大小申请
    if(list->length==list->listSize) {
        list->elem = realloc(list->elem, INCREMENT);
        list->listSize += INCREMENT;
    }

    list->elem[list->length++] = x;
    return true;
}

static copy(AnyType *src, AnyType *dest, int length)
{

    while (length--)
        *dest++ = *src++;

}

bool deleteElem(ArrayList list,int pos)
{
    if (pos < list->length){
        /* 第一个参数为复制的数组指针，应该从post的下一个开始，
         * 第二个参数为复制到的数组指针，应该从post开始
         * 长度为 length - pos + 1
         */
        copy(list->elem+pos+1, list->elem+pos, (list->length - pos + 1));
        list->length--;
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
            return true;
    return false;
}