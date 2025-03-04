/*************************************************************************
	> File Name: 7.define.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 02 Mar 2025 04:40:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define PI 3.1415926
#define S(a, b) a * b
#define P(a) {\
    printf("define P : %d\n", a);\
}

int main() {
    printf("PI = %lf\n", PI);
    printf("S(%d, %d) = %d\n", 3, 4, S(3, 4));
    printf("S(%d, %d) = %d\n", 3 + 7, 4, S(3 + 7, 4));
    S(int, p) = (int *)malloc(sizeof(int) * 10);
    int n = 123;
    p = &n;
    P(*p);
    return 0;
}
