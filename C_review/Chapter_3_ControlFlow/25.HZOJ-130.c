/*************************************************************************
	> File Name: 25.HZOJ-130.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 01:37:57 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int m, n;
    double yu = 0;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++){
        yu += m;
        yu *= 1.00417;
    }
    printf("$%.2lf\n", yu);
    return 0;
}
