/*************************************************************************
	> File Name: 5.switch_case_default.c
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jan 2025 12:38:08 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    switch(a){
        case 1:printf("a = 1\n");
        case 2:printf("a = 2\n");
        case 3:printf("a = 3\n");
        case 4:printf("a = 4\n");
        default: printf("Default value.\n");
    }
    return 0;
}
