
void array_BubbleSorting(int*arr,int size)
{
    int i,temp,j,c=0,sortingFlag;
    for(j=0; j<size; j++)
    {
        sortingFlag=1;
        for(i=0; i<size-1-j; i++)
        {
            c++;
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                sortingFlag=0;
            }
        }
        if(sortingFlag==1)
        {
            break;
        }
    }
    printf("s=%d  c=%d\n\n",size,c);

}


void array_SelectionSorting(int*arr,int size)
{
    int i,j,max=0,last=size-1;
    for(j=0; j<size; j++)
    {
        max=0;
        for(i=0; i<=last; i++)
        {
            if(arr[i]>arr[max])
            {
                max=i;
            }
        }
        if(max!=last)
        {
           swap(&arr[max],&arr[last]);
        }

        last--;
    }

}

void array_CountingSorting(int*arr,int size)
{
    int i,j,count[10]={0},c=0;
    for(i=0;i<size;i++)
    {
        count[arr[i]]++;
        c++;
    }
    j=0;
    for(i=0;i<10;i++)
    {
        printf("%d  %d\n",i,count[i]);
    }
    for(i=0;i<10;i++)
    {
        while(count[i])
        {
            c++;
            arr[j]=i;
            j++;
            count[i]--;
        }
    }
     printf("s=%d  c=%d\n\n",size,c);
}
