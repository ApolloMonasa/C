/*************************************************************************
	> File Name: 4.decl_def.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 02 Mar 2025 10:18:09 AM CST
 ************************************************************************/

#include<stdio.h>

int add(int, int);

extern int c, d;

int main() {
    int a, b;//def
    printf("a + b + c + d = %d\n", a+b+c+d);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
