/*************************************************************************
	> File Name: 7.fseek_position.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sat 08 Mar 2025 07:31:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>

int main() {
    FILE *fp = fopen("data7.txt", "w");
    fprintf(fp, "0123456789");
    fseek(fp, -4, SEEK_CUR);
    fprintf(fp, "xy");
    return 0;
}
