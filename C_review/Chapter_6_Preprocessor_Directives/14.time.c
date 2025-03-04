/*************************************************************************
	> File Name: 14.time.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Mon 03 Mar 2025 10:56:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<time.h>

#define TIME(func) {\
    long long b = clock();\
    func;\
    long long e = clock();\
    printf("%s  RUNTIME : %lldms\n",#func, 1000 * (e - b) / CLOCKS_PER_SEC);\
}

void test(long long n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum+=i;
    printf("sum = %lld\n", sum);
    return ;
}

int main() {
    TIME(test(100000));
    TIME(test(100000000));
    TIME(test(1000000000));
    return 0;
}
