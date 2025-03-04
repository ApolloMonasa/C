/*************************************************************************
	> File Name: 18.HZOJ-183.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 11:03:56 PM CST
 ************************************************************************/

#include<stdio.h>

int f(int x) {
    if(x <= 0) return 0;
    if(x == 1) return 1;
    if(x % 2 == 0) return 3 * f(x / 2) - 1;
    return 3 * f((x + 1) / 2) - 1;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n",f(n));
    return 0;
}
