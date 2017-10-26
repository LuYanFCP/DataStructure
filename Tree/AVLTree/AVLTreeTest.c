//
// Created by luyanfcp on 17-10-23.
//

#include "AVLTree.h"
int compare(void *x1,void *x2)
{
    int *x3 = (int*) x1;
    int *x4 = (int*) x2;
    return (*x3)>(*x4)?1:
                (*x3)<(*x4)? -1:0;
}

int main()
{
    int x = 3;
    AVLTree tree = createAVLTree(&x,compare);
    int test[] ={2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
    for (int i = 0; i <15; ++i) {
         tree = insert(tree,&test[i]);
    }
    NLR(tree);
    LDR(tree);
    levelTraversal(tree);

    destroyAVL(tree);
}