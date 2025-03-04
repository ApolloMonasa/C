/*************************************************************************
	> File Name: 17.goto_for.c
	> Author: 
	> Mail: 
	> Created Time: Mon 27 Jan 2025 09:02:26 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int i = 1;//声明不能加标签
for_1:
    goto for_2;
for_2:
    if(i <= n) goto for_4;
    else goto for_end;
for_3:
    i++;
    goto for_2;
for_4:
    if(i % 3 == 0) goto for_3;
    printf("%d ", i);
    goto for_3;
for_end:
    printf("\n");
    return 0;
}
