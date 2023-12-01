#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int ** Sudoko_Generate ( void );
int check_input(int i ,int j ,int a);
int sudoko_check(int arr[][9],int**p,int i,int j,int num);


int main()
{
    system("COLOR 07");


    int**p;
    int i,j,num,a,r;
    int count=0;
    p=Sudoko_Generate ( );

    int live[9][9]= {0};

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            live[i][j]=p[i][j];
        }
    }

    array_sudoko_2d_print(live,9,9);

    printf("\nPlease Enter The location i,j (1 to 9) (1 to 9) and the number (1 to 9)\n");
    while(1)
    {

        scanf("%d",&i);

        scanf("%d",&j);

        scanf("%d",&num);

        r=check_input(i,j,num);

        if(r==1)
        {
            i=i-1;
            j=j-1;
            a=sudoko_check(live,Sudoko_Generate( ),i,j,num);
            if(a==-1)
            {
                printf("\n               Wrong Response,\033[0;31mThis number Can't be edited\033[0m\n");
                array_sudoko_2d_print_2(live,Sudoko_Generate( ),9,9);
                printf("\n\n       Please Enter The location i,j and the number\n");
            }
            else if (a==0)
            {
                printf("\n                Wrong Response,This Number is \033[0;35mRepeated\033[0m\n");
                array_sudoko_2d_print_2(live,Sudoko_Generate( ),9,9);
                printf("\n\n       Please Enter The location i,j and the number\n");
            }

            else if (a==1)
            {
                live[i][j]=num;
                printf("\n               Your Number is \033[0;34mSetted\033[0m\n");
                array_sudoko_2d_print_2(live,Sudoko_Generate( ),9,9);
                count++;
                printf("\n\n      Please Enter The location i,j and the number\n");
            }

            if(count==47)
            {
                printf("\033[0;32mWell Played,GG\033[0m");
                break;
            }

        }
        else
        {
            printf("\n      \033[0;31mWrong input\033[0m,Please Enter The location i,j (1 to 9) (1 to 9) and the number (1 to 9)\n");
        }

    }

    return 0;
}





int ** Sudoko_Generate ( void )
{

int i,j;
int **s;

s=(int**)malloc(9*sizeof(int*));
for(i=0;i<9;i++)
{
    s[i]=(int*)malloc(9*sizeof(int));
}


    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
             if(i==0&&j==0)
            {
                s[i][j]=7;
            }
            else if(i==0&&j==2)
            {
                s[i][j]=9;
            }
            else if(i==0&&j==6)
            {
                s[i][j]=4;
            }
            else if(i==1&&j==0)
            {
                s[i][j]=5;
            }
            else if(i==1&&j==4)
            {
                s[i][j]=2;
            }
            else if(i==1&&j==5)
            {
                s[i][j]=9;
            }
            else  if(i==1&&j==6)
            {
                s[i][j]=1;
            }
            else  if(i==1&&j==8)
            {
                s[i][j]=7;
            }
            else if(i==2&&j==2)
            {
                s[i][j]=6;
            }
            else  if(i==2&&j==3)
            {
                s[i][j]=1;
            }
            else   if(i==2&&j==6)
            {
                s[i][j]=5;
            }
            else   if(i==3&&j==1)
            {
                s[i][j]=6;
            }
            else   if(i==3&&j==3)
            {
                s[i][j]=8;
            }
            else  if(i==3&&j==4)
            {
                s[i][j]=1;
            }
            else  if(i==3&&j==5)
            {
                s[i][j]=5;
            }
            else   if(i==3&&j==7)
            {
                s[i][j]=7;
            }
            else  if(i==4&&j==0)
            {
                s[i][j]=9;
            }
            else  if(i==4&&j==4)
            {
                s[i][j]=3;
            }
            else  if(i==4&&j==5)
            {
                s[i][j]=6;
            }
            else   if(i==4&&j==7)
            {
                s[i][j]=1;
            }
            else  if(i==4&&j==8)
            {
                s[i][j]=4;
            }

            else if(i==5&&j==1)
            {
                s[i][j]=8;
            }
            else if(i==5&&j==2)
            {
                s[i][j]=7;
            }
            else  if(i==5&&j==7)
            {
                s[i][j]=3;
            }
            else  if(i==6&&j==0)
            {
                s[i][j]=6;
            }
            else  if(i==6&&j==1)
            {
                s[i][j]=7;
            }
            else if(i==6&&j==4)
            {
                s[i][j]=8;
            }
            else  if(i==6&&j==8)
            {
                s[i][j]=9;
            }
            else if(i==7&&j==0)
            {
                s[i][j]=8;
            }
            else if(i==7&&j==5)
            {
                s[i][j]=7;
            }
            else  if(i==7&&j==6)
            {
                s[i][j]=3;
            }
            else if(i==8&&j==1)
            {
                s[i][j]=5;
            }
            else if(i==8&&j==2)
            {
                s[i][j]=1;
            }
            else if(i==8&&j==3)
            {
                s[i][j]=2;
            }
            else if(i==8&&j==5)
            {
                s[i][j]=3;
            }
            else  if(i==8&&j==6)
            {
                s[i][j]=7;
            }
            else
            {
                s[i][j]=' ';
            }
        }
    }
    return s;
}
void array_sudoko_2d_print(int p[][9],int row,int col)
{
    char i,j;


    for(i=0; i<9; i++)
    {
           if(i==0)
         {
              printf("                                ___________________________________________________________________________");
printf("\n");
         }
        printf("\n");
        printf("                                ");
        for(j=0; j<9; j++)
        {
            if(j==2||j==5||j==8)
            {
                if(p[i][j]>=0&&p[i][j]<=9)
                {
                     printf(" [ %d ]  |  ",p[i][j]);
                }
              else
              {
                      printf(" [ %c ]  |  ",p[i][j]);
              }


            }
            else if(j==0)
            {
                if(p[i][j]>=0&&p[i][j]<=9)
                {
                     printf("|  [ %d ] ",p[i][j]);
                }
             else
              {
                      printf("|  [ %c ] ",p[i][j]);
              }
            }
             else
            {
                  if(p[i][j]>=0&&p[i][j]<=9)
                {
                    printf(" [ %d ] ",p[i][j]);
                }
             else
              {
                      printf(" [ %c ] ",p[i][j]);
              }

            }



            }

        printf("\n");
         printf("             ");
         if(i==2||i==5||i==8)
         {
              printf("                   ___________________________________________________________________________");
              printf("\n");
         }


    }

}

