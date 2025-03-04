/*************************************************************************
	> File Name: 7.HZOJ-113.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 12:47:20 PM CST
 ************************************************************************/

#include<stdio.h>
//一个月有多少天？？
int main(){
    int y, m;
    scanf("%d%d",&y, &m);
    int a = y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m ==10 || m ==12) printf("31\n");
    else if(m == 4 || m == 6 || m == 9 || m == 11) printf("30\n");
    else if(m == 2) printf("%d\n",28 + a);
    else printf("Month Input Error!\n");

    return 0;
}
