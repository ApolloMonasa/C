/*************************************************************************
	> File Name: 21.HZOJ-114.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 12:34:55 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    char c;
    const char *name;

    scanf("%c", &c);
    switch(c){
        case 'h': name = "He\n"; goto PRINT;
        case 'l': name = "Li\n"; goto PRINT;
        case 'c': name = "Cao\n"; goto PRINT;
        case 'd': name = "Duan\n"; goto PRINT;
        case 'w': name = "Wang\n"; goto PRINT;
PRINT:
        printf("%s", name); break;
        default : printf("Not Here\n");break;
    }
    return 0;
}
