/*************************************************************************
	> File Name: students_table.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 09 Mar 2025 10:41:53 PM CST
 ************************************************************************/


#include<stdio.h>
#include<database.h>
static const char *table_name = "class table";
static const char *table_file = "./data/class_data.dat";

typedef struct {
    char classname[20];
    int Stu_Number;
    char master[20];
} table_data;
static const char *header_name[] = {"classname", "Stu_Number", "master"};
static int header_len[] = {15, 7, 15};

#include "table_unit.b"

static void printData(void *__data) {
    table_data *data = (table_data *)(__data);
    char frm[100];
    sprintf(frm, "%%%ds|%%%dd|%%%ds|\n", header_len[0], header_len[1], header_len[2] );
    printf(frm,
        data->classname, data->Stu_Number, data->master
          );
    return ;
}

static void scanData(void *__data) {
    table_data *data = (table_data *)(__data);
    scanf("%s%d%s",
         data->classname, &(data->Stu_Number),
         (data->master) 
         );
    return ;
}
