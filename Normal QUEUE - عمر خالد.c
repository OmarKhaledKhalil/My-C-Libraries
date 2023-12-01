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


queue_status inq (QUEUE q,int data)
{
    queue_status status;
    if(q->in==q->size&&(q->out<q->in))
    {
        status=QUEUE_FULL;
    }
    else if (((q->in)==(q->out)))
    {
        q->in=0;
        q->out=0;
        q->DataArr[q->in]=data;
        q->in++;
        status=QUEUE_OK;

    }
    else
    {
        q->DataArr[q->in]=data;
        q->in++;
        status=QUEUE_OK;
    }


    return status;
}

queue_status outq (QUEUE q,int *data)
{
    queue_status status;
    if((q->out)==(q->in))
    {
        status=QUEUE_EMPTY;
    }
    else
    {
        *data=q->DataArr[q->out];
        q->out++;
        status=QUEUE_OK;
    }

    return status;
}

QUEUE queue_create(int size)
{
    QUEUE q;
    q=malloc(sizeof(queue_t));
    q->DataArr=malloc(size*sizeof(int));
    q->size=size;
    q->in=0;
    q->out=0;
    return q;
}

int queue_delete(QUEUE q)
{
    free(q->DataArr);
    free(q);
  return 0;
}
