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


void insert_sort(int *arr, int left, int right);
void insert_sortOptimize(int *arr, int left, int right);

void insertSort(int* arr, int size)
{
    insert_sort(arr,0,size-1);
}


void halfInsertSort(int* arr, int size)
{
    insert_sortOptimize(arr,0,size-1);
}

void insert_sort(int *arr, int left, int right)
{
    int tmp,j;
    for (int i = left+1; i <= right; ++i) {
        tmp = arr[i];
        for (j = i; j > 0 && tmp < arr[j-1] ; --j) arr[j]=arr[j-1];
        arr[j] = tmp;
    }
}


void insert_sortOptimize(int *arr, int left, int right)
{
    /*优化插入排序，用二分法*/
    int tmp,j;
    int low,high,m;
    for (int i = left+1; i <= right; ++i) {
        tmp = arr[i];
        low = left;
        high = i-1;
        while (low<=high){
            m = (low+high)>>1;
            if (arr[m]<tmp){
                low = m+1;
            } else high = m-1;
        }
        /*复制向后，然后把第 i 元素放在low的位置*/
        for (j = i-1; j >=high ; --j) {
            arr[j+1] = arr[j];
        }

        arr[high+1] = tmp;
    }
};


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
static void percDown(int *a, int i, int n);

void quick_sort(int*arr, int size, int left, int right)
;

void heapSort(int *arr, int size)
{
    for (int i = size/2 - 1; i >=0 ; --i) { /*build heap*/
        percDown(arr,i,size);
    }
    for (int j = size - 1; j >0 ; --j) {
        swap(arr,arr+j);
        percDown(arr,0,j);
    }
}
static void percDown(int *a, int i, int n)
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

void merge(int *a, int *tmp, int leftpos, int rightpos, int rightEnd)
{
    int leftEnd = rightpos-1;
    int tmpPos = leftpos;
    int numElements = rightEnd-leftpos+1;

    while (leftpos<=leftEnd && rightpos <= rightEnd)
        if (a[leftpos]<=a[rightpos])
            tmp[tmpPos++] = a[leftpos++];
        else
            tmp[tmpPos++] = a[rightpos++];
    while (leftpos<=leftEnd)
        tmp[tmpPos++] = a[leftpos++];
    while (rightpos<=rightEnd)
        tmp[tmpPos++] = a[rightpos++];
    for (int i = 0; i < numElements; ++i,rightEnd--) {
        a[rightEnd] = tmp[rightEnd];
    }
}

void merge_sort(int *arr,int *tmp,int size,int left,int right)
{
    if (left >= right){
//        error("left>=right");
        return;
    }
    int mid = (left+right)/2;
    // 进行递归处理
    merge_sort(arr,tmp,size,left,mid);
    merge_sort(arr,tmp,size,mid+1,right);
//    merge(arr,tmp,left,mid+1,right);
    //以下为排序
    //判断不是第一个
    int posl = left;
    int posr = mid+1;
    int tmppos = left;

    while (posl<=mid && posr<=right) {
        if (arr[posl] < arr[posr])
            tmp[tmppos++] = arr[posl++];
        else
            tmp[tmppos++] = arr[posr++];
    }

    while(posl<=mid){
        tmp[tmppos++] = arr[posl++];
    }

    while(posr<=right){
        tmp[tmppos++] = arr[posr++];
    }
    /*把 tmp中的元素复制回去*/
    for (int i = left; i <= right; ++i) arr[i] = tmp[i];
}


void mergeSort(int *arr,int size)
{
    int tmp[size];
    merge_sort(arr,tmp,size,0,size-1);
}

void quickSort(int *arr,int size)
{
    quick_sort(arr,size,0,size-1);
}

#define CUTOFF 10

int median3(int *arr, int left, int right)
{
    int center = (right + left) /2;
    if (arr[center] < arr[left])
        swap(arr + center, arr + left);
    if (arr[right] < arr[left])
        swap(arr + right, arr + left);
    if (arr[right] < arr[center])
        swap(arr + right, arr + center);
    // 完成三值分割最后一个为枢纽元
    swap(arr + center, arr + right - 1);
    return arr[right - 1];

}

void quick_sort(int*arr, int size, int left, int right)
{

    if (size<=1)
        return;
    /*
     * 1. 使用三中值分割
     */
    if (left+CUTOFF <=right) {

        int pivot = median3(arr,left,right);

        int i = left, j = right - 1;
        while (1) {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);
            if (i < j) swap(arr + i, arr + j);
            else break;
        }
        swap(arr+i, arr + right - 1); //  交换枢纽元

        quick_sort(arr, size, left, i - 1);
        quick_sort(arr, size, i + 1, right);
    }
    else{
        insert_sort(arr,left,right);
    }
}

/*辅助方法*/
void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
/*测试排序的算法*/
void test(const int *x, int size)
{
    for (int i = 1; i < size; ++i) {
        if (x[i]<x[i-1]){
            printf("error! index:%d  value: %d \n",i,x[i]);
            return;
        }

    }
    printf("sort right!\n");
}

void printArray(int *arr,int size)
{
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d,",arr[i]);
    }
    printf("]\n");
}

void printTime(void (*sort)(int*,int), const int *array, int size, char *name)
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
    printf("%s time consuming:%f s \n", name, ((double) (end - start) / CLOCKS_PER_SEC));
    printArray(arr,size);
}

int main()
{
    srand((unsigned)time(NULL));

    const int SIZE = 10000;
    int arr[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 100 + 1;
    }
//    printArray(arr,SIZE);
    printf("%d数的随机数组排序情况：\n",SIZE);
    printTime(insertSort,arr,SIZE,"insertSort");
    printTime(halfInsertSort,arr,SIZE,"HalfInsertSort");
    printTime(shellSort,arr,SIZE,"shellSort");
    printTime(heapSort,arr,SIZE,"heapSort");
    printTime(mergeSort,arr,SIZE,"mergeSort");
    printTime(quickSort,arr,SIZE,"quickSort");
//    start = clock();
//    shellSort(arr1,SIZE);
//    end = clock();
//    test(arr1,SIZE);
//    printf("shellSort 用时:%f s \n",  ((double) (end - start) / CLOCKS_PER_SEC));

}