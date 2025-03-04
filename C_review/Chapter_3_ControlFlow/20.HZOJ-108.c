/*************************************************************************
	> File Name: 20.HZOJ-108.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 12:15:20 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    char c;
    double a, b;
    scanf("%c%lf%lf", &c, &a, &b);
    printf("%.2lf\n", c == 'r' ? a * b : a * b / 2);
    return 0;
}
