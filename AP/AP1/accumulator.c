#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accumulator.h"

void initialize(acumulator *a){

    a->total = 0;
    a->quantidade = 0;
}

void addDataValue(acumulator *a, double val){
    a->total += val;
    a->quantidade++;
}

double mean(acumulator *a){
    return (a->total / a->quantidade); 
}

double value(acumulator *a){
    return a->total;
}

void toString(acumulator *a, char *str){
    sprintf(str,"total: %lf\nmedia: %lf\n", a->total, (mean(a)));
}