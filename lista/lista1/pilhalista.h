#ifndef PILHALISTA_H_
#define PILHALISTA_H_

typedef struct _stack
{
    struct _stack *next;
    int num;

} stack;

typedef struct _head
{
    stack *top;
    int contador;
} head;

void create(head *cabeca);

void destroy(head *cabeca);

int empty(head cabeca);

int full(head cabeca);

int push(head *cabeca);

void pop(head *cabeca);

int size(head cabeca);

int top(head cabeca);

#endif