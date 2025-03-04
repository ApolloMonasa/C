/*************************************************************************
	> File Name: 4.param.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Feb 2025 10:51:17 PM CST
 ************************************************************************/

#include<stdio.h>

void test(int a, int b) {
    a += 1;
    b += 2;
    printf("test: a = %d. b = %d\n", a, b);
    return ;
}

int main(){
    int a = 1, b = 2;
    test(a, b);
    printf("main: a = %d, b = %d\n", a, b);
    return 0;
}
