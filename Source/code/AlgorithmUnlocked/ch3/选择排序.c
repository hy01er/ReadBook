// ch3-1 选择排序

// 版本: -S 非递归版本    -R 递归版本

/*
 * 试着写伪代码:
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

#include "../Common/common_print.h"

void swap_int(int *a, int *b);
void print_int_array(int *a, int len);

void SelectSort_S(int *a, int len)
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

int  main()
{
    int a[] = {8, 22, 96, 47, 63, 88, 96, 5, -9, 999, 52};
    int arrayLen = SIZE_ARRAY(a);
    SelectSort_S(a, arrayLen);
    print_int_array(a, arrayLen);
    return 0;
}