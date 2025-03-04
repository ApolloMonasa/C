/*************************************************************************
	> File Name: 31.HZOJ-142.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 03:39:28 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int a, b, c = 0;
    scanf("%d%d", &a, &b);
    for(int i = a; i <= b; i++){
        int flag = 1;
        for(int j = 2; j * j <= i; j++){
            if(i % j) continue;
            flag = 0;
        }
        if(flag){
            int x = i, y = 0;
            while(x){
                y = y * 10 + x % 10;
                x /= 10;
            }
            if(y != i) continue;
            if(c) printf(" ");
            c += printf("%d",i);
        }
    }
    return 0;
}
