 #include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;


//max bal seria a maior altura das duas arvores?
int max_bal(No* t){
    int he,hd;
    he = hd = 0;

    if(!t){
        return 0;
    }else{
        if(t->esq){
            he+= 1 + max_bal(t->esq);
        }if(t->dir){
            hd += 1 + max_bal(t->dir);
        }
    }
    if (hd > he)
    {
        return hd;
    }
    else
    {
        return he;
    }
}