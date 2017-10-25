//
// Created by luyanfcp on 17-10-4.
////
#include "AVLTree.h"
#include "../../LinearStructure/Stack/Stack.h"
#include "../../LinearStructure/Queue/LinkedQueue.h"
//#include <stdlib.h>
//#include <stddef.h>
//#include <stdio.h>
//#define ALLOWED_IMBALANCE 1
//
//typedef struct node *AVLTree;
////typedef Position ALVTree;
//struct node{
//    AVLTree right;
//    AVLTree left;
//    int elem;
//    int high;  //从改节点到叶子的最长路径
//};
//
//AVLTree createAVLTree(int);
//AVLTree insert(AVLTree, int);
//AVLTree AVLremove(AVLTree, int);
//
//AVLTree findMin(AVLTree);
static AVLTree balance(AVLTree /*t*/);
static AVLTree rotateWithLeftChild(AVLTree /*t1*/);
static AVLTree doubleRotateWithLeftChild(AVLTree /*t1*/);
static AVLTree rotateWithRightChild(AVLTree /*t1*/);
static AVLTree doubleRotateWithRightChild(AVLTree /*t1*/);

int max(int /*a*/, int /*b*/);

int max(int a, int b)
{
    return a > b ? a : b;
}

static int height(AVLTree T)
{
    return T ? (T->high) : -1;
}

AVLTree createAVLTree(int x)
{
    AVLTree t = (AVLTree)malloc(sizeof(struct node));
    t->elem = x;
    t->high = 0;
    t->right = NULL;
    t->left = NULL;
    return t;
}
AVLTree insert(AVLTree t, int x)
{
    //判断传入是否为空指针
    if(!t)
        return createAVLTree(x);
    if(x < t->elem)
        t->left = insert(t->left, x);
    if(x > t->elem)
        t->right = insert(t->right, x);
    t = balance(t);
    return t;
}

static AVLTree balance(AVLTree t)
{
    if (!t)
        return t;
    if (height(t->left)-height(t->right)>ALLOWED_IMBALANCE)
        if (height(t->left->left)>=height(t->left->right))
            t = rotateWithLeftChild(t);
        else
            t = doubleRotateWithLeftChild(t);
    else
        if (height(t->right)-height(t->left)>ALLOWED_IMBALANCE)
            if (height(t->right->right)>=height(t->right->left))
                t = rotateWithRightChild(t);
            else
                t = doubleRotateWithRightChild(t);

    t->high = max(height(t->left),height(t->right))+1;
    return t;
}

static AVLTree rotateWithLeftChild(AVLTree t1)
{
    AVLTree t2 = t1->left;
    t1->left = t2->right;
    t2->right = t1;
    t1->high = max(height(t1->right), height(t1->left))+1;
    t2->high = max(height(t1),height(t2->left))+1;
    return  t2;
}

static AVLTree doubleRotateWithLeftChild(AVLTree t1)
{
    t1->left=rotateWithRightChild(t1->left);
    return rotateWithLeftChild(t1);
}

static AVLTree rotateWithRightChild(AVLTree t1)
{
    AVLTree t2 = t1->right;
    t1->right = t2->left;
    t2->left = t1;
    t1->high = max(height(t1->right), height(t1->left))+1;
    t2->high = max(height(t1),height(t2->left))+1;

    return t2;
}

static AVLTree doubleRotateWithRightChild(AVLTree t1)
{
    t1->right=rotateWithLeftChild(t1->right);
    return rotateWithRightChild(t1);
}

AVLTree AVLremove(AVLTree t, int x)
{
    if(!t)
        return t;
    if(x > t->elem)
        AVLremove(t->right,x);
    else if(x < t->elem)
        AVLremove(t->left,x);
    else if (t->left!=NULL && t->right!=NULL){
        t->elem = findMin(t->right)->elem;
        t->right = AVLremove(t->right, t->elem);
    } else
        t = t->left? t->left:t->right;
}

AVLTree findMin(AVLTree t)
{
    if(t->left==NULL)
        return t;
    findMin(t->left);
}
//先序列遍历
void NLR(AVLTree t)
{
//    if(t){
//        printf("%d \n",t->elem);
//        NLR(t->left);
//        NLR(t->right);
//    }
    /*
     * 用栈实现递归操作
     */
    printf("[");
    AVLTree T = t;
    Stack stack = createStack();
    while (T!=NULL || !isEmpty(stack))
    {
        while(T){
            push(stack,T);
            printf("%d, ",T->elem);
            T = T->left;
        }
        if (!isEmpty(stack)){
            T = pop(stack);
            T = T->right;
        }
    }
    printf("]\n");
}

void LDR(AVLTree tree)
{
    AVLTree T = tree;
    Stack stack = createStack();
    while (T!=NULL || !isEmpty(stack))
    {
        while(T){
            push(stack,T);
            T = T->left;
        }
        if (!isEmpty(stack)){
            T = pop(stack);
            printf("%d \n",T->elem);
            T = T->right;
        }
    }
}
void LRN(AVLTree tree)
{
    printf("[");
    AVLTree T = tree;
    Stack stack = createStack();
    while (T!=NULL || !isEmpty(stack))
    {
        while(T){
            push(stack,T);
            printf("%d, ",T->elem);
            T = T->left;
        }
        if (!isEmpty(stack)){
            T = pop(stack);
            T = T->right;
        }
    }
    printf("]\n");
};

void levelTraversal(AVLTree tree)
{
    printf("[");
    AVLTree t = NULL;
    LinkedQueue queue = createQueue();
    EnQueue(queue,tree);
    while (!isQueueEmpty(queue)) {
        t = DeQueue(queue);
        printf("%d, ",t->elem);
        if (t->left)
            EnQueue(queue, t->left);
        if (t->right)
            EnQueue(queue, t->right);
    }
    printf("]\n");
};

bool destroyAVL(AVLTree tree)
{
    AVLTree tmp = NULL; //用于释放内存的临时变量
    AVLTree T = tree;
    Stack stack = createStack();
    while (T || !isEmpty(stack))
    {
        while(T){
            push(stack,T);
            T = T->left;
        }
        if (!isEmpty(stack)){
            T = pop(stack);
            tmp =T;
            T = T->right;
            free(tmp);
        }
    }
}