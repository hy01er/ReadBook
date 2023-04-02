// ch3 排序算法

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*******************基础接口定义****************************************/
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

/*******************排序接口定义****************************************/

// 定义排序接口类型
typedef void (*Sort)(int *a, int len);
Sort g_sortInterface = NULL;

// 1. 选择排序
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
void select_sort(int *a, int len)
{
    if (len <= 1) {
        return;
    }
    for (int i = 0; i < len - 1; i++) {
        int smallest = i;
        for (int  j = i; j < len; j++) {
            if (a[j] < a[smallest]) {
                smallest = j;
            }
        }
        swap_int(&a[i], &a[smallest]);
    }
    return;
}

// 2. 插入排序:和日常生活最贴近的排序算法
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
 * 1. 令i从1..(n-1)依次取值
 *      A.key被赋值为a[i],将j赋值成i -1
 *      B.只要j>=0, a[j] > key同时成立,执行如下操作:
 *          i. 令a[j + 1] = a[j]
 *          ii. j--
 *      C.将a[j + 1]赋值成key
*/

void insert_sort(int *a, int len)
{
    if (len  <= 1) {
        return;
    }
    int i, j;
    for (i = 1; i < len; i++) {
        int key = a[i];
        for (j = i - 1; (j >= 0) && (a[j] > key); j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}

typedef void (*sort_r) (int *a, int p, int r);
// 3. 归并排序(分治算法,递归)
void merge_sort(int *a, int p, int r);
/*
输入: 数组, 起始索引, 终止索引
输出: 排序好的数组

思想: 两个有序序列,合成一个有序序列
*/
#define MOST_NUMBER 99999999
void merge(int *a, int p, int q, int r)
{
    if (a == NULL) {
        return;
    }
    int n1 = q - p + 1;
    int n2 = r - q;
    int b[n1 + 1];
    int c[n2 + 1];
    int bIndex = 0, cIndex = 0;
    for (int i = p; i <= r; i++) {
        if (i <= q) {
            b[bIndex++] = a[i];
        } else {
            c[cIndex++] = a[i];
        }
    }
    b[n1] = MOST_NUMBER;
    c[n1] = MOST_NUMBER;
    bIndex = 0;
    cIndex = 0;
    for (int i = p; i <= r; i++) {
        if (b[bIndex] <= c[cIndex]) {
            a[i] = b[bIndex++];
        } else {
            a[i] = c[cIndex++];
        }
    }
}

void merge_sort(int *a, int p, int r)
{
    if (a == NULL || p >= r) {
        return;
    }
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
}

// 4.快速排序
void quick_sort(int *a, int p, int r);
/**
 * 输入:同merge_sort
 * 输出:同merge_sort
 *
 * 思想: 基准,左边小于,右边大于,基本条件是1个数字的时候不用排序直接是排好的
*/

int position(int *a, int p, int r)
{
    srand((unsigned int)time(NULL));
    int key = rand() % (r - p + 1) + p;
    if (key >= p && key <= r) {
        swap_int(&a[key], &a[r]);
    }
    int q = p; // q前是小于,后面是大于
    for (int u = p; u <= r - 1; u++) {
        if (a[u] <= a[r]) {
            swap_int(&a[q++], &a[u]);
        }
    }
    swap_int(&a[q], &a[r]);
    return q;
}

void quick_sort(int *a, int p, int r)
{
    if (a == NULL || p >= r) {
        return;
    }
    int q = position(a, p, r);
    quick_sort(a, p, q - 1);
    quick_sort(a, q + 1, r);
}

// 5.二分查找
#define NOT_FIND -1
int binary_find(int *a, int len, int x)
{
    int p = 0;
    int r = len - 1;
    int q = 0;
    while (p <= r) {
        q = (p + r) / 2;
        if (a[q] == x) {
            return q;
        } else if (a[q] < x) {
            p = q + 1;
        } else {
            r = q - 1;
        }
    }
    return NOT_FIND;
}

int  main()
{
    int a[] = {8, 22, 96, 47, 63, 88, 96, 5, -9, 999, 52, 354,-444, 87394, 66};
    int arrayLen = SIZE_ARRAY(a);
    sort_r sort = quick_sort;
    sort(a, 0, arrayLen - 1);
    print_int_array(a, arrayLen);

    int findNum = 999;
    int findIndex = binary_find(a, arrayLen, findNum);
    printf("\n\nfind %d index is %d\n\n", findNum, findIndex);
    return 0;
}