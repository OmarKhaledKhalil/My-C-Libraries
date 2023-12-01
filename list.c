#include "list.h"

pnode create_node(int data)
{
    pnode new_node =(pnode)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=NULLPTR;
    return new_node;
}
void list_add_node_at_end(ppnode head ,int data)
{
    if(*head==0)
    {
        *head=create_node(data);

    }
    else
    {


    pnode current=*head;

    while(current->next!=NULLPTR)
    {
        current=current->next;
    }
    current->next=create_node(data);
    }
}
list_status list_remove_data(ppnode head,int oldData)
{
    if(*head==0)
    {
        return EMPTY_LIST;
    }
    else if ((*head)->data==oldData)
    {
        pnode temp=(*head);
        *head=temp->next;
        free(temp);
    }

    else
    {
        pnode current=*head;

        while(current->next!=NULLPTR)
        {
            if(current->next->data==oldData)
            {
                pnode temp=current->next;
                current->next=current->next->next;
                free(temp);
                 return OK;
            }
            current=current->next;
        }
    }



    return NOT_FOUND;
}

void list_print(pnode head)
{
    while(head!=NULLPTR)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n===========================================\n");
}

list_status list_edit_data(pnode head , int oldData,int newData)
{
    if(head==NULLPTR)
    {
        return EMPTY_LIST;
    }
    while(head!=NULLPTR)
    {
        if(head->data==oldData)
        {
            head->data=newData;
            return OK;
        }
        head=head->next;
    }
    return NOT_FOUND;
}

void list_addNode_tofirst(ppnode head,int data)
{
   pnode newNode=create_node(data);
   newNode->next=*head;
   *head=newNode;
}
list_status list_removeData(ppnode head,int oldData)
{
    if(*head==NULLPTR)
    {
        return EMPTY_LIST;
    }
    else if ((*head)->data==oldData)
    {
        pnode temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    else
    {
        pnode current=*head;
        while(current->next!=NULLPTR)
        {
            if(current->next->data==oldData)
            {
                pnode temp=current->next;
                current->next=current->next->next;
                free(temp);
                return OK;
            }
            current=current->next;
        }
    }
        return NOT_FOUND;
}
list_status list_insert_data_after_data(ppnode head,int oldData,int newData)
{
    if(*head==NULLPTR)
    {
        *head=create_node(newData);
        return OK;
    }
    else
    {
        pnode current=*head;
        while(current!=NULLPTR)
        {
            if(current->data==oldData)
            {
                pnode temp=current->next;
                current->next=create_node(newData);
                current->next->next=temp;
                return OK;
            }
            current=current->next;

        }
    }
    return NOT_FOUND;
}

list_status list_insert_data_before_data(ppnode head,int oldData,int newData)
{
    if(*head==NULLPTR)
    {
        *head=create_node(newData);
        return OK;
    }
    else if ((*head)->data==oldData)
    {
        pnode temp=*head;
        *head=create_node(newData);
        (*head)->next=temp;
        return OK;
    }
    else
    {
        pnode current=*head;
        while(current->next!=NULLPTR)
        {
            if(current->next->data==oldData)
            {
                pnode temp=current->next;
                current->next=create_node(newData);
                current->next->next=temp;
                return OK;
            }
            current=current->next;

        }
    }
    return NOT_FOUND;
}
