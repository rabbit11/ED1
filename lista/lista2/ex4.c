#include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

int n_rec_inorder(No* t){
    stack pilha;
    push(t);
    No* aux = t;


    while(&pilha != NULL){
        aux = topo(&pilha);
        if(aux->esq){
            push(&pilha,aux->esq);
        }
        pop(&pilha);

        if(aux->dir){
            push(&pilha, aux->dir);
        }
}
