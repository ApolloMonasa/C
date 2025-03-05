/*************************************************************************
	> File Name: 21.color.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 06:14:09 PM CST
 ************************************************************************/

#include<stdio.h>
#ifdef PLAN_A
#define COLOR(msg, code) "\033[1;" #code "m" msg "\033[0m"
#define RED(msg)     COLOR(msg, 31)
#define GREEN(msg)   COLOR(msg, 32)
#define YELLOW(msg)  COLOR(msg, 33)
#define BLUE(msg)    COLOR(msg, 34)

int main() {
    printf("\033[1;32;43mhello world\033[0m\n");
    printf(RED("hello COLOR\n"));
    printf(GREEN("hello COLOR\n"));
    printf(YELLOW("hello COLOR\n"));
    printf(BLUE("hello COLOR\n"));
    return 0;
}

#else

enum COLOR_CODE {
    RED = 31,
    GREEN,
    YELLOW,
    BLUE
};


#define COLOR_SET "\033[1;%dm"
#define COLOR_END "\033[0m"

int main() {
    printf(COLOR_SET "hello color plan b\n" COLOR_END, RED);   
    printf(COLOR_SET "hello color plan b\n" COLOR_END, GREEN);   
    printf(COLOR_SET "hello color plan b\n" COLOR_END, YELLOW);   
    printf(COLOR_SET "hello color plan b\n" COLOR_END, BLUE);   
    
    printf(
        COLOR_SET "hello"
        COLOR_SET " color"
        COLOR_SET " plan"
        COLOR_SET " b\n"
        COLOR_END,
        RED,
        GREEN,
        YELLOW,
        BLUE
        );
    return 0;
}
#endif


