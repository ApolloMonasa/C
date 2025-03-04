/*************************************************************************
	> File Name: 9.do_while.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 07:06:03 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n, m = 0;
    scanf("%d",&n);
    do{
        m++;
        n /= 10;
    }while(n);
    printf("Digits:%d\n",m);
    return 0;
}
