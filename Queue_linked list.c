#define NULLPTR ((void*)0)
typedef enum
{
    OK,
    EMPTY_LIST,
    NOT_FOUND
}list_status;

typedef struct node
{
    int data;
    struct node* next;
}node_t;

typedef node_t* pnode;
typedef node_t** ppnode;
typedef node_t node;


//(1) main queue functions



pnode queue_create_linked(void)
{
    return NULLPTR;
}



void inQ_linked(ppnode head,int data)
{
    list_add_node_at_end(head,data);
}


list_status outQ_linked(ppnode head, int*data_out)
{
    if(*head==NULLPTR)
    {
        return EMPTY_LIST;
    }
    else
    {
        *data_out=(*head)->data;
        return list_remove_data(head,*data_out);
    }
}





//(2)   Helper functions




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
