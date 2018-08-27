 #include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

//versao interativa
//NÃO TERMINADA
No* vet2arv(int vet[], int n){
    //n seria o numero de elementos no vetor???
    //considerando que sim:
    int half = n / 2;

    No* raiz = (No*)malloc(sizeof(No));
    raiz->v = vet[half];
    raiz->esq = raiz->dir = 0;

    No* aux = raiz;
    for(int i = 0; i < n; i++){
        if(vet[i] < raiz->v){
            while(aux->esq && vet[i] < aux->v){
                aux = aux->esq;
            }
            No* novo = (No*)malloc(sizeof(No));
            novo->v = vet[i];
            aux->esq= novo;

        }else if(vet[i] > raiz->v){
            while(aux->dir && vet[i] > aux->v){
                aux = aux->esq;
            }
            No *novo = (No*)malloc(sizeof(No));
            novo->v = vet[i];
            aux->dir = novo;

        }else{
            aux->v = vet[i];
        }
    }
}