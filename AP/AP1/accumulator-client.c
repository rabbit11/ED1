#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accumulator.h"

int main(int argc, char *argv[]){

    if(argc == 1){
        printf("0\n");
        return 0;
    }

    int i = 1;
    acumulator entrada;

    initialize(&entrada);

    while ((argv[i] != '\0')){
        int j = atoi(argv[i]);
        addDataValue(&entrada, j);
        i++;
    }

    char msg[512];
    toString(&entrada, msg);
    printf("%s", msg);
    //printf("oi eu sou o accumulator\n");

    return 0;
}