/*************************************************************************
	> File Name: 9.string_cat.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 02 Mar 2025 08:44:04 PM CST
 ************************************************************************/

#include<stdio.h>
//#字符窜化运算符
#define STR(n) #n
#define RUN(func) {\
    func;\
    printf("%s done\n", #func);\
}
//连接运算符

#define CAT(a, b) a##b

void test1() {
    printf("this is test1\n");
    return ;
}

void test2(int a, int b) {
    printf("this is test2 : %d, %d\n", a, b);
    return ;
}

int main() {
    printf("%s\n", STR(hello));
    RUN(test1());
    RUN(test2(2, 3));
    int n10 = 123, n11 = 456;
    CAT(n, 10) = 789;
    printf("n10 = %d, n11 = %d\n", n10, n11);
    return 0;
}
