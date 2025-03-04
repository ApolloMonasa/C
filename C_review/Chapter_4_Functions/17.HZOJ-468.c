/*************************************************************************
	> File Name: 17.HZOJ-468.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 10:58:30 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int m, int n) {
    if(n == 0) return m;
    return gcd(n, m % n);
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", gcd(m, n));
    return 0;
}
