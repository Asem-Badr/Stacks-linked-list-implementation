#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main()
{
    int x ;
    Stack s ;
    createStack(&s);
    push(&s,20);
    push(&s,10);
    pop(&s,&x);
    push(&s,30);
    traverseStack(&s,&display);
    printf("x = %d\n", x);
    printf("the stack size is : %d",stackSize(&s));
    return 0;
}
