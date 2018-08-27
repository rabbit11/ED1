 #include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

//semelhante a busca pre ordem
No* minimo(No* t){
    stack s;

    if(!t){
        return NULL;
    }else{
        push(&s, t);
        No* aux;
        while(!vazio(&s)){
            aux = pop(&s);
            if(aux->esq){
                push(&s);
            }else{
                return pop(&s);
            }
        }
    }
}
