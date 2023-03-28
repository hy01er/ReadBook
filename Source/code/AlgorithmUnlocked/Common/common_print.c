#include "common_print.h"

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