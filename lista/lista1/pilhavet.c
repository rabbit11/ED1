#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "pilhavet.h"

void create(stack* s, int max_size){
    s->num = (char*)malloc(sizeof(char) * max_size);
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
int push(stack* s, char a) {
    if(full(s) == 1){
        return 0;
    }
    if(empty(s) == 1){
        s->num[0] = a;
        s->topo++;
        return 1;
    }else{
        s->num[s->topo] = a;
        s->topo++;
        return 1;
    }
}
char pop(stack* s) {
    if (empty(s) == 1)
    {
        return 0;
    }else{
        char a = s->num[--s->topo];
        s->num[s->topo] = 0;
        return a;
    }
}
int size(stack* s) {
    int aux = s->topo;
    return --aux;
}
char top(stack* s) {
    char a = --s->topo;
    s->topo++;
    return a;
}
