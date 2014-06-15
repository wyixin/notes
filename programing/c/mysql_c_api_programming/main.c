/*
   +----------------------------------------------------------------------+
   | 员工管理系统 V 0.1                                                   |
   +----------------------------------------------------------------------+
   | 安装：                                                               |
   |      sudo apt-get install libmysqlclient-dev mysql-server            |
   |      gcc main.c -o main  `mysql_config --cflags --libs`              |
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
    printf("员工管理系统使用指南\n\n");
    printf("用法：./main [OPTION]... [PARAMS]...\n");
    printf("-i insert    插入数据     -i 姓名 性别 出生年月 工作年月 学历 职务 住址 电话\n");
    printf("-d delete    删除数据     -d 员工编号\n");
    printf("-l list      列出数据     -l \n");
    printf("-u updata    更新数据     -u 需要更新员工的编号 待更新字段名字 更新数据 \n");
    printf("-s sort      排序输出     -s 排序字段名 排序方向\n");
    printf("-h help      帮助文档     -h\n");
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
    printf("%s", sql);
    excute_query(con, sql);    
}

void _list(MYSQL *con, char *sql){

    excute_query(con, sql);

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL){
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;
    MYSQL_FIELD *field;

    printf("%s %s   %s %s %s  %s  %s  %s  %s\n", "编号", "姓名", "性别", "出生年月", "工作年月", "学历", "职务", "住址", "电话");

    while ((row = mysql_fetch_row(result))){
        int i = 0;
        for(i; i < num_fields; i++){
            printf("%s  ", row[i] ? row[i] : "NULL");
        }
        printf("\n"); 
    }

    mysql_free_result(result);
}

void list(MYSQL *con){
    char *sql = "select * from users order by name";
    _list(con, sql);
}

void update(MYSQL *con, char *id, char *field, char *value){
    char sql[40];
    sprintf(sql, "update users set %s = '%s' where id = %s", field, value, id);
    excute_query(con, sql);    
}

void sort(MYSQL *con, char *field, char *direct){
    int i = 0;

    char sql[40];
    char *fields[] = {
        "name", "id"
    };
    int num_fields = 2;

    if(!direct || strcmp(direct, "desc"))
        direct = "asc";

    for( ; i < num_fields; i++){
        if(field && !strcmp(field, fields[i])){
            // found
            goto found;
        }
    }

    field = "id";

 found:
    sprintf(sql, "select * from users order by %s %s", field, direct);
    _list(con, sql);
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
        sort(con, argv[2], argv[3]);
     } else {
        one_line_help();
    }

    mysql_close(con);

    exit(0);
}
