#include <stdio.h>
#include <stdlib.h>
#include "posfixa.h"
#include "pilhavet.h"


void transforma(char infix[], char posfix[], stack a){
    create(&a, 100);
    push(&a, '#');

    int j = 0;

    for(int i = 0; infix[i] != '\0'; i++){
        if(operador(infix[i]) == 0){
            posfix[j] = infix[i];
            j++;
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
int precedencia(char a){
    switch(a){
        case '+':
        return 1;
        break;

        case '-':
        return 1;
        break;

        case '*':
        return 2;
        break;

        case '/':
        return 2;
        break;

        case '^':
        return 3;
        break;

        case '(':
        return 0;
        break;

        case ')':
        return 0;
        break;

        case '#':
        return 0;
        break;

    }
}
int operador(char a){
    switch(a){
        case '+':
        return 1;
        break;

        case '-':
        return 1;
        break;

        case '*':
        return 1;
        break;

        case '/':
        return 1;
        break;

        case '^':
        return 1;
        break;

        case '(':
        return 1;
        break;

        case ')':
        return 1;
        break;

        default:
        return 0;
    }
}
