/*************************************************************************
	> File Name: scanf_Collection.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 03:41:47 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    //读入一行可能包含空格的字符串
    char s[100];
    scanf("%[^\n]",s);
    printf("s = %s\n",s);
    return 0;
}
