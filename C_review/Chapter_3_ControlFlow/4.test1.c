/*************************************************************************
	> File Name: 4.test1.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 12:23:53 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if(!n) printf("HEHE\n");
    else if(n < 60) printf("FAIL\n");
    else if(n <75 ) printf("MEDIUM\n");
    else printf("GOOD\n");
    
    return 0;
}
