/*************************************************************************
	> File Name: 9.fwrite_fread.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 09 Mar 2025 03:04:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}

int fwrite_test() {
    srand(time(0));
    #define MAX_N 10
    int arr[MAX_N], copy[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        arr[i] = rand() % 10000;
    }
    output(arr, MAX_N);
    FILE *fp = fopen("data9.dat", "wb+");
    fwrite(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fp);
    fclose(fp);
    return 0;
}

int main() {
    int arr[MAX_N];
    FILE *fp = fopen("data9.dat", "rb");
    fread(arr, sizeof(arr[0]), MAX_N, fp);
    output(arr, MAX_N);
    return 0;
}
