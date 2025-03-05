/*************************************************************************
	> File Name: 17.struct.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Tue 04 Mar 2025 02:46:53 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct person {
    char name[20];
    int age;
    char gender;
    float height;
} P;

void output(struct person *p) {
    printf("%s, %d, %c, %f\n", p->name, p->age, p->gender, p->height);

}

void set_buff(char *buff, void *head, void *begin, void *end, char ch) {
    while(begin != end) {
        buff[(char *)begin - (char *)head] = ch;
        begin += 1;
    }
    return ;
}

void output_person() {
    int n = sizeof(P), len = 0;
    char buff[n];
    for (int i = 0 ;i < n; i++) buff[i] = '.';
    for (int i = 0; i < n; i++) {
        len += printf("%3d", i);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    P hug;
    set_buff(buff, &hug, hug.name, 20 + (void *)hug.name, 'n');
    set_buff(buff, &hug, &hug.age, 4 + (void *)&hug.age, 'a');
    set_buff(buff, &hug, &hug.gender, 1 + (void *)&hug.gender, 'g');
    set_buff(buff, &hug, &hug.height, 4 + (void *)&hug.height, 'h');
    for (int i = 0; i < n; i++) {
        printf("%3c", buff[i]);
    }
    printf("\n");
    return ;
}

int main() {
    struct person s1 = {"Peter", 18, 'x', 1.87};
    printf("%s, %d, %c, %f\n", s1.name, s1.age, s1.gender, s1.height);
    output(&s1);
    printf("sizeof(struct person) = %zd\n", sizeof(P));
    output_person();
    return 0;
}
