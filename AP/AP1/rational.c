#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rational.h"

// Cria um numero racional e retorna
rational define(int numerator, int denominator){
    //rational a = (rational)malloc(sizeof(rational));
    rational a;
    a.numerator = numerator;
    a.denominator = denominator;

    return a;
}

// Retorna a+b
rational plus(rational a, rational b){
    //caso os denominadores sejam iguais
    if(a.denominator == b.denominator){
        rational c;
        c.numerator = a.numerator + b.denominator;
        c.denominator = a.denominator;
        return c;
    }
    //caso os denominadores sejam multiplos
    if((a.denominator % b.denominator) != 0){
        rational c;
        c.denominator = a.denominator - b.denominator;
        //conferindo se no caso o denominador de b é maior que o de a e por isso resulta em deno. neg.
        if(c.denominator < 0){
            c.denominator = c.denominator * -1;
            c.numerator = a.denominator * c.denominator + b.numerator;
            return c;
        }
        //caso o deno. de b seja menor que o de a, nao precisamos multipilicar por -1 para tornar posit.
        c.numerator = a.numerator + b.numerator * c.denominator;

        return c;
    }else{
        rational c;
        c.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
        c.denominator = a.denominator * b.denominator;

        return c;
    }
}

// Retorna a-b
rational minus(rational a, rational b){
    //caso os denominadores sejam iguais
    if (a.denominator == b.denominator)
    {
        rational c;
        c.numerator = a.numerator - b.denominator;
        c.denominator = a.denominator;
        return c;

    }
    //caso os denominadores sejam multiplos
    if ((a.denominator % b.denominator) != 0)
    {
        rational c;
        c.denominator = a.denominator - b.denominator;
        //conferindo se no caso o denominador de b é maior que o de a e por isso resulta em deno. neg.
        if (c.denominator < 0)
        {
            c.denominator = c.denominator * -1;
            c.numerator = a.denominator * c.denominator - b.numerator;
            return c;
        }
        //caso o deno. de b seja menor que o de a, nao precisamos multipilicar por -1 para tornar posit.
        c.numerator = a.numerator - b.numerator * c.denominator;

        return c;
    }
    else
    {
        rational c;
        c.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
        c.denominator = a.denominator * b.denominator;

        return c;
    }
}

// Retorna a*b
rational times(rational a, rational b){
    rational c;
    c.numerator = a.numerator * b.numerator;
    c.denominator = a.denominator * b.denominator;

    return c;
}

// Retorna a/b
rational divides(rational a, rational b){
    rational c;
    c.numerator = a.numerator * b.numerator;
    c.denominator = a.denominator * b.numerator;

    return c;
}

// Retorna 0, caso 'a' seja diferente de 'b'
int equals(rational a, rational b){
    if(a.numerator == b.numerator){
        if(a.denominator == b.denominator){
            return 1;
        }
    }else if((a.numerator / a.denominator) == (b.numerator / b.denominator)){
        return 1;

    }else{
        return 0;
    }
}

// Preenche 'str' com o numero 'r' no fomato 'numerador/denominador'
void toString(rational r, char *str){
    sprintf(str, "%d/%d", r.numerator, r.denominator);
}
