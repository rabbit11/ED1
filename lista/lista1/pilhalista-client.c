#include <stdio.h>
#include <stdlib.h>
#include "pilhalista.h"

int main()
{

    head cabeca;
    cabeca.contador = 0;
    cabeca.top = NULL;

    push(&(cabeca));
    printf("%d\n", size(cabeca));
    printf("%d\n", top(cabeca));
    pop(&(cabeca));
    push(&(cabeca));
    push(&(cabeca));
    printf("%d\n", size(cabeca));
    destroy(&(cabeca));

    return 0;
}