/*************************************************************************
	> File Name: 23.hex.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 08:03:56 PM CST
 ************************************************************************/

#include<stdio.h>

union Hex {
    struct {
        unsigned char B1:4;  
        unsigned char B2:4;  
    } B[4];
    unsigned int number;
} Hex1;

char code(unsigned int x) {
    if(x < 10) return '0' + x;
    return x - 10 + 'A';
}

int main() {
    Hex1.number = 0x6a6b6c6d;
    for (int i = 3; i >= 0; i--) {
        printf("%c%c", code(Hex1.B[i].B2), code(Hex1.B[i].B1));
    }
    printf("\n");

    return 0;
}
