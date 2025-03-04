/*************************************************************************
	> File Name: 7.HZOJ-1.2.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 09:57:08 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    double a, b, c, t;
    scanf("%lf%lf%lf%lf",&a, &b, &c, &t);
    printf("%.2lf\n",t + (1 - t / a - t / b) / (1 / a + 1 / b - 1 / c));
    return 0;
}
