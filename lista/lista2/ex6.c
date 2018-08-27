#include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

No *espelho(No *t){
    queue f;
    push(&f, t);
    No* e;

    while(f != NULL){
        No* temp = pop(&f);
        inserir_inversamente(e, temp);
        if(temp->esq){
            push(&f, temp->esq);
        }if(temp->dir){
            push(&f, temp->dir);
        }
    }
    return e;
}

//insere maiores elementos a esquerda e os menores a direita de cada nó
No *inserir_inversamente(No* e, No* temp){
    if(!e){
        No* novo = (No*)malloc(sizeof(No));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->v = 0;
        return novo;
    }else if(temp->v > e->v){
        e->esq = inserir_inversamente(e->esq, temp->v);
    }else if(temp->v < e->v){
        e->dir = inserir_inversamente(e->dir, temp->v);
    }else{
        e->v = temp->v;
    }
    return e;
}
