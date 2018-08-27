#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "complex.h"

typedef struct _complex{
    double re, im;
}*Complex;

// Create a new `Complex` number from two `double`s.
Complex newComplex(double re, double im){
    Complex a = malloc(sizeof(Complex));
    a->re = re;
    a->im = im;

    return a;
}

// Release all resources associated with a `Complex` number.
void destroyComplex(Complex c){
    free(c);
}

// Retrieve the real part of the `Complex` number.
double complexRe(Complex c){
    double real;
    real = c->re;

    return real;
}

// Retrieve the imaginary part of the `Complex` number.
double complexIm(Complex c){
    double imaginary;
    imaginary = c->im;

    return imaginary;
}

// Add two `Complex` numbers together.
Complex complexAdd(Complex w, Complex z){
    Complex result = newComplex(w->re + z->re, w->im + z->im);
    //result->re = w->re + z->re;
    //result->im = w->im + z->im;

    return result;
}

// Multiply two `Complex` numbers together.
Complex complexMultiply(Complex w, Complex z){
    Complex result = newComplex(w->re * z->re - (w->im * z->im), w->re * z->im + w->im * z->re);

    return result;
}

// Take the magnitude (or modulus, or absolute) of a `Complex` number.
double complexMod(Complex w){
    double result;

    result = sqrt((w->re) * (w->re) + (w->im) * (w->re));

    return result;
}

// Take the argument (or angle) of a `Complex` number.
double complexArg(Complex w){
    double argument;
    
    argument = ((w->im) * (w->im) +(w->re) * (w->re)) / w->im;

    return argument;
}