/*************************************************************************
	> File Name: 4.student_system.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Fri 07 Mar 2025 01:14:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<inttypes.h>//<stdint.h>
#include<stdarg.h>

const char *file_name = "student_data.txt";

typedef struct Student {
    char name[20];
    int age;
    int class;
    double height;
} Student;

#define MAX_N 10000
Student stus[MAX_N + 5];
int scnt = 0;

int read_from_file(Student *arr) {
    int i = 0;
    FILE *fp = fopen(file_name, "r");
    if(!fp) return 0;
    while(~fscanf(fp, "%s", arr[i].name)) {
        fscanf(fp, "%d%d%lf",
               &arr[i].age,
               &arr[i].class,
               &arr[i].height
              );
        i++;
    }
    fclose(fp);
    return i;
}

void output_to_file(Student *arr, int n) {
    FILE *fp = fopen(file_name, "a");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %d %d %.2lf\n",
                arr[i].name, arr[i].age,
                arr[i].class, arr[i].height
        );
    }
    return ;
}

void restore_data_to_file(Student *arr, int n) {
    FILE *fp = fopen(file_name, "w");
    fclose(fp);
    output_to_file(arr, n);
    return ;
}

void list_students() {
    int len = printf("%4s|%10s|%4s|%6s|%7s|\n",
          "id", "name", "age", "class", "height"
          );
    for (int i = 0; i < len; i++) printf("=");
    printf("\n");

    for (int i = 0; i < scnt; i++) {
        printf("%4d|%10s|%4d|%6d|%7.2lf|\n",
                i, stus[i].name,
               stus[i].age, stus[i].class,
               stus[i].height
              );
    }
    return ;
}

void add_a_student() {
    printf("Add new item as example: name age class height\n");
    printf("mysql > ");
    scanf("%s%d%d%lf",
        stus[scnt].name,
        &stus[scnt].age,
        &stus[scnt].class,
        &stus[scnt].height
         );
    output_to_file(stus + scnt, 1);
    scnt++;
    printf("Add Success!!\n");
    return ;
}

void modify_a_student() {
    list_students();

    int id;
    do{
        printf("Modify ID : ");
        scanf("%d", &id);
    } while((id < 0 || id >= scnt) && printf("Invalid ID!!\n"));
    printf("Modifif item as example: name age class height\n");
    printf("mysql > ");
    scanf("%s%d%d%lf",
        stus[id].name,
        &stus[id].age,
        &stus[id].class,
        &stus[id].height
         );
    restore_data_to_file(stus, scnt);
    printf("Modify Success!!\n");
    return ;
}

void delete_a_student() {
    if(scnt == 0) {
        printf("There is no student\n");
        return ;
    }
    list_students();

    int id;
    do{
        printf("Delete ID : ");
        scanf("%d", &id);
    } while((id < 0 || id >= scnt) && printf("Invalid ID!!\n"));
    char s[100];
    printf("confirm (y/n) : ");
    while(getchar() != '\n');
    scanf("%[^\n]", s);
    if (s[0] != 'y') return ;
    
    for (int i = id + 1; i < scnt; i++) {
        stus[i - 1] = stus[i];
    }
    scnt--;
    restore_data_to_file(stus, scnt);
    printf("Delete Success!!\n");
    return ;

}

enum NO_TYPE {
    LIST = 1,
    ADD,
    MODIFY,
    DELETE,
    QUIT
};

int usage() {
    int no;
    do {
        printf("\n\n");
        printf("%d : List students\n", LIST);
        printf("%d : Add a new student\n", ADD);
        printf("%d : Modify a student\n", MODIFY);
        printf("%d : Delete a student\n", DELETE);
        printf("%d : Quit\n", QUIT);
        printf("mysql > ");
        scanf("%d", &no);
        printf("Input no : %d\n", no);
    } while ((no < LIST || no > QUIT) && printf("Invalid Value!\n"));
    return no;
}

int main() {
    scnt = read_from_file(stus);
    
    while(1) {
        switch(usage()) {
            case LIST : {
                list_students();
            } break;
            case ADD : {
                add_a_student();
            } break;
            case MODIFY : {
                modify_a_student();
            } break;
            case DELETE : {
                delete_a_student();
            } break;
            case QUIT :
                printf("Quit\n"); exit(0); break;
        }


    }
    return 0;
}
