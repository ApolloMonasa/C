/*************************************************************************
	> File Name: 23.HZOJ-120.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 01:12:44 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int y, m, d, days;
    scanf("%d%d%d", &y, &m, &d);
    if(m == 2) days = 28 + ((y % 4 == 0 && y % 100) || (y % 400 == 0));
    else if(m == 4 || m == 6 || m == 9 || m == 11) days = 30;
    else days = 31;
    if(m > 12 || m < 1) printf("NO\n");
    else if(d > days || d <= 0) printf("NO\n");
    else printf("YES\n");
    return 0;
}
