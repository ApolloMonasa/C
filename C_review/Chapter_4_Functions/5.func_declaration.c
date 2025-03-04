/*************************************************************************
	> File Name: 5.func_declaration.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Feb 2025 11:10:06 PM CST
 ************************************************************************/

#include<stdio.h>
//声明是函数原型的说明，以告诉编译器存在这个函数，定义是函数的实现细节，是复合语句中的所有内容
//因为编译的顺序执行，会存在函数互相调用的时候可能被调用的函数还为定义，
//所以在开头把所有函数声明一遍可以解决这个问题
//声明的时候编译器只关心参数类型而不会关心参数名字，所有可以省略形参名
int a_func(int);
int b_func(int);
int a_func(int x) {
    switch (x) {
        case 1: return b_func(x);
        case 2: printf("2 * x = %d\n", 2 * x); break;
    }
    return 0;
}

int b_func(int x) {
    switch (x) {
        case 1: printf("3 * x = %d\n", 3 * x); break;
        case 2: return a_func(x);
    }
    return 0; 
}
int main(){
    b_func(1);
    b_func(2);
    return 0;
}
