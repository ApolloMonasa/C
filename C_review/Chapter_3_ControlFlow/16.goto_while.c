/*************************************************************************
	> File Name: 16.goto_while.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 08:55:37 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n, i = 1;
    scanf("%d", &n);
judge:
    if(i <= n) goto stmt;
    else goto while_end;
stmt:
    printf("%d ",i);
    i += 1;
    goto judge;
while_end:
    printf("\n");
    return 0;
}
