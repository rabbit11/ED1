#ifndef PILHAVET_H_
#define PILHAVET_H_

typedef struct _stack
{
    int topo;
    int *num;
} stack;

void create(stack*s, int max_size);

void destroy(stack* s);

int empty(stack* s);

int full(stack* s);

int push(stack* s);

void pop(stack* s);

int size(stack* s);

int top(stack* s);

#endif
