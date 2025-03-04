/*************************************************************************
	> File Name: 8.while.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 06:54:20 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    //1-n输出
    int n, i = 0;
    scanf("%d",&n);
    while(i<n){
        printf("%d ",++i);
    }
    return 0;
}
