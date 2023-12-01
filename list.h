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

pnode create_node(int data);
void list_add_node_at_end(ppnode head ,int data);
void list_print(pnode head);
list_status list_remove_data(ppnode head,int oldData);
list_status list_edit_data(pnode head , int oldData,int newData);
void list_addNode_tofirst(ppnode head,int data);
list_status list_removeData(ppnode head,int oldData);
list_status list_insert_data_after_data(ppnode head,int oldData,int newData);
list_status list_insert_data_before_data(ppnode head,int oldData,int newData);
