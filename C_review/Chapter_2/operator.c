/*************************************************************************
	> File Name: operator.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 04:21:34 PM CST
 ************************************************************************/

#include<stdio.h>
#define Print(stmt, func){\
    printf("%s\n", #stmt);\
    stmt;\
    func;\
}

int main(){
    int a = 5,b = 2, c = 7, d;
    printf("a = %d, b = %d, c = %d\n",a, b, c);
    Print(a = c, printf("a = %d, b = %d, c = %d\n",a, b, c));
    Print(d = a + b, printf("d = %d\n",d));
    Print(d = a - b, printf("d = %d\n",d));
    Print(d = a * b, printf("d = %d\n",d));
    Print(d = a / b, printf("d = %d\n",d));

    return 0;
}
