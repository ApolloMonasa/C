/*************************************************************************
	> File Name: 1.fprintf.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 06 Mar 2025 03:11:52 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fp = fopen("data.txt", "w");
    if(!fp) {
        perror("main() :: fopen()\n");
        exit(1);
    }
    fprintf(fp, "hello fp\n");
    fclose(fp);
}
