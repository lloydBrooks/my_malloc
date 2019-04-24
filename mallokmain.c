#include <stdio.h>

#include "mallok.h"

typedef struct tester_tag {
    int number;
    char name[100];
    
    
}Tester;


void main(void) {
    create_pool(113);
    printf("pool created.\n");
    int* intP = my_malloc(sizeof(int));
    char* charP = my_malloc(sizeof(char)); 
    double* doubleP = my_malloc(sizeof(double));
    Tester* testerP = my_malloc(sizeof(Tester));
    printf("memory allocated.\n");
    my_free(testerP);
    my_free(doubleP);
    my_free(charP);
    printf("memeory freed.\n");
    testerP = my_malloc(sizeof(Tester));
    doubleP = my_malloc(sizeof(double));
    printf("memory re-allocated.\n");
}