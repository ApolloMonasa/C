/*************************************************************************
	> File Name: 2.file_access.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Thu 06 Mar 2025 03:39:24 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void r_access() {
    FILE *fp = fopen("data.txt", "r");
    if(!fp) {
        printf("r mode :Failed to open\n");
        exit(1);
    }
    char s[100];
    fscanf(fp, "%[^\n]", s);
    printf("s = %s\n", s);
    fclose(fp);

    /*fp = fopen("temp.txt", "r");
    if(!fp) {
        perror("Faile to open file");
    }*/
    return ;
}

void rand_file_name(char *file_name, int n) {
    for (int i = 0; i < n; i++) {
        file_name[i] = rand() % 26 + 'a';
    }
    strcat(file_name, ".txt");
    return ;
}

void w_access() {
    FILE *fp = fopen("data.txt", "w");
    if(!fp) {
        printf("w mode : Failed to open\n");
        exit(1);
    }
    fprintf(fp, "hahaha, world\n");
    fprintf(fp, "hello hangzhou\n");
    fclose(fp);
    char file_name[100] = {0};
    rand_file_name(file_name, 10);
    fp = fopen(file_name,"w");
    fclose(fp);
    return ;
}

void r_plus_access() {
    FILE *fp = fopen("data.txt", "r+");
    if(!fp) {
        printf("r+ mode : Failed to open\n");
        exit(1);
    }
    char s[100];
    fscanf(fp, "%s", s);
    printf("r+ mode : s = %s\n", s);
    fprintf(fp, "000000");

    fclose(fp);
}

int main() {
    //r_access();
    w_access();
    r_plus_access();
    return 0;
}
