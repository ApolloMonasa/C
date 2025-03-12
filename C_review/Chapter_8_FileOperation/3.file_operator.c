/*************************************************************************
	> File Name: 3.file_operator.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 07 Mar 2025 10:57:49 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>

const char *file_name = "data3.txt";
#define MAX_N 10000

int arr[MAX_N + 5], n;

void output_arr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}
void append_arr_to_file(int *arr, int n) {//追加a模式
    FILE *fp = fopen(file_name, "a");
    if(!fp) {
        perror("append_arr_to_file::fopen() == NULL\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fprintf(fp, "\n");
    printf("append_arr_to_file %s \n", file_name);
    fclose(fp);
    return ;
}

int output_test() {
    srand(time(0));
    for (n = 0; n < 10;) arr[n++] = rand() % 100;
    output_arr(arr, n);
    append_arr_to_file(arr, n);
    return 0;
}

int read_from_file(int *arr) {
    if(!arr) {
        perror("arr is not valid\n");
        return 0;
    }
    int num = 0;
    FILE *fp = fopen(file_name, "r");
    if(!fp) {
        perror("read_from_file::fopen() == NULL\n");
        return 0;
    }
    while (~fscanf(fp, "%d", arr + num)) num++; 
    fclose(fp);
    return num;
}

int read_test() {
    n = read_from_file(arr);//return value : the number of numbers it read
    output_arr(arr, n);
    printf("total read %d numbers\n", n);
    return 0;
}

void clear_file() {
    FILE *fp = fopen(file_name, "w");
    fclose(fp);
    return ;
}

int main() {
    clear_file();
    return 0;
}
