/*************************************************************************
	> File Name: 13.attribute.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 09 Mar 2025 09:11:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>

int arr[10];

__attribute__((constructor)) void test1() {
    printf("hello test1\n");
    arr[0] = 100;
    return ;
}
__attribute__((constructor)) void test2() {
    arr[1] = 99;
    return ;
}
__attribute__((constructor)) void test3() {
    arr[2] = 10086;
    return ;
}

int main() {
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("hello main\n");
    return 0;
}
