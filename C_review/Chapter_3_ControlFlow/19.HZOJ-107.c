/*************************************************************************
	> File Name: 19.HZOJ-107.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 11:57:57 AM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    printf("%s\n", n % 7 == 0 && n % 2 ? "YES" : "NO");
    return 0;
}
