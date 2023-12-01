
void intToString(int n,char*str)
{
    int i=0,rem,flag=0;
    if(n==0)
    {
        str[0]='0';
        str[1]=0;
        return;
    }
    if(n<0)
    {
        n=n*(-1);
        flag=1;
    }

    while(n)
    {
        rem=n%10;
        rem=rem+'0';
        str[i]=rem;
        i++;
        n=n/10;
    }
    if(flag==1)
    {
        str[i]='-';
        i++;
    }
    str[i]=0;
    string_reverse(str);

}

int stringToInt(char*str,int*pnum)
{
    int i=0,n=0,flag=0;
    if(str[0]=='-')
    {
        flag=1;
        i=1;
    }
    for(; str[i]; i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        n=n*10+(str[i]-'0');
        else
            return 0;
    }
    if(flag==1)
    {
        n=n*(-1);
    }
    *pnum=n;
    return 1;
}



char add(unsigned char n1,unsigned char n2,unsigned char*presult)
{
    unsigned char r=(n1/2)+(n2/2);
    if(r>127)
    {
        return 0;
    }
    *presult=n1+n2;
    return 1;



}
unsigned char add_sat(unsigned char n1,unsigned char n2)
{
    unsigned char r=(n1/2)+(n2/2);
    if(r>127)
    {
        return 255;
    }

    return n1+n2;


}