int sudoko_check(int arr[][9],int**p,int i,int j,int num)
{
    int k;

    if(p[i][j]==' ')
    {
        for(k=0;k<9;k++)
        {
            if(arr[i][k]==num||arr[k][j]==num)
            {
                return 0;
            }
        }

    }
    else
    {
        return -1;
    }
return 1;
}

int check_input(int i ,int j ,int a)
{
    if((i>=1&&i<=9)&&(j>=1&&j<=9)&&(a>=1&&a<=9))
    {
        return 1 ;
    }
    else
    {
        return 0;
    }
}

void array_sudoko_2d_print_2(int p[][9],int**p2,int row,int col)
{
    char i,j;


    for(i=0; i<9; i++)
    {
           if(i==0)
         {
              printf("                                ___________________________________________________________________________");
printf("\n");
         }
        printf("\n");
        printf("                                ");
        for(j=0; j<9; j++)
        {
            if(j==2||j==5||j==8)
            {
                if(p[i][j]>=0&&p[i][j]<=9)
                {
                    if(p[i][j]==p2[i][j])
                    {
                        printf(" [ %d ]  |  ",p[i][j]);
                    }
                    else
                    {
                        printf(" [\033[0;34m %d \033[0m]  |  ",p[i][j]);
                    }

                }
              else
              {
                      printf(" [ %c ]  |  ",p[i][j]);
              }


            }
            else if(j==0)
            {
                if(p[i][j]>=0&&p[i][j]<=9)
                {
                     if(p[i][j]==p2[i][j])
                    {
                        printf("|  [ %d ] ",p[i][j]);
                    }
                    else
                    {
                        printf("|  [\033[0;34m %d \033[0m] ",p[i][j]);

                    }

                }
             else
              {
                      printf("|  [ %c ] ",p[i][j]);
              }
            }
             else
            {
                  if(p[i][j]>=0&&p[i][j]<=9)
                {
                     if(p[i][j]==p2[i][j])
                    {
                        printf(" [ %d ] ",p[i][j]);
                    }
                    else
                    {
                        printf(" [\033[0;34m %d \033[0m] ",p[i][j]);
                    }

                }
             else
              {
                      printf(" [ %c ] ",p[i][j]);
              }

            }



            }

        printf("\n");
         printf("             ");
         if(i==2||i==5||i==8)
         {
              printf("                   ___________________________________________________________________________");
              printf("\n");
         }


    }

}
