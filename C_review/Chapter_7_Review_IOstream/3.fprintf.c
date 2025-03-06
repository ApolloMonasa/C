/*************************************************************************
	> File Name: 3.fprintf.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 09:38:20 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    fprintf(stdout, "hello stdioe\n");
    int n;
    fscanf(stdin, "%d", &n);
    fprintf(stderr, "n = %d\n", n);
    return 0;
}
