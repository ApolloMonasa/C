/*************************************************************************
	> File Name: 19.HZOJ-235.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 11:07:40 PM CST
 ************************************************************************/

#include<stdio.h>

int arr[10];

void printf_one_result(int n) {
    for(int i = 0; i <= n; i++) {
        if(i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

void f(int i, int j, int n){
    if(j > n) return ;
    for(int k = j; k <= n; k++) {
        arr[i] = k;
        printf_one_result(i);
        f(i + 1, k + 1, n);
    }

}

int main() {
    int n;
    scanf("%d", &n);
    f(0, 1, n);
    return 0;
}
