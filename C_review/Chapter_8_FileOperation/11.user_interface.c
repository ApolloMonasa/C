/*************************************************************************
	> File Name: 11.user_interface.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 09 Mar 2025 05:25:24 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>


int page1_usage() {
    printf("1 : goto page2\n");
    printf("2 : goto page3\n");
    printf("3 : goto page4\n");
    int x = -1;
    do {
        printf("Input : ");
        scanf("%d", &x);
    } while((x < 1 || x > 3) && printf("Invalid Value!!\n"));

    return x;
}

int page2_usage() {
    printf("0 : back to page1\n");
    printf("1 : goto page5\n");
    int x = -1;
    do {
        printf("Input : ");
        scanf("%d", &x);
    } while((x < 0 || x > 1) && printf("Invalid Value!!\n"));
    
    return x;
}

int page4_usage() {
    printf("0 : back to page1\n");
    printf("1 : goto page5\n");
    int x = -1;
    do {
        printf("Input : ");
        scanf("%d", &x);
    } while((x < 0 || x > 1) && printf("Invalid Value!!\n"));
    
    return x;
}

void page3_run() {
    int arr[10];
    for (int i = 0; i < 10; i++) arr[i] = rand() % 10;
    int len = 0;
    for (int i = 0; i < 10; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("=");
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
    return ;
}

void page5_run() {
    printf("Hello This is Page5\n");
    return ;
}

int main() {
    srand(time(0));
    int status = 1;
    while (1) {
        switch(status) {
            case 1: {
                printf("Into Page1 : \n");
                int x = page1_usage();
                if (x == 1) status = 2;
                if (x == 2) status = 3;
                if (x == 3) status = 4;
            } break;
            case 2: {
                printf("Into Page2 : \n");
                int x = page2_usage();
                if(x == 0) status = 1;
                else if (x == 1) status = 5;

            } break;
            case 3: {
                printf("Into Page3 : \n");
                page3_run();
                status = 5;

            } break;
            case 4: {
                printf("Into Page4 : \n");
                int x = page4_usage();
                if(x == 0) status = 1;
                else if (x == 1) status = 5;

            } break;
            case 5: {
                printf("Into Page5 : \n");
                page5_run();
                status = 1;
            } break;
        }
    }
    return 0;
}
