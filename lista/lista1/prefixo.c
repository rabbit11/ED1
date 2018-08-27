#include <stdio.h>
#include <stdlib.h>
#include "prefixo.h"
#include "posfixa.h"

void transformar(char infix[], char posfix[], stack a, stack b){
    create(&a, 100);
    push(&a, '#');
    push(&b, '#');
    int j = 0;

    for(int i = 0; infix[i] != '\0'; i++){
        if(operador(infix[i]) == 0){
            if(top(&b) != '#'){
                posfix[j] = pop(&b);
                j++;
            }push(&b, infix[i]);
        }else{
            if(infix[i] == '('){
                push(&a, infix[i]);
            }else if(infix[i] == ')'){
                // char b = 'a';
                while(top(&a) != '('){
                    // printf("%c\n", top(&a));
                    posfix[j] = pop(&a);
                    j++;
                }
                pop(&a);
            }else{
                if(precedencia(infix[i]) >= precedencia(top(&a))){
                    push(&a, infix[i]);
                }else{
                    while(precedencia(infix[i]) < precedencia(top(&a))){
                        posfix[j] = pop(&a);
                        j++;
                    }
                    push(&a, infix[i]);
                }
            }
        }
    }while(top(&a) != '#' && top(&a) != '\0'){
        posfix[j] = pop(&a);
        j++;
    }
    posfix[j] = '\0';

}
