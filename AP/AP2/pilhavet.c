#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "pilhavet.h"

void create(stack* s, int max_size){
    s->num = (int*)malloc(sizeof(int) * max_size);
    s->topo = 0;
}

void destroy(stack* s) {
        free(s->num);
}
int empty(stack* s) {
    if (s->topo == 0)
    {
        return 1;
    }
    return 0;
}
int full(stack* s) {
    if (s->topo == 100)
    {
        return 1;
    }
    return 0;
}
int push(stack* s) {
    if(full(s) == 1){
        return 0;
    }
    if(empty(s) == 1){
        s->num[0] = 1;
        s->topo++;
        return 1;
    }else{
        s->num[s->topo] = 1;
        s->topo++;
        return 1;
    }
}
void pop(stack* s) {
    if (empty(s) == 1)
    {
        return;
    }else{
        s->num[--s->topo] = 0;
    }
}
int size(stack* s) {
    int aux = s->topo;
    return --aux;
}
int top(stack* s) {
    return s->topo;
}
