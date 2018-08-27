#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

int conta_folhas(No* t){
    int size = 0;

    if(t->esq){
        conta_folhas(No* t->esq);
    }
    if(t->dir){
        conta_folhas(No* t->dir);
    }
    else if(!t->esq && !t->dir){
        return size++;
    }

}
