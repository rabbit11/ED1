#ifndef AVL_H_
#define AVL_H_

typedef struct arvore{
    struct arvore* esq;
    struct arvore* dir;
    int dado, bal, size, altura;
}Arvore;

typedef int Chave;
typedef int Dados;

void inicializar( Arvore* arvore );
void destruir( Arvore* arvore );
unsigned tamanho( Arvore* arvore );
int procurar( Arvore* arvore, Chave chave);
void inserir( Arvore* arvore, Chave chave);
arvore* remover( Arvore* arvore, Chave chave);
arvore* rotEE(arvore* a);
arvore* rotDD(arvore* a);
arvore* rotED(arvore* a);
arvore* rotDE(arvore* a);

#endif
