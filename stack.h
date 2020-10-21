#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef int stack_elements ;
typedef struct stack_node
{
    stack_elements data;
    struct stack_node* next;
}Stack_node;
typedef struct mystack
{
    Stack_node *top;
}Stack;



void createStack(Stack*ps);
void push (Stack*ps,stack_elements element);
void pop(Stack*ps,stack_elements* element);
void clearStack(Stack*ps);
int stackEmpty(Stack*ps);
int	stackFull(Stack*ps);
void stackTop(stack_elements *element, Stack *ps);
int	 stackSize(Stack *ps);
void display(stack_elements element);
void traverseStack (Stack* ps , void(*pf)(stack_elements));
#endif
