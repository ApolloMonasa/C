/*************************************************************************
	> File Name: 16.HZOJ-467.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 10:55:18 PM CST
 ************************************************************************/

#include<stdio.h>
long long factorial(int n) {
    if(n == 0 || n == 1) return 1;
    return factorial(n - 1) * n; 
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%lld\n", factorial(n));
    return 0;
}
