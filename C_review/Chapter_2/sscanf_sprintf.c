/*************************************************************************
	> File Name: sscanf_sprintf.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 03:55:01 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    //sscanf就是从字符串中读取数据
    char s[100] = "123 456 789";
    int a, b, c;
    sscanf(s,"%d%d%d",&a, &b, &c);
    printf("a = %d b = %d c = %d\n", a, b, c);
    //sprintf就是向字符数组中输出数据
    sprintf(s,"%d:%d:%d",a, b, c);
    printf("%s\n",s);
    return 0;
}
