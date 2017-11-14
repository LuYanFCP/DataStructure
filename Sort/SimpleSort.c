//
// Created by luyanfcp on 17-11-13.
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *x, int *y);
void test(const int *x, int size)
{
    for (int i = 1; i < size; ++i) {
        if (x[i]<x[i-1]){
            printf("sort error!\n");
            return;
        }

    }
    printf("sort right!\n");
}

void insertSort(int* arr, int size)
{
    int tmp,j;
    for (int i = 1; i < size; ++i) {
        tmp = arr[i];
        for (j = i; j > 0 && tmp < arr[j-1] ; --j) swap(arr+j-1,arr+j);
        arr[j] = tmp;
    }
    /*优化插入排序，用二分法*/
}

void bubbleSort(int* arr,int size)
{
    for (int i = 0; i < size-1 ; ++i) {
        for (int j = 0; j < size-1-i; ++j) {
            if (arr[j] > arr[j+1])
                swap(arr+j,arr+j+1);
        }
    }
    /*优化的冒泡排序*/

}

void swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

int main()
{
//    int size;
//    printf("请输入要排序元素的个事:");
//    scanf("%d",&size);
//    int arr[size];
//    for (int i = 0; i < size; ++i)
//        scanf("%d",arr+i);
//    printf("输入完毕显示排序结果与时间:\n");

    srand((unsigned)time(NULL));

    const int SIZE = 30000;
    int arr[SIZE];
    int arr1[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100 + 1;
        arr1[i] = arr[i];
    }

    long start,end;
    start = clock();
    insertSort(arr,SIZE);
    end = clock();
    test(arr,SIZE);
    printf("insertSort 用时:%f ms \n",  ((double) (end - start) / CLOCKS_PER_SEC));

    start = clock();
    bubbleSort(arr1,SIZE);
    end = clock();
    test(arr1,SIZE);
    printf("bubbleSort 用时:%f ms \n",  ((double) (end - start) / CLOCKS_PER_SEC));
}