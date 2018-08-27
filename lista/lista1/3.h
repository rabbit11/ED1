#ifndef exe3_H_
#define exe3_H_

typedef struct _no{
    char placa[8], modelo[30], cor[20];
    struct no *proximo;
}no;

typedef struct_lista{
    no* inicio;
    no* fim;
}lista;

void inicializar(lista *a);
int inserircarro(lista *a, char placa[], char modelo[], char cor[]);
int removercarro(lista *a, char placa[]);
int alterar(lista *a, char placa[], char novaplaca[]);
int buscarcarro(lista *a, char placa);

#endif
