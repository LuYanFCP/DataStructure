cmake_minimum_required(VERSION 3.8)
project(DataStructure)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES LinearStructure/Stack/Stack.c LinearStructure/Stack/StackTest.c)
add_executable(data_structure ${SOURCE_FILES})