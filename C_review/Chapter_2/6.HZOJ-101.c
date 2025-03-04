/*************************************************************************
	> File Name: 6.HZOJ-101.c
	> Author: 
	> Mail: 
	> Created Time: Wed 22 Jan 2025 09:49:51 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n, sum=0;
    scanf("%d",&n);
    while(n){
        sum += n%10;
        n/=10;
    }
    printf("%d\n",sum);
    return 0;
}
