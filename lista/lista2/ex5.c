#include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

int busca(No* t, int v){

    if(t->v == v){
        return 1;
    }else{
        if(t->esq){
            busca(t->esq);
        }if(t->dir){
            busca(t->dir);
        }
    }
    return 0;
}
