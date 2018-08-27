 #include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;

//escolhi percurso pre ordem
int existe_chave_negativa(No* t){
    stack s;

    create(&s, MAX);
    push(&s, t);

    No* temp;
    while(!empty(&s)){
        temp = pop(&s);
        if(temp->v < 0){
            return 1;
        }else{
            if(temp->esq){
                push(&s, temp->esq);
            }if(temp->dir){
                push(&s, temp->dir);
            }
        }
    }
    return 0;

}