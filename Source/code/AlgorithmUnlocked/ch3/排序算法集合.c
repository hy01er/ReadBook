// ch3 排序算法

#include "stdio.h"

#define SIZE_ARRAY(a) ((sizeof(a)) / (sizeof(a[0])))

void print_int_array(int *a, int len)
{
    if (len <= 0){
        return;
    }
    int i = 0;
    while(i < len) {
        printf("%d ", a[i]);
        i++;
    }
    putchar('\n');
    return;
}

void swap_int(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// 定义排序接口类型
typedef void (*Sort)(int *a, int len);
Sort g_sortInterface = NULL;


// 选择排序
/*
 * 伪代码:
 * 程序 SelectSort(int *a, int len)
 *
 * 输入:
 *  a :int *, 一个一维的数组
 * len:int, 数组的长度
 *
 * 输出: 一个递增的排序好的数组
 *
 * 1. 令i从0..(len - 2)取值:
 *      A.将smallest赋值成i
 *      B.令j从(i+1)..(len - 1)取值:
 *          i.如果a[j]<a[smallest],那么将smallest赋值成j
 *      C.交换a[i]与a[smallest]的值.
 *
*/
void SelectSort(int *a, int len)
{
    if (len <= 0) {
        return;
    }
    for (int i = 0; i < len - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[smallest]) {
                smallest = j;
            }
        }
        swap_int(&a[i], &a[smallest]);
    }
    return;
}

// 插入排序:和日常生活最贴近的排序算法
/**
 * 伪代码:
 * 伪代码:
 * 程序 InsertSort(int *a, int len)
 *
 * 输入:
 *  a :int *, 一个一维的数组
 *  len:int, 数组的长度
 *
 * 输出: 一个递增的排序好的数组
 *
 * 1. 令i从2..(n-1)依次取值
 *      A.key被赋值为a[i],将j赋值成i -1
 *      B.只要j>=0, a[j] > key同时成立,执行如下操作:
 *          i. 令a[j + 1] = a[j]
 *          ii. j--
 *      C.将a[j + 1]赋值成key
*/

void InsertSort(int *a, int len)
{
    if (len <= 0) {
        return;
    }
    int i, j;
    for ( i = 1; i < len; i++) {
        int key = a[i];
        for (j = i - 1; (j >= 0 && a[j] > key); j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
    return;
}


int  main()
{
    int a[] = {8, 22, 96, 47, 63, 88, 96, 5, -9, 999, 52};
    int arrayLen = SIZE_ARRAY(a);
    g_sortInterface = InsertSort;
    g_sortInterface(a, arrayLen);
    print_int_array(a, arrayLen);
    return 0;
}