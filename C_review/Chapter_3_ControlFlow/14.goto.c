/*************************************************************************
	> File Name: 14.goto.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 08:22:58 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    goto lab1;
    printf("Hello world\n");
lab1:
    printf("Hello hangzhou\n");
    goto lab2;//goto会跳过变量的初始化但是不会跳过变量的声明
    int a = 0, b = 0;
    scanf("%d%d",&a, &b);
lab2:
    printf("%d\n",a * b);
    return 0;
}
