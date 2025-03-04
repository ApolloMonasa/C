/*************************************************************************
	> File Name: 11.ifdef.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 02 Mar 2025 09:34:03 PM CST
 ************************************************************************/

#include<stdio.h>

#ifndef DEBUG
#define DEBUG
#endif
//一定定义DEBUG宏

#ifdef DEBUG
int a = 1;
#else
int a = 0;
#endif


int main() {
    printf("a = %d\n", a);
    return 0;
}
