/*************************************************************************
	> File Name: 22.HZOJ-118.c
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Jan 2025 12:54:22 PM CST
 ************************************************************************/

#include<stdio.h>

int main(){
    int y;
    char* arr[12] = {"rat\n", "ox\n", "tiger\n", "rabbit\n", "dragon\n", "snake\n", "horse\n", "sheep\n", "monkey\n", "rooster\n","dog\n","pig\n"};
    scanf("%d", &y);
    printf("%s", arr[y >= 1900 ? (y - 1900) % 12 : 12 + (y - 1900) % 12]);
    return 0;
}
