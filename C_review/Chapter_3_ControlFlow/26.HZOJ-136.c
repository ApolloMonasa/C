/*************************************************************************
	> File Name: 26.HZOJ-136.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 01:43:08 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i * 7 <= n; i++){
        printf("%d\n", i * 7);
    }
    return 0;
}
