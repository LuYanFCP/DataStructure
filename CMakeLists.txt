cmake_minimum_required(VERSION 3.8)
project(DataStructure)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c BTree/BTree.c BTree/BTree.h LinearStructure/List/LinkedList.h LinearStructure/List/ArrayList.h LinearStructure/Stack/Stack.h LinearStructure/Query/Query.h LinearStructure/List/ArrayList.c)
add_executable(data_structure ${SOURCE_FILES})