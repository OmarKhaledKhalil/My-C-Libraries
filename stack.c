#include "stack.h"


stack_status push(STACK stack,int data)
{
    stack_status s;
    if(stack->sp==stack->size)
     {
         s= STACK_FULL;

     }
    else
     {
         stack->DataArr[stack->sp]=data;
         stack->sp++;
         s= STACK_OK;
     }
     return s;
}

stack_status pop(STACK stack,int *data)
{
    stack_status s;
    if(stack->sp==0)
    {
        s=STACK_EMPTY;
    }
    else
    {
        stack->sp--;
        *data=stack->DataArr[stack->sp];
        s=STACK_OK;
    }
    return s;
}

STACK stack_create(int size)
{
    STACK s;
    s=malloc(sizeof(stack_t));
    s->DataArr=malloc(size*sizeof(int));
    s->size=size;
    s->sp=0;
    return s;
}

void stack_delete(STACK s)
{
    free(s->DataArr);
    free(s);
}
