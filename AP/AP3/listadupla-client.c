#include <stdio.h>
#include <stdlib.h>

#include "listadupla.h"



int main() {

	Lista letras;

	inicializa(&letras);
	int i = vazia(&letras);

	insereInicio(&letras, 'A');
	insereFim(&letras, 'C');

	char c;

	//imprimindo todos os termos
	for(Iterador it = inicio(&letras);
	 !acabou(&it); proximo(&it) ) {
		elemento(&it,&c);
		printf("%c\n", c);
	}

	//buscando o elemento C na lista e imprimindo-o
	printf("------\n");
	Iterador ini = inicio(&letras);
	Iterador it = buscaProximo(&ini, 'C');
	insereAntes(&it, 'B');
	insereDepois(&it, 'D');
	while( !acabou(&it) ) {
		elemento(&it,&c);
		printf("%c\n", c);
		proximo(&it);
		it = buscaProximo(&it, 'C');
	}

	//imprimindo novamente todos os termos apos inserir B e D, antes e depois de C respectivamente, porem começando pelo final
	printf("------\n");
	for(Iterador it = fim(&letras);
	 !acabou(&it); anterior(&it) ) {
		elemento(&it,&c);
		printf("%c\n", c);
	}

	char a;
	it = buscaPrimeiro(&letras, a);
	removeInicio(&letras, &a);
	printf("Item removido %c\n", a);
	it = buscaUltimo(&letras, a);
	removeFim(&letras, &a);
	printf("Item removido %c\n", a);

	it = fim(&letras);
	remover(&it, &a);
	printf("%c\n", it.p->item);

	it = inicio(&letras);
	printf("O novo primeiro termo da lista é: %c\n", it.l->ini->item);
	it = fim(&letras);
	printf("O novo último termo da lista é: %c\n", it.l->fim->item);

	//imprimindo todos os termos apos imprimir o primeiro e o ultimo termo da lista
	printf("------\n");
	for(Iterador it = inicio(&letras);
	 !acabou(&it); proximo(&it) ) {
		elemento(&it,&c);
		printf("%c\n", c);
	}
	i = quantidade(&letras);

	return 0;
}
