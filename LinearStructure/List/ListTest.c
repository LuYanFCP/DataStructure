//
// Created by luyanfcp on 17-10-21.
//
//#include "ArrayList.h"
#include "LinkedList.h"
int main()
{
    /*
     * 测试 ArrayList
     */
//    ArrayList arrlist = createList();
//    for (int i = 0; i < 30; ++i) {
//        insertElem(arrlist,&i);
//    }
//    printf("arrlist->length: %d \n",arrlist->length);
//    printList(arrlist);
//
//    deleteElem(arrlist,5);
////    deleteElem(arrlist,6);
//    printList(arrlist);
////    printf("arrlist[11]: %d \n",getElem(arrlist,10));
////    printf("15-index: %d \n",searchElem(arrlist,15));
//
//    destroy(arrlist);









    /*
     * 测试LinkedList
     */
    LinkedList linkedList = createList();
    for (int i = 0; i < 20 ; ++i) {
        insertElem(linkedList,i);
    }
    int l = length(linkedList);
    printf("linkedList->length: %d \n",l);

    printList(linkedList);
//    // 删除几个值
    deleteElem(linkedList,5);
    deleteElem(linkedList,6);
    l = length(linkedList);
    printf("linkedList->length: %d \n",l);
    printList(linkedList);
    printf("\n");

    //查找测试

    printf("19 - index: %d \n",searchElem(linkedList,19));

    destroy(linkedList);


}