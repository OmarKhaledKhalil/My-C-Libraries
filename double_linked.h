#define NULLPTR ((void*)0)
typedef enum
{
    LAST_TO_FIRST,
    FIRST_TO_LAST
}printf_t;

typedef struct dnode
{
 int data;
 struct dnode *next;
 struct dnode *prev;
}dnode_t;

typedef struct
{
     dnode_t *head;
     dnode_t *tail;
     int size;
} doublelist_t;

typedef doublelist_t*  LIST;
typedef dnode_t* PDNODE;

LIST Dlist_create(void);
void Dlist_addtofirst(LIST l,int data);
void Dlist_addtolast(LIST l,int data);
PDNODE create_Dnode(int data);
void Dlist_print(LIST l,printf_t direction);
