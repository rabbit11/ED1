#include <stdlib.h>
#include <stdio.h>
#include "listadupla.h"


void inicializa(Lista *l) {
	l->ini = NULL;
    l->fim = NULL;
	l->qtd = 0;
}

void insereInicio(Lista *l, T item) {
	No* p = (No*)malloc(sizeof(No));
	p->item = item;
	p->prox = l->ini;
    p->anterior = NULL;
	l->ini = p;
	if(l->fim == NULL){
		l->fim = l->ini;
		// printf("oi eu sou o fim %c\n", l->fim->item);
	}
	l->qtd++;
}
void insereFim(Lista *l, T item){
    No* p = (No*)malloc(sizeof(No));
    p->item = item;
    p->prox = NULL;
    p->anterior = l->fim;
	l->fim->prox = p;
	// printf("oi eu sou o fim %c\n", l->fim->item);
    l->fim = p;
	// printf("oi eu sou o fim %c\n", l->fim->item);

	if(l->ini == NULL){
		l->ini = l->fim;
	}
    l->qtd++;
}

void removeInicio(Lista *l, T* item) {
	if(l->ini != NULL) {
    		No* p = l->ini;
    		l->ini = l->ini->prox;
			l->ini->anterior = NULL;
    		*item = p->item;
    		free(p);
            //caso a lista possua um unico termo (portanto fim e inicio apontam para o mesmo termo)
            if(l->ini == l->fim){
                l->fim = l->ini;
            }
	}
}

void removeFim(Lista *l, T* item){
    if(l->fim != NULL){
        No* p = l->fim;
        l->fim = l->fim->anterior;
        l->fim->prox = NULL;
        *item = p->item;
        free(p);
        //caso a lista possua um unico termo (portanto fim e inicio apontam para o mesmo)
        if(l->fim == l->ini){
            l->ini = l->fim;
        }
    }
}

void removeDepois(Iterador* it, T* item){ // checar
    if(it->p->prox != NULL){
        No* removido = it->p->prox;
        it->p->prox = removido->prox;
        removido->prox->anterior = it->p;
        *item = removido->item;
        free(removido);
    }
}

void remover(Iterador* it, T* item){
    if(!acabou(it)){
        No* removido = it->p;
		if(it->p != it->l->fim){
			it->p->anterior->prox = removido->prox;
			removido->prox->anterior = it->p->anterior;
		}else{
			//daria para usar Remove Fim aqui?
			it->p->anterior->prox = NULL;
			it->l->fim = removido->anterior;
		}
        *item = removido->item;
        //o iterador agora deve apontar para o anterior do que foi removido ou o proximo?
        it->p = it->p->anterior;
        free(removido);
    }
}

void removeAntes(Iterador* it, T* item){
    No* removido = it->p->anterior;
    it->p->anterior->anterior->prox = it->p;
    it->p->anterior = it->p->anterior->anterior;
    *item = removido->item;
    free(removido);
}

Iterador inicio(Lista *l) {
	Iterador it;
	it.p = l->ini;
	it.l = l;
	return it;
}

Iterador fim(Lista *l){
    Iterador it;
    it.p = l->fim;
    it.l = l;
    return it;
}

void elemento(Iterador* it, T* item) {
	if(!acabou(it))
		*item = it->p->item;
}

void proximo(Iterador* it) {
	if( !acabou(it) ) {
		it->p = it->p->prox;
	}
}

void anterior(Iterador* it){
    if(!acabou(it)){
        it->p = it->p->anterior;
    }
}

int acabou(Iterador *it) {
	return it->p == NULL;
}

Iterador buscaPrimeiro(Lista* l, T item) {
	Iterador it = inicio(l);
	while( !acabou(&it) ) {
		if( it.p->item == item )
			return it;
		proximo(&it);
	}
	return it;
}

Iterador buscaUltimo(Lista* l, T item){
    Iterador it = fim(l);
    while(!acabou(&it)){
        if(it.p->item == item){
            return it;
        }
        anterior(&it);
    }
    return it;
}

Iterador buscaProximo(Iterador* it, T item) {
	while( !acabou(it) ) {
		if( it->p->item == item )
			return *it;
		proximo(it);
	}
	return *it;
}

Iterador buscaAnterior(Iterador* it, T item){
    while(!acabou(it)){
        if(it->p->anterior->item == item){
            return *it;
        }
        anterior(it);
    }
    return *it;
}

void insereDepois(Iterador* it, T item) {
	if(!acabou(it)) {
		No* novo = (No*)malloc(sizeof(No));
		novo->item = item;
		novo->prox = it->p->prox;
		novo->anterior = it->p;
		it->p->prox = novo;
		it->l->qtd++;
		if(it->p == it->l->fim){
			it->l->fim = novo;
		}
	}
}

int quantidade(Lista* l) {
	return l->qtd;
}

void insereAntes(Iterador* it, T item) {
	if(!acabou(it)) {
        No* novo = (No*)malloc(sizeof(No));
        novo->item = item;
        novo->prox = it->p;
		novo->anterior = it->p->anterior;
		it->p->anterior->prox = novo;
        it->p->anterior = novo;
        it->l->qtd++;
	}
}

int vazia(Lista* l){
    if(l->ini == NULL && l->fim == NULL){
        return 1;
    }
    return 0;
}
