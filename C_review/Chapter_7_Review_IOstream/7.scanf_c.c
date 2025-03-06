/*************************************************************************
	> File Name: 7.scanf_c.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 10:34:27 PM CST
 ************************************************************************/

#include<stdio.h>
int main() {
    printf("intput : 123 456\n");
    char c1, c2;
    int a, b;
    scanf("%d", &a);
    scanf("%c%c", &c1, &c2);
    scanf("%d", &b);

    printf("a = %d, b = %d, c1 = %d, c2 = %d\n", a, b, c1, c2);
    return 0;
}
