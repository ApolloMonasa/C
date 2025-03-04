/*************************************************************************
	> File Name: 7.gcd.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 09:04:37 PM CST
 ************************************************************************/

#include<stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) {
        printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    }

    return 0;
}
