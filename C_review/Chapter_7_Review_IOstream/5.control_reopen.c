/*************************************************************************
	> File Name: 4.freopen.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 10:03:03 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    char s[1000];\
    int i  = 1;
    while(~scanf("%[^\n]", s)){
        fprintf(stderr, "%d test case\n", i++);
        printf("%s" " | hello world\n", s);
        while(getchar() != '\n');
    }
    return 0;
}
