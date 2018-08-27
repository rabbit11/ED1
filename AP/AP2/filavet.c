#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "filavet.h"

void create(stack* s, int max_size){
    s->num = (int*)malloc(sizeof(int) * max_size);
    s->topo = 0;
    s->fim = 0;

}

void destroy(stack* s) {
    free(s->num);
}
int empty(stack* s) {
    if (s->fim == 0)
    {
        return 1;
    }
    return 0;
}
int full(stack* s) {
    if (s->fim >= 10)
    {
        return 1;
    }
    return 0;
}
int push(stack* s) {
    if(full(s) == 1){
        if(s->num[s->topo] != 1){
            s->num[s->fim] = 1;
            s->fim++;
            return 1;
        }else{
            return 0;
        }
    }
    if(empty(s) == 1){
        s->num[0] = 1;
        s->fim = 1;
        return 1;
    }else{
        s->num[s->fim] = 1;
        s->fim++;
        return 1;
    }
}
void pop(stack* s) {
    if (empty(s) == 1)
    {
        return;
    }else{
        s->num[s->topo] = 0;
        s->topo++;
        s->fim--;
    }
}
int size(stack* s) {
    int aux = s->fim;

    return aux--;
}
int top(stack* s) {
    return s->fim;
}
