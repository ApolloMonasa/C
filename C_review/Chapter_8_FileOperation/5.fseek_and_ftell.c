/*************************************************************************
	> File Name: 5.fseek_and_ftell.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 07 Mar 2025 08:55:31 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>


int main() {
    FILE *fp = fopen("data5.txt", "w");
    printf("ftell(fp) = %ld\n", ftell(fp));
    fprintf(fp, "0123456789");
    printf("after input 0123456789 : ftell(fp) = %ld\n", ftell(fp));
    fseek(fp, 2, SEEK_SET);
    printf("after Set(2): ftell(fp) = %ld\n", ftell(fp));
    fprintf(fp, "abc");
    printf("after input abc: ftell(fp) = %ld\n", ftell(fp));

    return 0;
}
