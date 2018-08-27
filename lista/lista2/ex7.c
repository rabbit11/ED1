 #include <stdio.h>

typedef struct no{
    int v;
    struct no *esq, *dir;
}No;


int expr_valida(ap_no t){
    int vetnum[10];
    stack s;
    No* temp;

    //vetor para checagem dos operandos
    for(int i = 0; i < 10; i++){
        vetnum[i] = i;
    }

    if(t){
        push(&s, t);
    }
    //flag2 checa se nós folha são ou não operandos
    int flag2 = 0;

    while(!vazia(&s)){
        temp = pop(&s);

        flag2 = 1;
        if(!(temp->v == + || temp->v == - || temp->v == * || temp->v == * || flag2 == 1)){
            return 0;
        }else{
            flag2 = 0;
            int flag = 0;
            for(int i = 0; i < 10; i++){
                //checagem se operando é valido
                if(vetnum[i] == temp->v){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                return 0;
            }
        }
        if(temp->esq){
            push(&s, temp->esq);
        }if(temp->dir){
            push(&s, temp->dir);
        }
    }
    if(flag2 == 1){
        return 0;
    }else{
        return 1;
    }
}