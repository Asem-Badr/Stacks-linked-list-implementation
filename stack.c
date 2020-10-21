#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void createStack(Stack*ps)
{
    ps->top= NULL;
}
void push (Stack*ps,stack_elements element)
{
    //memory allocation
    Stack_node*pn = (Stack_node*)malloc(sizeof (Stack_node));
    pn->data = element ;
    pn->next = ps->top ;
    ps->top = pn ;
}
void pop(Stack*ps,stack_elements* element)
{
    Stack_node*pn ;
    *element = ps->top->data ;
    pn = ps->top;
    ps->top = ps->top->next ;
    free(pn);
}
void clearStack(Stack*ps)
{
    Stack_node*pn = ps->top ;
    Stack_node*pfr = ps->top ;
    while(pn)
    {
        pn = pn -> next ;
        free(pfr) ;
        pfr =pn ;
    }
    ps->top = NULL ;
}
int stackEmpty(Stack*ps)
{
    return ps->top == NULL ;
}
int	stackFull(Stack*ps)
{
    return 0 ;
}
void stackTop(stack_elements *element, Stack *ps)
{
    *element = ps->top->data ;
}
int	 stackSize(Stack *ps)
{
    int counter = 0 ;
    Stack_node* pn;
    pn = ps->top ;
    while(pn)
    {
        pn = pn->next ;
        counter++ ;
    }
    return counter ;
}
void display(stack_elements element)
{
    printf("%d\n",element);
}

void traverseStack (Stack* ps , void(*pf)(stack_elements))
{
     Stack_node*pn = ps->top ;
     while (pn)
     {
         (*pf)(pn->data) ;
         pn = pn->next ;
     }
}

