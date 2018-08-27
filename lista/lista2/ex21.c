#include <stdio.h>

typedef struct no{
    int v;
    int bal;
    struct no *esq, *dir;
}No;

//bal = hd - he
//isso funciona?
int altura_avl(No* t){
    if(!t){
        return 0;
    }else{
        if(t->bal < 0){
            return 1 + altura_avl(t->esq);
        }if(t->bal > 0){
            return 1 + altura_avl(t->dir);
        }else{
            return 1 + altura_avl(t->dir);
        }
    }
}