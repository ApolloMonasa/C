/*************************************************************************
	> File Name: 24.HZOJ-128.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 01:30:40 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n, sum = 0;
    scanf("%d", &n);
    for(int i = 0, a; i < n; i++){
        scanf("%d", &a);
        sum += a;
    }
    printf("%.2lf\n",sum * 1.0  / n);
    return 0;
}
