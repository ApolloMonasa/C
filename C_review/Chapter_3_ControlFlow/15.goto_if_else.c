/*************************************************************************
	> File Name: 15.goto_if_else.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 08:36:51 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){

    int n;
    scanf("%d", &n);
    n % 2 == 0 && ({goto if_stmt;0;});
    !(n % 2) == 0 && ({goto else_stmt;0;});
if_stmt:
    printf("n is even\n");
    goto if_end;
else_stmt:
    printf("n is odd\n");
if_end:
    return 0;
}
