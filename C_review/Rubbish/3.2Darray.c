/*************************************************************************
	> File Name: 3.2Darray.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 05 May 2025 10:11:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>
#include<stdbool.h>

void output(int (*a)[],int  n,int  m) {
    int (*arr)[m] = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &arr[i][j]);
        }
    }
    output(arr, n, m);
}
