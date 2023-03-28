#ifndef __COMMON_H_
#define __COMMON_H_

#include "stdio.h"
#define SIZE_ARRAY(a) ((sizeof(a)) / (sizeof(a[0])))

// unused
typedef enum {
    R_MODE, // 递归版本
    S_MODE  // 非递归版本
} CODE_MODE;


void swap_int(int *a, int *b);
void print_int_array(int *a, int len);

#endif