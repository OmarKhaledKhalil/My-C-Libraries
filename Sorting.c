//Advantages of Bubble Sorting     : - We Can Detect Early That the Array is already order.
//DisAdvantages of Bubble Sorting  : - The Execution Complexity is O(n2) in the Worst Case.
void array_BubbleSorting (int*arr , int size)
{
    int i , j , temp ;
    int flag ;

    for( i = 0 ; i < size ; i++ )
    {
        flag = 1 ;

        for( j = 0 ; j < size-1 ; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp     = arr[j]   ;
                arr[j]   = arr[j+1] ;
                arr[j+1] = temp     ;
                flag     =  0       ;
            }
        }

        if ( flag == 1 )
        {
            break ;
        }
    }

}


//Advantages of Bubble Sorting     : - Less Swap Operations , Better in Big Data Elemets  .
//DisAdvantages of Bubble Sorting  : - The Execution Complexity is O(n2) in the Worst Case , and we can't know the array is sorted early.
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
           int temp = arr[max] ;
           arr[max] = arr[last];
           arr[last]= temp     ;
        }

        last--;
    }

}





