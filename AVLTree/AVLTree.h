//
// Created by luyanfcp on 17-10-8.
//

#ifndef TCPL_AVLTREE_H
#define TCPL_AVLTREE_H

#endif //TCPL_AVLTREE_H
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#define ALLOWED_IMBALANCE 1
typedef struct node *AVLTree;
//typedef Position ALVTree;
struct node{
    AVLTree right;
    AVLTree left;
    int elem;
    int high;  //从改节点到叶子的最长路径
};

AVLTree createAVLTree(int);
AVLTree insert(AVLTree, int);
AVLTree AVLremove(AVLTree, int);

AVLTree findMin(AVLTree);
void NLR(AVLTree);