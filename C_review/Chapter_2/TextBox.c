/*************************************************************************
	> File Name: TextBox.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 04:05:51 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    char s[100], t[100];
    scanf("%[^\n]",s);
    int n = 0;
    n = sprintf(t,"| %s |",s);
    for(int i = 0;i < n;i++)printf("-");
    printf("\n");
    printf("%s",t);
    printf("\n");
    for(int i = 0;i < n;i++)printf("-");
    printf("\n");


    return 0;
}
