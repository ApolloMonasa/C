/*************************************************************************
	> File Name: 6.terminal_output.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 10:25:41 PM CST
 ************************************************************************/

#include<stdio.h>

int main() {
    freopen("/dev/pts/1", "w", stdout);
    char s[1000];
    while(~scanf("%s", s)) {
        printf("[from /dev/pts/0] : %s\n", s);
    }
    return  0;
}
