/*************************************************************************
	> File Name: 2.and_or.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 12:09:37 PM CST
 ************************************************************************/

#include<stdio.h>
//利用短路原则实现类似分支结构的效果
int main(){
    int a, b;
    scanf("%d%d",&a, &b);
    //如果a>b就输出YES，否则输出NO
    a > b  && printf("YES\n");
    a <= b && printf("NO\n");
    a > b  || printf("NO\n");
    a <= b || printf("YES\n");


    return 0;
}
