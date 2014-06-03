
#include <stdio.h>

int main(int argc, char *argv[]) 
{
    // go through each string in argv
/*
    int i = 0;
    while(i < argc) {
        printf("arg %d: %s \n", i, argv[i]);
        i++;
    }
    
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;
    i=0;
    
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }
*/
    int i = 0;
    char *test_states[] = {"California", "Oregon", "Washington", "Texas"};
    int num_states = 4;
    while(i < argc) {
        test_states[i] = argv[i + 1];
        i++;
    }
    
    while(i > 0) {
        printf("from argc %d: %s\n", i, test_states[i]);
        i--;
    }
    
    return 0;
}