#ifndef EX4_H_
#define EXE4_H_

typedef char T;

typedef struct no {
	T item;
	struct no* prox;
    struct no* anterior;
} No;

typedef struct lista {
	No* ini;
    No* fim;
	int qtd;
} Lista;

typedef struct iterador {
	No* p;
	Lista *l;
} Iterador;

void inicializa(Lista* l);					// ja feita -
void destroi(Lista* l);						// ja feita -
void insereInicio(Lista* l, T item);		// ja feita -

void insereFim(Lista* l, T item);			// ja feita -

void removeInicio(Lista* l, T* item);		// ja feita -

void removeFim(Lista* l, T* item);			// ja feita -

Iterador inicio(Lista* l);					//ja feita -

Iterador fim(Lista* l);						//ja feita -

void elemento(Iterador* it, T* item);		//ja feita -
void proximo(Iterador* it);					//ja feita -
void anterior(Iterador* it);				//ja feita -

void insereFim(Lista* l, T item);			// ja feita -

void removeInicio(Lista* l, T* item);		// ja feita -

void removeFim(Lista* l, T* item);			// ja feita -

Iterador inicio(Lista* l);					//ja feita -

Iterador fim(Lista* l);						//ja feita -

void elemento(Iterador* it, T* item);		//ja feita -
void proximo(Iterador* it);					//ja feita -
void anterior(Iterador* it);				//ja feita -

int acabou(Iterador *it);					//ja feita -

Iterador buscaPrimeiro(Lista* l, T item);	//ja feita -

Iterador buscaUltimo(Lista* l, T item);		//ja feita -

Iterador buscaProximo(Iterador* it, T item);//ja feita -

Iterador buscaAnterior(Iterador* it, T item);//ja feita -

void insereDepois(Iterador* it, T item);	//ja feita -

void insereAntes(Iterador* it, T item);		//ja feita -
void removeDepois(Iterador* it, T* item);	//ja feita -
void remover(Iterador* it, T* item);		//ja feita -
void removeAntes(Iterador* it, T* item);	//ja feita -

int quantidade(Lista* l);					//ja feita -

int vazia(Lista* l);						//ja feita -

int nElementosrecur(No* p);
int nElementosite(No* p);
No* menorElementorecur(No* p);
No* menorElementoite(No* p);
No* inverteListarecur(No* p);
No* inverteListaite(No* p);
int remove_(No** l, int v);
int remove_recur(No** l, int v);
No* intercalaListas(No** x, No** y);
No* meio_da_lista(Lista* l);

#endif
