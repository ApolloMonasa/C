/*************************************************************************
	> File Name: 30.HZOJ-141.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 03:16:02 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n + 1; i++){
        int c_num = 2 * abs(n - i) + 1;
        int spc_num =  n - abs(n - i);
        for(int j = 0; j < spc_num; j++) printf(" ");
        for(int j = 0; j < c_num; j++){
            char ch = 'A' + n - abs(c_num / 2 - j);
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
