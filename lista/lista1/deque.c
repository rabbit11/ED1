#include <stdio.h>
#include <stdlib.h>
#include "deque.h"


int cria_fila(queue* a){
    a->ini = NULL;
    a->fim = NULL;
    a->flag = 0;
}

int fila_vazia(queue* a){
    return a->flag;
}

int insere_frente(queue* a, int item){
    no* novo = (no*)malloc(sizeof(no));
    novo->item = item;
    novo->ante = NULL;
    novo->prox = a->ini;
    if(fila_vazia(a) == 0){
        novo->prox = NULL;
        a->flag = 1;
        a->fim = novo;
    }
    a->ini->ante = novo;
    a->ini = novo;
}

int insere_final(queue* a, int item){
    no* novo = (no*)malloc(sizeof(no));
    novo->item = item;
    novo->prox = NULL;
    novo->ante = a->fim;
    if(fila_vazia(a) == 0){
        novo->ante = NULL;
        a->flag = 1;
        a->ini = novo;
    }
    a->fim->prox = novo;
    a->fim = novo;
}

int remove_frente(queue* a){
    no* aux = a->ini;
    if(a->ini == a->fim){
        a->ini = NULL;
        a->fim = NULL;
        a->flag = 0;
        free(aux);
    }
    aux->prox->ante = NULL;
    a->ini = a->ini->prox;
    free(aux);
}

int remove_final(queue* a){

}
