cmake_minimum_required(VERSION 3.8)
project(DataStructure)

set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES  LinearStructure/Stack/Stack.c Tree/AVLTree/AVLTree.c Tree/AVLTree/AVLTreeTest.c)
#set(SOURCE_FILES LinearStructure/Stack/Stack.c LinearStructure/Stack/StackTest.c)
#set(SOURCE_FILES LinearStructure/Queue/LinkedQueue.c LinearStructure/Queue/QueueTest.c)
#set(SOURCE_FILES LinearStructure/Queue/Queue.c LinearStructure/Queue/QueueTest.c)

#set(SOURCE_FILES LinearStructure/List/LinkedList.c LinearStructure/List/ListTest.c)

set(SOURCE_FILES heap/heap.c heap/heapTest.c)
add_executable(data_structure ${SOURCE_FILES})