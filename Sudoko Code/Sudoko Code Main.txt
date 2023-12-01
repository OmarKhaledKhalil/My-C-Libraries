#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

