/*************************************************************************
	> File Name: 13.break_continue.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 08:03:24 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    //输出1-n所有不大于8的偶数
    for(int i = 0;i < n; i++){
        if(i + 1 > 8) break;
        if((i + 1) % 2 ==0) continue;
        printf("%d ",i + 1);
    }
    printf("\n");
    return 0;
}
