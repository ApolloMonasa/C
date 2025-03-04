/*************************************************************************
	> File Name: 27.HZOJ-137.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 02:11:25 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n;
    char ch = 'A';
    scanf("%d", &n);
    for(int i = n; i > 0; i--){
        for(int j = 0; j < i; j++,ch++){
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
