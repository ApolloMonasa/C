/*************************************************************************
	> File Name: 4.freopen.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 10:03:03 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    printf("hello freopen\n");
    char s[1000];
    while(~scanf("%[^\n]", s)){
        printf("%s" " | hello world\n", s);
        while(getchar() != '\n');
    }
    return 0;
}
