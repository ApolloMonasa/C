/*************************************************************************
	> File Name: test3.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 02 Mar 2025 09:55:28 AM CST
 ************************************************************************/

#include<stdio.h>

int add(int, int);

int main() {
    int a = 123, b = 456;
    printf("a + b =%d\n", a + b);
    printf("add(%d, %d) = %d\n", a, b, add(a, b));
    return 0;
}
