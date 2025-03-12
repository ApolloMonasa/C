/*************************************************************************
	> File Name: students_table.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 09 Mar 2025 10:41:53 PM CST
 ************************************************************************/


static void init_table(struct Database *);
static size_t getDataSize();
static void printData(void *);
static void scanData(void *);
static int header_cnt;

__attribute__((constructor))
static void __register_table() {
    register_table(table_name, init_table);
    return ;
}

void init_table(struct Database *db) {
    db->table_name = table_name;
    db->table_file = table_file;
    db->getDataSize = getDataSize;
    db->printData = printData;
    db->scanData = scanData;
    db->header_name = header_name;
    db->header_len = header_len;
    db->header_cnt = sizeof(header_len) / sizeof(header_len[0]);
    return ;
}

size_t getDataSize() {
    return sizeof(table_data);
}
