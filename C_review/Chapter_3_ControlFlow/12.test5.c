/*************************************************************************
	> File Name: 12.test5.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 07:46:39 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int a = 1, b = 1;
    //f[n] = f[n-1] + f[n-2]
    for(int i = 0;i < 20;i++){
        printf("%d ",a);
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    printf("\n");

    for(int i = 0, f1 = 1,f2 = 1;i < 20;i++,f2 += f1,f1 = f2 - f1){
        printf("%d ",f1);
    }
    printf("\n");
    return 0;
}
