/*************************************************************************
	> File Name: 22.bit.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 06:51:35 PM CST
 ************************************************************************/

#include<stdio.h>

struct A {
    unsigned int a:1;
    unsigned int b:2;
    unsigned int c:3;
} obj;

#define P(a, format) {\
    printf("%s = " format "\n", #a, a);\
}

int main() {
    P(sizeof(struct A), "%zd");
    obj.a = 15;
    obj.b = 15;
    obj.c = 15;
    P(obj.a, "%d");
    P(obj.b, "%d");
    P(obj.c, "%d");
    return 0;
}
