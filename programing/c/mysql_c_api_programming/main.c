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
//char *create_query = "CREATE DATABASE test";
//excute_query(con, create_query);

void insert(MYSQL *con, char *name, char *gender, char *b_day, char *w_day, char *xl, char *zw, char *addr, char *phone){
    char sql[200];
    sprintf(sql, "insert into users (name, gender, birth_day, work_day, xl, zw, addr, phone) values('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')", name, gender, b_day, w_day, xl, zw, addr, phone); 
    printf(sql);
    excute_query(con, sql);
}

void delete(){
    printf("This is delete");
}

void list(){
    printf("This is list");
}

void update(){
    printf("This is update");
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
        // insert(con, "wyx", "n", "201111", "201111", "hg", "xs", "beiqu", "1342982");
        insert(con, argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
    } else if(!strcmp(opt, "-d")){
        delete();
    } else if(!strcmp(opt, "-l")){
        list();
    } else if(!strcmp(opt, "-u")){
        update();
    } else if(!strcmp(opt, "-s")){
        sort();
    } else {
        one_line_help();
    }

    mysql_close(con);

    exit(0);
}
