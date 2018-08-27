#include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

int conta_nos(No* t){
    
    if(t->esq == NULL && t->dir == NULL){
        return 0;
    }else{
        return conta_nos(t->esq) + conta_nos(t->dir) + 1;
    }
}
