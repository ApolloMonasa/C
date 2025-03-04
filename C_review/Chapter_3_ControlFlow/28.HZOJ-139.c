/*************************************************************************
	> File Name: 28.HZOJ-139.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 02:53:30 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n - 1; i++){
        int a_num = 2 * n - 2 * abs(n - 1 -i);
        int b_num = abs(n - 1 -i);
        for(int j = 0; j < b_num; j++) printf(" ");
        for(int j = 0; j < a_num; j++) printf("A");
        printf("\n");
    }
    return 0;
}
