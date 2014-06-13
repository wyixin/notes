/*
   +----------------------------------------------------------------------+
   | 员工管理系统 V 0.1                                                   |
   +----------------------------------------------------------------------+
   | 安装：                                                               |
   |      sudo apt-get install libmysqlclient-dev mysql-server            |
   |      gcc main.c -o main  `mysql_config --cflags --libs`              |
   +----------------------------------------------------------------------+
   | 使用方式:                                                            |
   +----------------------------------------------------------------------+
   | Authors:                                                             |
   +----------------------------------------------------------------------+
*/
#include <string.h>
#include <my_global.h>
#include <mysql.h>
#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "root"
#define DB_NAME "test"

void finish_with_error(MYSQL *con){
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void excute_query(MYSQL *con, char *query){
    if(mysql_query(con, query))
        finish_with_error(con);
}

void help(){
    printf("This is help");
}

void one_line_help(){
    printf("Usage: ./maim -i|-d|-l|-u|-s|-h + [params]\n");
}

void insert(MYSQL *con, char *name, char *gender, char *b_day, char *w_day, char *xl, char *zw, char *addr, char *phone){
    char sql[200];
    sprintf(sql, "insert into users (name, gender, birth_day, work_day, xl, zw, addr, phone) values('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')", name, gender, b_day, w_day, xl, zw, addr, phone); 
    excute_query(con, sql);
}

void delete(MYSQL *con, char *id){
    char sql[20];
    sprintf(sql, "delete from users where id = %s", id);
    excute_query(con, sql);    
}

void list(MYSQL *con){
    char *sql = "select * from users order by name";
    excute_query(con, sql);

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL){
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    MYSQL_FIELD *field;
    int i = 0;
    
    while ((row = mysql_fetch_row(result))){
        for(i; i < num_fields; i++){
            if (i == 0){
                printf("%s %s   %s %s %s  %s  %s  %s  %s", "编号", "姓名", "性别", "出生年月", "工作年月", "学历", "职务", "住址", "电话");
                printf("\n");
            }
            
            printf("%s  ", row[i] ? row[i] : "NULL");
        }
    }

    printf("\n");

    mysql_free_result(result);
}

void update(MYSQL *con, char *id, char *field, char *value){
    char sql[40];
    sprintf(sql, "update users set %s = '%s' where id = %s", field, value, id);
    excute_query(con, sql);    
}

void sort(){
    printf("This is sort");
}

int main(int argc, char **argv)
{
    char *opt;
    MYSQL *con = mysql_init(NULL);

    if (con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    mysql_options(con, MYSQL_SET_CHARSET_NAME, "utf8");

    if (mysql_real_connect(con, DB_HOST, DB_USER, DB_PASS,
            DB_NAME, 0, NULL, 0) == NULL) {
        finish_with_error(con);
    }
    
    if(argc == 1){
        opt = "-h";
    } else {
        opt = argv[1];
    }

    if(!strcmp(opt, "-h")){
        help();
    } else if(!strcmp(opt, "-i")){
        insert(con, argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
    } else if(!strcmp(opt, "-d")){
        delete(con, argv[2]);
    } else if(!strcmp(opt, "-l")){
        list(con);
    } else if(!strcmp(opt, "-u")){
        update(con, argv[2], argv[3], argv[4]);
    } else if(!strcmp(opt, "-s")){
        //TODO sort();
        list(con);
    } else {
        one_line_help();
    }

    mysql_close(con);

    exit(0);
}
