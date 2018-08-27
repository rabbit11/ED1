#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exe3.h"

void inicializar(lista* a){
    a->inicio = NULL;
    a->fim = NULL;
}

//insere no fim da lista
int inserircarro(lista* a, char placa[], char modelo[], char cor[]){
    no* novo = (no*)malloc(sizeof(no));
    strcpy(novo->placa, placa);
    strcpy(novo->modelo, modelo);
    strcpy(novo->cor, cor);
    novo->prox = NULL;
    a->fim.prox = novo;
    a->fim = novo;

    return 1;
}
int removercarro(lista* a, char placa[]){
    no* aux = a->inicio;
    no* aux2= a->inicio->prox;

    if(strcmp(aux->placa, placa) == 0){
        a->inicio = aux2;
        free(aux);
        return 1;
    }
    while(aux2 != NULL){
        if(strcmp(aux2->placa, placa) == 0){
            aux->prox = aux2->prox;
            free(aux);
            return 1;
        }
        aux = aux->prox;
        aux2 = aux2->prox;
    }
    return 0;
}
int alterar(lista* a, char placa[], char novaplaca[]){
    no* aux = a->inicio;

    while(aux != NULL){
        if(strcmp(aux->placa, placa) == 0){
            strcpy(aux->placa, novaplaca);
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}
int buscarcarro(lista* a, char placa[]){
    no* aux = a->inicio;

    while(aux != NULL){
        if(strcmp(aux->placa, placa) == 0){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}
