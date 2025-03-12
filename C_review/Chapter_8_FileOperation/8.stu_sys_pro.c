/*************************************************************************
	> File Name: 8.student_system_pro.c
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
const char* output_format = "%10s%4d%4d%7.2lf\n";
typedef struct Student {
    long offset;
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
    while(1) {
        long offset = ftell(fp);
        if (fscanf(fp, "%s", arr[i].name) == EOF) break;
        fscanf(fp, "%d%d%lf",
               &arr[i].age,
               &arr[i].class,
               &arr[i].height
              );
        arr[i].offset = offset;
        while(fgetc(fp) != '\n');
        i++;
    }
    fclose(fp);
    return i;
}

long output_to_file(Student *arr, int n) {
    FILE *fp = fopen(file_name, "a");
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp);
    for (int i = 0; i < n; i++) {
        fprintf(fp, output_format,
                arr[i].name, arr[i].age,
                arr[i].class, arr[i].height
        );
    }
    fclose(fp);
    return offset;
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
    stus[scnt].offset = output_to_file(stus + scnt, 1);
    scnt++;
    printf("Add Success!!\n");
    return ;
}

void modify_data_to_file(Student *stu) {
    FILE *fp = fopen(file_name, "r+");
    fseek(fp, stu->offset, SEEK_SET);
    fprintf(fp, output_format,
        stu->name, stu->age,
        stu->class, stu->height
    );
    fclose(fp);
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
    modify_data_to_file(stus + id);
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
        long offset = stus[i - 1].offset;
        stus[i - 1] = stus[i];
        stus[i - 1].offset = offset;
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
