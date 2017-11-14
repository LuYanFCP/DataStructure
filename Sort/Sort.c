//
// Created by luyanfcp on 17-11-14.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define error(x) printf("%s\n",x)
/*
 * 1. shellSort
 * 2. heapSort
 * 3. mergSort
 * 4. quickSort
 * 5. bucketSort
 * 6. radixSort
 * 7. countingSort
 */
/*辅助方法*/
void swap(int *x, int *y);
void test(const int *x, int size);
/*排序算法*/
void insertSort(int* arr, int size);
void bubbleSort(int* arr,int size);
void shellSort(int *arr,int size);
void heapSort(int *arr,int size);
void mergeSort(int *arr,int size);
void quickSort(int *arr,int size);



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

void bubbleSort(int *arr,int size)
{
    for (int i = 0; i < size-1 ; ++i) {
        for (int j = 0; j < size-1-i; ++j) {
            if (arr[j] > arr[j+1])
                swap(arr+j,arr+j+1);
        }
    }
    /*优化的冒泡排序*/
}

void shellSort(int *arr,int size)
{
    /*采用经典的shell推荐序列*/
    int j;
    for (int gap = size/2; gap >0 ; gap/=2) {
        for (int i = gap; i < size; ++i) {
            int tmp = arr[i];
            for (j = i; j >= gap && tmp < arr[j-gap] ; j -= gap) arr[j] = arr[j-gap];
            arr[j] = tmp;
        }
    }
}
static percDown(int *a, int i, int n);
void heapSort(int *arr,int size)
{
    for (int i = size/2 - 1; i >=0 ; --i) { /*build heap*/
        percDown(arr,i,size);
    }
    for (int j = size - 1; j >0 ; --j) {
        swap(arr,arr+j);
        percDown(arr,0,j);
    }
}
static percDown(int *a, int i, int n)
{
    int child;
    int tmp;
    for (tmp = a[i]; n > (2*i + 1); i = child) {
        child = 2*i + 1;
        if (child != n-1 && a[child]<a[child+1])
            child++;
        if (tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}

void merge_sort(int *arr,int *tmp,int size,int left,int right)
{
    if (left >= right){
        error("left>=right");
        return;
    }
    int mid = (left+right)/2;
    // 进行递归处理
    merge_sort(arr,tmp,size,left,mid);
    merge_sort(arr,tmp,size,mid+1,right);

    //以下为排序
    if (right-left != size-1){ //判断不是第一个
        int posl = left;
        int posr = mid+1;
        int tmppos = left;
        while (posl<=mid && posr<=right){
            if (arr[posl]<arr[posr])
                tmp[tmppos++] = arr[posl++];
            else
                tmp[tmppos++] = arr[posr++];
        }

        while(posl<=mid){
            tmp[tmppos++] = arr[posl++];
        }
        while(posr<=mid){
            tmp[tmppos++] = arr[posr++];
        }
    }

    /*把 tmp中的元素复制回去*/
    for (int i = left; i < right+1; ++i) arr[i] = tmp[i];

}

void mergeSort(int *arr,int size)
{
    int tmp[size];
    merge_sort(arr,tmp,size,0,size-1);
}
void quickSort(int *arr,int size)
{

}

/*辅助方法*/
void swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}
/*测试排序的算法*/
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

printTime(void (*sort)(int*,int), const int *array, int size, char *name)
{
    int arr[size];
    for (int i = 0; i <size ; ++i){
        arr[i] = array[i];
    }
    long start,end;
    start = clock();
    sort(arr,size);
    end = clock();
    test(arr,size);
    printf("%s 用时:%f s \n", name, ((double) (end - start) / CLOCKS_PER_SEC));
}

int main()
{
    srand((unsigned)time(NULL));

    const int SIZE = 30000;
    int arr[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    printTime(insertSort,arr,SIZE,"insertSort");
    printTime(shellSort,arr,SIZE,"shellSort");
    printTime(heapSort,arr,SIZE,"heapSort");
    printTime(mergeSort,arr,SIZE,"mergeSort");
//    start = clock();
//    shellSort(arr1,SIZE);
//    end = clock();
//    test(arr1,SIZE);
//    printf("shellSort 用时:%f s \n",  ((double) (end - start) / CLOCKS_PER_SEC));

}