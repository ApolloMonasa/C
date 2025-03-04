/*************************************************************************
	> File Name: types.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 02:10:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include <inttypes.h>

int main(){
    int a = 123, b = 97, c, d;
    c = 10062;
    d = 9651;
    printf("%d %d %d %d\n",a, b, c, d);
    a = 2147483647 + 1;
    printf("%d\n",a);
    printf("INT32_MAX = %d\n",INT32_MAX);
    printf("INT32_MIN = %d\n",INT32_MIN);
    long long int e = INT32_MAX + 1;
    printf("%lld\n",e);//这个地方是因为之计算过程中发生溢出才出错
    e = 2147483647LL + 1;
    printf("%lld\n",e);
    float  f  = e + 0.1;
    double ff = e + 0.123456789;//float保证七位有效数字，double保证15位有效数字，但不是说后面的都一定错误；
    printf("float : %f\n",f);
    printf("double : %.9lf\n",ff);
    char g = 'a';
    printf("g = %c\n",g);
    printf("g(%%d) = %d\n",g);
    return 0;
}
