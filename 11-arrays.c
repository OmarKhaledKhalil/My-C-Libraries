void array_print(int*p,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
       printf("%d ",p[i]);
    }
    printf("\n===============================\n");
}

int array_findElement(int*arr,int size,int n)
{
    int i;
    for(i=0;i<size;i++)
    {
       if(arr[i]==n)
       {
           return i;
       }

    }
    return -1;
}

void array_reverse(int *arr,int size)
{

    int i=0,j=size-1,temp;
    for(i=0;i<=j;i++)
    {
       swap(&arr[i],arr+j);
        j--;
    }


}

int array_removePrime(int *arr,int size)
{
    int i,x,c=0;
    for(i=0;i<size;i++)
    {

        if(IsPrime(arr[i]))
        {
            arr[i]=0;
            c++;
        }
    }

return c;
}

int array_MaxMin(int *arr,int size,int*pmin)
{
    int i,max=arr[0];
    *pmin=arr[0];
    for(i=1;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<*pmin)
        {
            *pmin=arr[i];
        }

    }
    return max;

}

int IsPrime(int n)
{
    //  printf("test\n");
    int i;
    if(n<2)
    {
        return 0;
    }
    for(i=2; i<n; i=i+1)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

void print_binary(unsigned int n)
{
    int i,flag=0;
    for(i=31; i>=0; i=i-1)
    {
        if((n>>i)&1)
        {
            printf("1");
            flag=1;
        }
        else
        {
            if(flag==1)
            {
                printf("0");
            }
        }
    }
    printf("\n");
}
