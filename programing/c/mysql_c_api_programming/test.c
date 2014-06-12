#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char *opt;
    opt = argv[1];

    printf("%s\n", opt);
    
    if(!strcmp(opt, "-h")){
        printf("help");
    } else if(!strcmp(opt, "-i")){
        printf("insert");
    }
     
}
/*
int main(int argc, char *argv){
    int i;
    //    char *input;
    printf(argc);
    for(i=1; i<argc; i++) printf("%s ", argv[i]);
    printf( "Start input: \n" );
    //    scanf( "%c", &input );
    /*
    switch (input) {
    case "all":
        all();
        break;
    case "insert":
        insert();
        break;
    }
}*/
