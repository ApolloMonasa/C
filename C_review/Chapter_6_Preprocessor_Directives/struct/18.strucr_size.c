/*************************************************************************
	> File Name: 18.strucr_size.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Wed 05 Mar 2025 01:58:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#ifdef STRUCT_A
struct A {
    char a;
    int b;
    short c;
};

void set_buff(char *buff, void *head, void *begin, void *end, char ch) {
    while(begin != end) {
        buff[(char *)begin - (char *)head] = ch;
        begin += 1;
    }
    return ;
}

void output_person() {
    int n = sizeof(struct A), len = 0;
    char buff[n];
    for (int i = 0 ;i < n; i++) buff[i] = '.';
    for (int i = 0; i < n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    struct A hug;
    set_buff(buff, &hug, &hug.a, 1 + (void *)&hug.a, 'a');
    set_buff(buff, &hug, &hug.b, 4 + (void *)&hug.b, 'b');
    set_buff(buff, &hug, &hug.c, 2 + (void *)&hug.c, 'c');
    for (int i = 0; i < n; i++) {
        printf("%3c", buff[i]);
    }
    printf("\n");
    return ;
}

#endif

int main() {
    output_person();
    return 0;
}
