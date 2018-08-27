#include <stdio.h>
#include <stdlib.h>
#include "pilhalista.h"

void destroy(head *cabeca)
{
    if (empty(*cabeca) == 1)
    {
        return;
    }
    stack *auxremove = cabeca->top;
    stack *aux;
    int i = 0;

    while (i < cabeca->contador)
    {
        pop(cabeca);
        i++;
    }
}

int empty(head cabeca)
{

    if (cabeca.contador == 0)
    {
        return 1;
    }
    return 0;
}

int full(head cabeca)
{
    if (cabeca.contador == 100)
    {
        return 1;
    }
    return 0;
}

int push(head *cabeca)
{
    if (full(*cabeca) == 1)
    {
        return 0;
    }
    stack *s = (stack *)malloc(sizeof(stack));

    if (empty(*cabeca) == 1)
    {
        s->next = NULL;
        cabeca->top = s;
        cabeca->contador = 1;
        s->num = 1;
    }
    else
    {
        stack *aux = cabeca->top;
        s->next = aux;
        cabeca->top = s;
        cabeca->contador++;
        s->num = 1;
        // aux->next = NULL
    }
}

void pop(head *cabeca)
{

    if (empty(*cabeca) == 1)
    {
        return;
    }
    else
    {
        stack *auxremove = cabeca->top;
        stack *aux = auxremove->next;
        free(auxremove);
        cabeca->top = aux;
        cabeca->contador--;
    }
}

int size(head cabeca)
{

    return cabeca.contador;
}

int top(head cabeca)
{

    return cabeca.top->num;
}
