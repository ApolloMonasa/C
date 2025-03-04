/*************************************************************************
	> File Name: 11.main_2.c
	> Author: 
	> Mail: 
	> Created Time: Wed 05 Feb 2025 09:53:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[], char **env){
    int flag = 0;
    for(char **p = env; p[0]; p++) {
        if(strcmp(p[0], "LOGNAME=HDUSai") == 0){
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("Error log name, please use HDUSai\n");
    }
    printf("argc = %d\n", argc);
    for(int i = 0; i < argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    printf("-----------------------------------------------\n");

    for(char **p = env; p[0]; p++) {
        printf("%s\n", p[0]);
    }
    return 0;
}
