/*************************************************************************
	> File Name: 1.stderr.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 09:14:20 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    printf("hello world\n");//stdout
    int n;
    scanf("%d", &n);//stdin
    perror("out of range\n");//stderr
    return 0;
}
