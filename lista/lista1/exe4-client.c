#include <stdio.h>
#include <stdlib.h>
#include "exe4.h"

int main(){

    No* teste;
    Lista letras;
    char c;
    Lista testando;
    Lista test;

    inicializa(&letras);
    inicializa(&test);
    int i = vazia(&letras);


    insereInicio(&letras, 'A');
    insereFim(&letras, 'C');

    No* meio = meio_da_lista(&letras);
    printf("meio %c\n", meio->item);
    
    insereInicio(&test, 'Z');
    insereFim(&test, 'Y');

    int j = 0;
    j = nElementosrecur(letras.ini);
    printf("%d\n", j);
    j = nElementosite(letras.ini);
    printf("%d\n", j);
    //teste = menorElementoite(letras.ini);
    //printf("%c\n", teste->item);
    teste = menorElementorecur(letras.ini);
    printf("%c\n", teste->item);
    // remove_recur(&letras.ini, 'A');
    printf("------\n");
    for(Iterador it = inicio(&letras);
	 !acabou(&it); proximo(&it) ) {
		elemento(&it,&c);
		printf("%c\n", c);
	}


    printf("------\n");
    for(Iterador it = inicio(&test);
     !acabou(&it); proximo(&it) ) {
        elemento(&it,&c);
        printf("%c\n", c);
    }
    testando.ini = intercalaListas(&letras.ini, &test.ini);

    printf("------\n");
    for(Iterador it = inicio(&testando);
     !acabou(&it); proximo(&it) ) {
        elemento(&it,&c);
        printf("%c\n", c);
    }


    return 0;
}
