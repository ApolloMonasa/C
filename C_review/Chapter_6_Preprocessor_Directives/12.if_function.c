/*************************************************************************
	> File Name: 12.if_function.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 02 Mar 2025 09:47:51 PM CST
 ************************************************************************/

#include<stdio.h>


#ifdef CLOCK
void test1() {
    printf("this is test1\n");
    return ;
}
#endif

#ifdef PHONE
void test2() {
    printf("this is test2\n");
    return ;
}
#endif
int main() {
    #ifdef CLOCK
    test1();
    #endif
    #ifdef PHONE
    test2();
    #endif

    return 0;
}
