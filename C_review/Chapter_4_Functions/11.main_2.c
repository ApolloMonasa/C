/*************************************************************************
	> File Name: 11.main_2.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 09:53:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]){
    if (strcmp(argv[0],"./bilibili") != 0) {
        printf("Wrong call, please call:./bilibili\n");
        return 0;
    }
    printf("Right call\n");
    printf("argc = %d\n", argc);
    for(int i = 0; i < argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}
