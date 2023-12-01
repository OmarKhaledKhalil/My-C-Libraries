#include <stdio.h>
#include <stdlib.h>

 void string_void_print(char*str)
{
    int i;

    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}

 int string_int_len(char*str)
{
    int i;
    for(i=0; str[i]; i++);
    return i;

}


 void string_void_reverse(char*str)
{
    int j,i,len=string_int_len(str);
    j=len-1;
    char temp;
    for(i=0; i<=j; i++,j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }

}


 int string_int_compare(char *s1,char*s2)
{
    int i;

    for(i=0; s1[i]||s2[i]; i++)
    {
        if(s1[i]<s2[i])
        {
            return 1;
        }
    }
    return 0;
}


 void string_void_scan(char*str,int maxSize)
{
    int i=0;
    fflush(stdin);
    scanf("%c",&str[i]);
    for(; str[i]!='\n'&&i<maxSize-1;)
    {
        i++;
        scanf("%c",&str[i]);
    }
    str[i]=0;

}


