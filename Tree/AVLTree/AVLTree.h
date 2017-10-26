//
// Created by luyanfcp on 17-10-8.
//

#ifndef TCPL_AVLTREE_H
#define TCPL_AVLTREE_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#define ALLOWED_IMBALANCE 1
#define AnyType void*
#define error(x) printf("%s \n",x)
typedef struct node *AVLTree;
//typedef Position ALVTree;
struct node{
    AVLTree right;
    AVLTree left;
    AnyType elem;
    int high;  //从改节点到叶子的最长路径
};

AVLTree createAVLTree(AnyType,int (*compare)(void*,void*));
AVLTree insert(AVLTree, AnyType);
AVLTree AVLremove(AVLTree, AnyType);
AVLTree findMin(AVLTree);
void NLR(AVLTree);
void LDR(AVLTree);
void LRN(AVLTree);
void levelTraversal(AVLTree);
bool destroyAVL(AVLTree);
#endif //TCPL_AVLTREE_H
