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
    int ci;
    int co;
}queue_c_t;

typedef queue_c_t* QUEUE_c;

queue_status inq_c (QUEUE_c q,int data);
queue_status outq_c (QUEUE_c q,int *data);
QUEUE_c queue_c_create(int size);
int queue_c_delete(QUEUE_c q);



queue_status inq_c (QUEUE_c q,int data)
{
    queue_status status;

       if((q->in==q->out)&&(q->ci>q->co))
       {
           status=QUEUE_FULL;
       }
       else if (q->in==q->size)
       {
           q->in=0;
           q->ci++;
           if(q->out==0)
           {
               status=QUEUE_FULL;
           }
           else
           {
               q->DataArr[q->in]=data;
               q->in++;
               status=QUEUE_OK;
           }
       }
       else
       {
            q->DataArr[q->in]=data;
               q->in++;
               status=QUEUE_OK;
       }
    return status;
}

queue_status outq_c (QUEUE_c q,int *data)
{
    queue_status status;
    if((q->out==q->in)&&(q->co==q->ci))
    {
        status=QUEUE_EMPTY;
    }
    else if (q->out==q->size)
    {
        q->out=0;
        q->co++;
        if(q->in==0)
        {
            status=QUEUE_EMPTY;
        }
        else
        {
            *data=q->DataArr[q->out];
            q->out++;
            status=QUEUE_OK;
        }
    }
    else
    {
        *data=q->DataArr[q->out];
            q->out++;
            status=QUEUE_OK;
    }
    return status;
}

QUEUE_c queue_c_create(int size)
{
    QUEUE_c q;
    q=malloc(sizeof(queue_c_t));
    q->DataArr=malloc(size*sizeof(int));
    q->size=size;
    q->in=0;
    q->out=0;
    q-> ci=0;
    q-> co=0;
    return q;
}

int queue_c_delete(QUEUE_c q)
{
    free(q->DataArr);
    free(q);
  return 0;
}