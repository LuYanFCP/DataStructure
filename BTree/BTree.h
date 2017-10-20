//
// Created by luyanfcp on 17-10-15.
//

#ifndef DATA_STRUCTURE_BTREE_H
#define DATA_STRUCTURE_BTREE_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define M 4 //树的阶数
#define keytype int

typedef struct node *BTree;
struct node{
    int count; //记录当前节点有几个键
    keytype key[M+1]; //第一个位置空出来
    BTree prt[M+1];    //空出来第一个位置
};





#endif //DATA_STRUCTURE_BTREE_H
