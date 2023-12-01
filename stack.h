#define STACK_SIZE 5
typedef enum
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_OK

}stack_status;

typedef struct
{
    int *DataArr;
    int size;
    int sp;
}stack_t;

typedef stack_t* STACK;

stack_t * stack_create(int size);
stack_status push(STACK stack,int data);
stack_status pop(STACK stack,int *data);
