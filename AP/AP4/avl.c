#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void inicializar( Arvore* arvore ){
    Arvore* nova = (Arvore*)malloc(sizeof(Arvore));
    nova->esq = nova->dir = 0;
    nova->altura = nova->bal = nova->dado = nova->size = 0;
}
void destruir( Arvore* arvore ){
    if(!arvore){
        return;
    }else{
        if(arvore->esq){
            destruir(arvore->esq);
        }if(arvore->dir){
            destruir(arvore->dir);
        }free(arvore);
    }
}
unsigned tamanho( Arvore* arvore ){
    if(!arvore){
        return 0;
    }else{
        if(arvore->esq){
            return 1 + tamanho(arvore->esq);
        }if(arvore->dir){
            return 1 + tamanho(arvore->dir);
        }
    }
}

int procurar( Arvore* arvore, Chave chave){
    if(!arvore){
        return 0;
    }else{
        if(chave < arvore->dado){
            procurar(arvore->esq, chave);
        }else if(chave > arvore->dado){
            procurar(arvore->dir, chave);
        }else{
            return 1;
        }
    }
}

int getAltura(arvore* a){
    if(!a){
        return 0;
    }else{
        return 1 + max(getAltura(a->esq), getAltura(a->dir));
    }
}
int getBal(arvore* a){
    return getAltura(a->dir) - getAltura(a->esq);

}
void inserir( Arvore* arvore, Chave chave){
    if(!arvore){
        Arvore* nova = (Arvore*)malloc(sizeof(Arvore));
        nova->bal = nova->size = 0;
        nova->dado = chave;
        nova->esq = nova->dir = 0;
        nova->bal = 0;
        nova->altura = 0;
        return;
    }else{
        if(chave < arvore->dado){
            inserir(arvore->esq, chave);
        }else if(chave > arvore->dado){
            inserir(arvore->dir, chave);
        }
    }
    getBal(arvore);

    if(arvore->bal == -2){
        if(chave < arvore->dado){
            rotEE(arvore);
        }else{
            rotED(arvore);
        }
    }else if(arvore->bal == 2){
        if(chave > arvore->dado){
            rotDD(arvore);
        }else{
            rotED(arvore);
        }
    }
    arvore->size++;

    return;
}

arvore* rotEE(arvore* a){
    arvore* b = a->esq;
    a->esq = b->dir;
    b->dir = a;

    return b;
}

arvore* rotDD(arvore* a){
    arvore* b = a->dir;
    a->dir = b->esq;
    b->esq = a;

    return b;
}

arvore* rotED(arvore* a){
    arvore* b = a->esq;
    arvore* c = b->dir;

    a->esq = c->dir;
    b->dir = c->esq;
    c->esq = b;
    c->dir = a;

    if(c->bal == -1){
        a->bal = 0;
        b->bal = 1;
        c->bal = 0;
    }else if(c->bal == -1){
        a->bal = -1;
        b->bal = 0;
        c->bal = 0;
    }else{
        a->bal = 0;
        b->bal = 0;
    }

    return c;
}

arvore* rotDE(arvore* a){
    arvore* b = a->dir;
    arvore* c = b->esq;

    a->dir = c->esq;
    b->esq = c->dir;
    c->esq = a;
    c->dir = b;

    return c;
}

arvore* remover( Arvore* arvore, Chave chave){
    if(!arvore){
        return arvore;
    }else{
        if(chave < arvore->dado){
            return remover(arvore->esq, chave);
        }else if(chave > arvore->dado){
            return remover(arvore->dir, chave);
        }else{
            if(!arvore->dir){
                arvore* esquerda = arvore->esq;
                free(arvore);
                return esquerda;
            }if(!arvore->esq){
                arvore* direita = arvore->dir;
                free(arvore);
                return direita;
            }
            arvore->dado = maior(arvore->esq)->dado;
            arvore->esq = remover(arvore->esq, arvore->esq->dado);
        }
    }
}
