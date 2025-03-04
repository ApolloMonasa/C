/*************************************************************************
	> File Name: 1.block.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Feb 2025 06:31:38 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int a = 1, b = 2;
    for(int i = 0; i < 10; i++){
        int a = 2, b = 4, c = 1, d = 2;
        printf("Inside: a = %d, b = %d\n", a, b);
    }
    printf("%d %d\n", a, b);
    printf("Outside: a = %d, b = %d\n", a, b);
    //printf("%d %d\n", c, d);
    return 0;
}
