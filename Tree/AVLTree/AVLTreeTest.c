//
// Created by luyanfcp on 17-10-23.
//

#include "AVLTree.h"

int main()
{
    AVLTree tree = createAVLTree(3);
    int test[] ={2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
    for (int i = 0; i <15; ++i) {
         tree = insert(tree,test[i]);
    }
    NLR(tree);
    levelTraversal(tree);

    destroyAVL(tree);
}