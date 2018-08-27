#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rational.h"

int main(int argc, char* argv[]){
    
    if(argc != 6){
        return 0;
    }
    
    int numerator = atoi(argv[1]);
    int denominator = atoi(argv[2]);
    rational a = define(numerator, denominator);

    numerator = atoi(argv[3]);
    denominator = atoi(argv[4]);
    rational b = define(numerator, denominator);

    int operacao = atoi(argv[5]);
    rational r;
    int igual;

    switch(operacao){
        case 1:
            r = plus(a, b);
            break;
        case 2:
            r = minus(a, b);
            break;
        case 3:
            r = times(a, b);
            break;
        case 4:
            r = divides(a, b);
            break;
        case 5:
            igual = equals(a, b);
            break;
    }

    char msg[512];
    toString(r,msg);
    printf("%s\n", msg);

    return 0;
}