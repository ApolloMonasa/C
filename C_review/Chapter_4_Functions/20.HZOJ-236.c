/*************************************************************************
	> File Name: 20.HZOJ-236.c
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Feb 2025 09:55:31 AM CST
 ************************************************************************/

#include<stdio.h>

int arr[10];

void print_one_result(int n) {
    for(int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

void f(int i, int j, int n, int m) {
    if (i == m) {
        print_one_result(m);
        return ;
    }
    for (int k = j; k <= n && m - i - 1 <= n - k; k++) {
        arr[i] = k;
        f(i + 1, k + 1, n, m);
    }
    return ;

}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    f(0, 1, n, m);
    return 0;
}
