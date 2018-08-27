#ifndef DEQUE_H_
#define DEQUE_H_

typedef struct no_{
    struct no_* prox;
    struct no_* ante;
    int item;
}no;

typedef struct queue_{
    int flag;
    no* ini;
    no* fim;
}queue;

int cria_fila(queue* a);
int fila_vazia(queue* a);
int insere_frente(queue* a, int item);
int insere_final(queue* a, int item);
int remove_frente(queue* a);
int remove_final(queue* a);

#endif
