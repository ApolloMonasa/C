/*************************************************************************
	> File Name: 8.ex_gcd.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 09:20:19 PM CST
 ************************************************************************/

#include<stdio.h>
int x, y, nx, ny;

int ex_gcd(int a, int b) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int c = ex_gcd(b, a % b);
    nx = y;
    ny = x - a / b * y;
    x = nx, y = ny;
    return c;
}

int main(){
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        int c = ex_gcd(a, b);
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, c);
    }

    return 0;
}
