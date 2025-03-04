/*************************************************************************
	> File Name: 6.f_function.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Feb 2025 11:42:33 PM CST
 ************************************************************************/

#include<stdio.h>

int f(int n) {
    printf("In f(%d)\n",n);
    if(n == 0) return 1;
    int ret = n * f(n - 1);
    printf("Out f(%d)\n",n);
    return ret;
}
int main(){
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("f(%d) = %d\n", n, f(n));
    }

    return 0;
}
