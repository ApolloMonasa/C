/*************************************************************************
	> File Name: scanf.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 03:13:57 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n, a, b;
    printf("Normal scanf,input a, b:");
    n = scanf("%d%d",&a, &b);
    printf("a = %d, b = %d\n",a, b);
    printf("n = %d\n",n);
    printf("Format scanf,input %%dabc%%d:");
    n = scanf("%dabc%d",&a, &b);
    printf("a = %d, b = %d\n",a, b);
    printf("n = %d\n",n);

    n = scanf("%d",&a);
    printf("n = %d\n",n);

    n = scanf("%d",&a);
    printf("n = %d\n",n);

    n = scanf("%d",&a);
    printf("n = %d\n",n);
    n = scanf("%d",&a);
    printf("n = %d\n",n);
    n = scanf("%d",&a);
    printf("n = %d\n",n);
    n = scanf("%d",&a);
    printf("n = %d\n",n);
    n = scanf("%d",&a);
    printf("n = %d\n",n);
    n = scanf("%d",&a);
    printf("n = %d\n",n);
    n = scanf("%d",&a);
    printf("n = %d\n",n);

    printf("EOF = %d\n",EOF);
    //Ctrl + D就是文件末尾标识
    return 0;
}
