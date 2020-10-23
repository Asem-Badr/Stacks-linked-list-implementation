
/** 3.2 E2 **/



#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define INT_MAX -99999
int firstElement (Stack*s);
int thirdElement (Stack*s);
int buttomElement (Stack*s);
void deleteX(Stack*s ,int x);
int main()
{
    int first,third ;
    Stack s ;
    createStack(&s);
    push(&s,20);
    push(&s,10);
    push(&s,30);
    first = firstElement(&s);
    third = thirdElement(&s);
    traverseStack(&s,&display);
    printf("first = %d\n", first);
    printf("third = %d\n", third);
    printf("buttom = %d\n", buttomElement (&s));
    printf("the stack size is : %d\n",stackSize(&s));
    deleteX(&s ,10);
    traverseStack(&s,&display);

    return 0;
}
int firstElement (Stack*s)
{
    if (stackEmpty(s))
    {
        return INT_MAX;
    }
    else
    {
    int x ;
    pop(s,&x);
    push(s,x);
    return x;
    }
}
int thirdElement (Stack*s)
{
    if(stackSize(s)>=3)
    {
        int arr[3];
        int i;
        for (i=0 ;i<3 ;i++)
        {
            pop(s,&arr[i]);
        }
        for (i=2 ;i>=0 ;i--)
        {
            push(s,arr[i]);
        }
        return arr[2] ;
    }
    else
    {
        return INT_MAX;
    }
}
int buttomElement (Stack*s)
{
    if(!stackEmpty(s))
    {
    int i;
    int x = stackSize(s);
    Stack s2 ;
    createStack(&s2);
    for(i=0; i<x ;i++)
    {
        int myelement;
        pop(s,&myelement);
        push(&s2,myelement);
    }
    int first = firstElement(&s2);
    for(i=0; i<x ;i++)
    {
        stack_elements myelement;
        pop(&s2,&myelement);
        push(s,myelement);
    }
    return first;
    }
    else return INT_MAX;
}
void deleteX(Stack*s ,int x)
{
    int temparr[stackSize(s)],counter=0,i;
    while(stackSize(s))
    {
        stack_elements myelement;
        pop(s,&myelement);
        if(myelement!= x)
        {
        temparr[counter]=myelement;
        counter ++;
        }
    }
    for(i=counter-1 ;i>=0 ;i--)
    {
        push(s,temparr[i]);
    }
}

