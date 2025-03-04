/*************************************************************************
	> File Name: 13.HZOJ-464.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 10:18:29 PM CST
 ************************************************************************/

#include<stdio.h>

_Bool is_leap_year(int i) {
    return i % 100 && i % 4 == 0 || i % 400 ==0;
}

int main() {
    int x, y, ans = 0;
    scanf("%d%d", &x, &y);
    for (int i = x; i <= y; i++) {
        ans += is_leap_year(i);
    }
    printf("%d\n",ans);
    return 0;
}
