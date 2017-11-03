cmake_minimum_required(VERSION 3.8)
project(DataStructure)

set(CMAKE_C_STANDARD 99)

#set(SOURCE_FILES  LinearStructure/Stack/Stack.c Tree/AVLTree/AVLTree.c Tree/AVLTree/AVLTreeTest.c)
#set(SOURCE_FILES LinearStructure/Stack/Stack.c LinearStructure/Stack/StackTest.c)
#set(SOURCE_FILES LinearStructure/Queue/LinkedQueue.c LinearStructure/Queue/QueueTest.c)
#set(SOURCE_FILES LinearStructure/Queue/Queue.c LinearStructure/Queue/QueueTest.c)

#set(SOURCE_FILES LinearStructure/List/LinkedList.c LinearStructure/List/ListTest.c)

#set(SOURCE_FILES Tree/AVLTree/AVLTree.c Tree/AVLTree/AVLTreeTest.c LinearStructure/Stack/Stack.c LinearStructure/Queue/LinkedQueue.c)
set(SOURCE_FILES Graph/AdjacentList.c Graph/GraphTest.c LinearStructure/Queue/Queue.c LinearStructure/Stack/Stack.c Tree/DijSets.c LinearStructure/List/ArrayList.c)
#set(SOURCE_FILES String/matchAlgorithm.c Tree/DisjSets.h Tree/DijSets.c)
#set(SOURCE_FILES main.c)
add_executable(data_structure ${SOURCE_FILES})