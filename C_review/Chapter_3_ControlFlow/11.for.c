/*************************************************************************
	> File Name: 11.for.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 07:37:47 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n, i;
    scanf("%d", &n);
    printf("Program1:\n");
    for(i = 0;i < n;i++){
        printf("%d ", i+1);
    }
    printf("\n");
    printf("Program2:\n");
    for(i = 0;;i++){
        if(i == n) break;
        printf("%d ",i+1);
    }
    printf("\n");

    return 0;
}
