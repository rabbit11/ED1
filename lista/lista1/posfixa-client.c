#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "posfixa.h"
#include "pilhavet.h"
#include "prefixo.h"

int main(){
    stack a;
    stack b;
    char infix[100];
    char posfix[100];
    char prefix[100];

    gets(infix);

    transforma(infix, posfix, a);
    for(int j = 0; posfix[j] != '\0'; j++){
        printf("%c", posfix[j]);
    }
    printf("\n");

    printf(" --------------------\n");

    transformar(infix, prefix, a, b);
    for(int j = 0; prefix[j] != '\0'; j++){
        printf("%c", prefix[j]);
    }

    return 0;
}
