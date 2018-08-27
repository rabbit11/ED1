#include <stdio.h>

typedef struct no{
    int v;
    int bal;
    struct no *esq, *dir;
}No;

//contabilizaçao de he e hd funciona corretamente? ou deveria fazer a funçao sendo int?
void calcula_bal(No* t){
    int he,hd;
    he = hd = 0;

    if(!t){
        return 0;
    }else{
        if(t->esq){
           calcula_bal(t->esq);
           he++;
        }if(t->dir){
           calcula_bal(t->dir);
           hd++;
        }
        t->bal = hd - he;
    }
}
