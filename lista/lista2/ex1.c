#include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

//versao recursiva
void largura(No* t){

    queue fila;

    processa(t);

    if(t->esq){
        push(t->esq);
    }
    if(t->dir){
        push(t->dir);
    }
    if(&fila != NULL){
        largura(pop(&fila));
    } //verifica antes de remover pois na raiz fila está vazia

    return;
}

//versao iterativa

void largura2(No* t){
    queue fila;
    push(t);

    while(&fila != NULL){
        processa(pop(&fila));
        if(t->esq){
            push(&fila, t->esq);
        }if(t->dir){
            push(&fila, t->dir);
        }
    }
}
