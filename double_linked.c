#include "double_linked.h"


LIST Dlist_create(void)
{
    LIST l=(doublelist_t*)malloc(sizeof(doublelist_t));
    l->head=0;
    l->tail=0;
    l->size=0;
    return l;
}

void Dlist_addtofirst(LIST l,int data)
{
    PDNODE newNode=create_Dnode(data);
    newNode->next=l->head;
    if(l->head!=0)
    {
        l->head->prev=newNode;
    }
    else
    {
        l->tail=newNode;
    }
    l->head=newNode;
    l->size++;
}
void Dlist_addtolast(LIST l,int data)
{
    PDNODE newNode=create_Dnode(data);
    newNode->prev=l->tail;
    if(l->tail!=0)
    {
        l->tail->next=newNode;
    }
    else
    {
        l->head=newNode;
    }
    l->tail=newNode;
    l->size++;
}

void Dlist_print(LIST l,printf_t direction)
{
    PDNODE current;

    if(direction==FIRST_TO_LAST)
    {
        current=l->head;
        int i;
        for(i=0;i<l->size;i++)
        {
            printf("%d ",current->data);
            current=current->next;
        }
    }
    else
    {
        current=l->tail;
        int i;
        for(i=0;i<l->size;i++)
        {
            printf("%d ",current->data);
            current=current->prev;
        }

    }

}

PDNODE create_Dnode(int data)
{
    PDNODE n=(PDNODE)malloc(sizeof(dnode_t));
    n->next=NULLPTR;
    n->prev=NULLPTR;
    n->data=data;
}
