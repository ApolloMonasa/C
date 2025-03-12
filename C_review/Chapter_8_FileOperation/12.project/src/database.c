/*************************************************************************
	> File Name: database.c
	> Author: HDU-Apollo
	> Mail: xyl6716@outlook.com
	> Created Time: Sun 09 Mar 2025 07:58:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<database.h>


struct Database db;//存储当前数据库信息

__attribute__((constructor))
void init_db() {
    db.table      = NULL;
    db.table_file = NULL;
    db.table_name = NULL;
    db.head.next  = NULL;
    return ;
}

struct TableInfo tables[100];
int table_cnt = 0;

void register_table(const char *table_name, InitTable_T init_table) {
    tables[table_cnt].table_name = table_name;
    tables[table_cnt].init_table = init_table;
    table_cnt++;
    return ;
}

static struct table_data *getNewTableData(void *data, long offset) 
{
    struct table_data *p  = (struct table_data *)malloc(sizeof(struct table_data));
    p->data = (void *)malloc(db.getDataSize());
    memcpy(p->data, data, db.getDataSize());
    p->offset = offset;
    p->next = NULL;
    return p;
}

static void destroyTableData(struct table_data *p) {
    free(p->data);
    free(p);
    return ;
}

static void load_table_data() {
    char buff[db.getDataSize()];//缓冲区
    struct table_data *p = &(db.head);
    int data_cnt = 0;
    while (1) {
        long offset = ftell(db.table);
        if (fread(buff, db.getDataSize(), 1, db.table) == 0) break;
        //打包成为链表节点
        p->next = getNewTableData(buff, offset);
        p = p->next;
        data_cnt++;
    }
    printf("Successfully load %d Item(s)\n", data_cnt);
    return ;
}

static void open_table() {
    FILE *fp = fopen(db.table_file, "a");
    fclose(fp);
    db.table = fopen(db.table_file, "rb+");
    if (db.table == NULL) {
        printf("Can't Open File : %s\n",
               db.table_file);
        exit(1);
    }
    load_table_data();
    return ;
}

static void clear_table() {
    struct table_data *p = db.head.next, *q;
    while (p) {
        q = p->next;
        destroyTableData(p);
        p = q;
    }
    return ;
}

static void close_table() {
    clear_table();// 清空链表
    if(db.table == NULL) return ;
    fclose(db.table);
    return ;
}

static enum OP_TYPE choose_table() {
    for (int i = 0; i < table_cnt; i++) {
        printf("%d : %s\n", i, tables[i].table_name);
    }
    printf("%d : quit\n", table_cnt);
    int x;
    do {
        printf("Input :");
        scanf("%d", &x);
    } while ((x < 0 || x > table_cnt) && printf("Invalid Input!\n"));
    if (x < table_cnt) {
        close_table();
        tables[x].init_table(&db);
        open_table();//加载表信息
        return TABLE_USAGE;
    }
    return OP_END;
    return TABLE_USAGE;
}

static enum OP_TYPE table_usage() {
    printf("1 : List %s\n", db.table_name);  
    printf("2 : Add One Item To %s\n", db.table_name);  
    printf("3 : Modify An Item In %s\n", db.table_name);  
    printf("4 : Delete One Item From %s\n", db.table_name);  
    printf("5 : Back\n"); 
    int x;
    do {
        printf("Input : ");
        scanf("%d", &x);
    } while((x < 1 || x > 5) && printf("Invalid Input!\n"));
    if (x == 1) return LIST_TABLE;
    if (x == 2) return ADD_TABLE;
    if (x == 3) return MODIFY_TABLE;
    if (x == 4) return DELETE_TABLE;
    return CHOOSE_TABLE;
}

static void printTableHeader() {
    int len = 0;
    len += printf("%5s|", "id");
    char frm[100];
    for (int i = 0; i < db.header_cnt; i++) {
        sprintf(frm, "%%%ds|", db.header_len[i]);
        len += printf(frm, db.header_name[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    return ;
}

static int __list_table() {
    struct table_data *p = db.head.next;
    int id = 0;
    printTableHeader();
    while (p) {
        printf("%5d|", id);
        db.printData(p->data);//每个表的数据都是不一样的
        p = p->next;
        id++;
    }
    return id;
}

static enum OP_TYPE list_table() {
    struct table_data *p = db.head.next;
    int id = 0;
    printTableHeader();
    while (p) {
        printf("%5d|", id);
        db.printData(p->data);//每个表的数据都是不一样的
        p = p->next;
        id++;
    }
    return TABLE_USAGE;
}

static long add_one_table_data(void *buff) {
    fseek(db.table, 0, SEEK_END);
    long offset = ftell(db.table);
    struct table_data *p = &(db.head);
    while (p->next) p = p->next;
    p->next = getNewTableData(buff, offset);
    fwrite(buff, db.getDataSize(), 1, db.table);
    fflush(db.table);
    printf("Data Add Successfully!!\n");
    return offset;
}

static enum OP_TYPE add_table() {
    printf("add new item : (");
    for (int i = 0; i < db.header_cnt; i++) {
        if(i) printf(",");
        printf("%s", db.header_name[i]);
    }
    printf(")\n");
    printf("Input : ");
    char buff[db.getDataSize()];
    db.scanData(buff);
    add_one_table_data(buff);
    return TABLE_USAGE;
}

static void modify_one_table_data(void *buff, int id) {
    struct table_data *p = db.head.next;
    for (int i = 0; i < id; i++) p = p->next;
    memcpy(p->data, buff, db.getDataSize());
    fseek(db.table, p->offset, SEEK_SET);
    fwrite(buff, db.getDataSize(), 1, db.table);
    fflush(db.table);
    return ;
}

static enum OP_TYPE modify_table() {
    int n = __list_table();
    int id;
    do {
        printf("Modify ID(Input %d Back) : ", n);
        scanf("%d", &id);
    } while ((id < 0 || id > n) && printf("Invalid ID!!\nInput again : "));
    if (id == n) return TABLE_USAGE;

    printf("Modify Item(id = %d) : (", id);
    for (int i = 0; i < db.header_cnt; i++) {
        if(i) printf(",");
        printf("%s", db.header_name[i]);
    }
    printf(")\n");
    printf("Input : ");
    char buff[db.getDataSize()];
    db.scanData(buff);
    
    modify_one_table_data(buff, id);

    printf("Modify Data Successfully!!\n");
    return TABLE_USAGE;
}

static void clearTableData() {
    fclose(db.table);
    db.table = fopen(db.table_file, "w");
    fclose(db.table);
    db.table = fopen(db.table_file, "rb+");
    struct table_data *p = db.head.next, *q;
    while (p) {
        q = p->next;
        destroyTableData(p);
        p = q;
    }
    db.head.next = NULL;
    return ;
}

static void restoreTableData() {
    struct table_data *p = db.head.next, *q;
    db.head.next = NULL;
    clearTableData();
    while (p) {
        q = p->next;
        add_one_table_data(p->data);
        destroyTableData(p);
        p = q;
    }
    return ;
}

static enum OP_TYPE delete_table() {
    int n = __list_table();
    int id;
    do {
        printf("Modify ID(Input %d Back) : ", n);
        scanf("%d", &id);
    } while ((id < 0 || id > n) && printf("Invalid ID!!\nInput again : "));
    if (id == n) return TABLE_USAGE;
    
    struct table_data *p = &(db.head), *q;
    for (int i = 0; i < id; i++) p = p->next;
    q = p->next;
    p->next = q->next;
    destroyTableData(q);
    restoreTableData();
    printf("Delete Item Successfully!!\n");
    return TABLE_USAGE;
}

enum OP_TYPE run(enum OP_TYPE status) {
    switch (status) {
        case CHOOSE_TABLE : {
            return choose_table();
        } break;
        case TABLE_USAGE : {
            return table_usage();
        } break;
        case LIST_TABLE : {
            return list_table();
        } break;
        case ADD_TABLE : {
            return add_table();
        } break;
        case MODIFY_TABLE : {
            return modify_table();
        } break;
        case DELETE_TABLE : {
            return delete_table();
        } break;
        default : {
            printf("Unknown Status : %d\n", status);
        } break;
    }
    return OP_END;
}

void run_database() {
    enum OP_TYPE status = CHOOSE_TABLE;
    while (1) {
        status = run(status);
        if(status == OP_END) break;
    }
    return ;
}
