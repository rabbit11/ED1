#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complex.h"

int main(int argc, char* argv[]){

    if(argc != 5){
        return 0;
    }

    double re = atof(argv[1]);
    double im = atof(argv[2]);
    double re1 = atof(argv[3]);
    double im1 = atof(argv[4]);

    Complex w = newComplex(re, im);
    Complex z = newComplex(re1,im1);

    printf("chambrando\n");

    printf("Real part of complex number a %lf\n", complexRe(w));
    printf("chambrando\n");
    printf("Real part of complex number b %lf\n", complexRe(z));
    printf("chambrando\n");
    printf("Imaginary part of complex number a %lf\n", complexIm(w));
    printf("chambrando\n");
    printf("Imaginary part of complex number b %lf\n", complexIm(z));
    Complex resultado = complexAdd(w,z);
    printf("Adding a and b = %lf+ %lfi\n", complexRe(resultado), complexIm(resultado));
    resultado = complexMultiply(w,z);
    printf("Multiplying a and b  = %lf + %lfi\n", complexRe(resultado), complexIm(resultado));

    

    destroyComplex(w);
    destroyComplex(z);
    destroyComplex(resultado);
    
    return 0;
}