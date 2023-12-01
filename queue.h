typedef enum
{
    QUEUE_EMPTY,
    QUEUE_FULL,
    QUEUE_OK

}queue_status;

typedef struct
{
    int *DataArr;
    int size;
    int in;
    int out;
}queue_t;

typedef queue_t* QUEUE;

queue_status inq (QUEUE q,int data);
queue_status outq (QUEUE q,int *data);
QUEUE queue_create(int size);
int queue_delete(QUEUE q);
