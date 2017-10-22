//
// Created by luyanfcp on 17-10-15.
//

#ifndef TCPL_BPTREE_H
#define TCPL_BPTREE_H

#endif //TCPL_BPTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define M 1

typedef int typekey;

typedef struct btnode *btp;  //B树节点指针
typedef struct btnode node;
struct btnode{
    int d;
    typekey k[2*M];
    char *v[2*M];
    btp p[2*M+1];
};

int btree_disp; //查找时找到的键在节点的位置
char *InsValue; //与要插的键相对应的值

btp search(typekey,btp);
btp insert(typekey,btp);
btp delete(typekey,btp);
int height(btp);
int count(btp);
double payload(btp);
btp deltree(btp);

