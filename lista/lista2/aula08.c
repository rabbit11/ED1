#include "stdio.h"
#include "pilhalista.c"

void create(stack *s, unsigned max_size);
void destroy(stack *s);
int empty(stack *s);
int full(stack *s);
int push(stack *s, T item);
T pop(stack *s);
unsigned size(stack *s);
T top(stack *s);

struct node {
	T data;
	int nfilhos;
	struct node *filhos[GRAU_MAX];
	struct node *pai; // opcional
};


void pre_order( struct node *p ) {
	
	stack s;
	create(&s, MAX);
	
	push(&s, p);
	
	while( !empty(&s) ) {
		
		struct node * e = pop(&s);
		
		process(e); //printf("%d ", e->data);
		
		for(int i=0; i<e->nfilhos; i++)
			push(&s, e->filhos[i] );		
	}
	
	return;
}

void pos_order( struct node *p ) {
	
	stack s;
	create(&s, MAX);
	
	push(&s, p);
	
	while( !empty(&s) ) {
		
		struct node * e = top(&s);
		
		if( foi_visitado(e) ) {
			pop(&s);
			process(e); //printf("%d ", e->data);
		} else {
			visitado(e);
			for(int i=0; i<e->nfilhos; i++)
				push(&s, e->filhos[i] );		
		}
	}
	
	return;
}

void em_nivel( struct node *p ) {
	
	Queue q;
	create(&q, MAX);
	
	push(&q, p);
	
	while( !empty(&q) ) {
		
		struct node * e = get(&q);
		
		process(e); //printf("%d ", e->data);
		
		for(int i=0; i<e->nfilhos; i++)
			put(&q, e->filhos[i] );		
	}
	
	return;
}


int pos_order_exercicio( struct node *p ) {
	
	int acumulador = 4;
    for(int i = 0; i < p->nfilhos; i++) {
		acumulador += 4;
		if( eh_arquivo(p->filhos[i]) )
			acumulador += size(p->filhos[i]);
		else
			acumulador += pos_order_exercicio(p->filhos[i]);
    }

    return acumulador;
}




int main() {
	
}
