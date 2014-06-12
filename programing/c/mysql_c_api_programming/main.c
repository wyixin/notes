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


//char *create_query = "CREATE DATABASE test";
//excute_query(con, create_query);

void insert(){
    printf("This is insert");
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
        insert();
    } else if(!strcmp(opt, "-d")){
        delete();
    } else if(!strcmp(opt, "-l")){
        list();
    } else if(!strcmp(opt, "-u")){
        update();
    } else if(!strcmp(opt, "-s")){
        sort();
    }

    mysql_close(con);

    exit(0);
}
