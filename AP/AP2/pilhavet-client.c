#include "pilhavet.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    int max_size = 100;
    stack s;

    create(&s, max_size);
    push(&s);
    printf("%d\n", size(&s));
    pop(&s);
    printf("%d\n", size(&s));

    return 0;
}
