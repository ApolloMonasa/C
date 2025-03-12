/*************************************************************************
	> File Name: 6.fscanf_and_fseek.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 07 Mar 2025 09:18:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>

int main() {
    FILE *fp = fopen("data5.txt", "r");
    int n;
    fseek(fp, 5, SEEK_SET);
    fscanf(fp, "%d", &n);
    printf("fscanf n = %d\n", n);
    return 0;
}
