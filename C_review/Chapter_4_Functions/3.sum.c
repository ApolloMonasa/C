/*************************************************************************
	> File Name: 3.sum.c
	> Author: 
	> Mail: 
	> Created Time: Sun 02 Feb 2025 09:11:00 PM CST
 ************************************************************************/

#include<stdio.h>

int sum(int a1, int r, int d){
    /*a1--首项
     *r --最大范围
     *d --公差*/
    int n = (r - a1) / d + 1;
    int an = a1 + (n - 1) * d;
    return (a1 + an) * n / 2;
}

int main(){
    //函数存在的意义是为了减少代码重复，以及模块化编程
    printf("%d %d %d\n",
        sum(1, 100, 1),
        sum(1, 100, 2),
        sum(26, 36999, 47)
    );

    return 0;
}
