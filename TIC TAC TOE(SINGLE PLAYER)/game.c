#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include"conditions.h"

int b[3][3];

void name(void)
{
    printf("\n\t\t\t\t\t====================TIC TAC TOE=======================\n");
}
int cmenu(void)
{
    name();
    int n,k;
    do
    {
        printf("\n\t\t\t1-BLUE\n");
        printf("\n\t\t\t2-GREEN\n");
        printf("\n\t\t\t3-RED\n");
        printf("\n\t\t\t4-YELLOW\n");
        printf("\n\t\t\t5-WHITE\n");
        printf("\n\t\t\tSELECT COLOR     ===========>>>>>>>>>>       ");
        scanf("%d",&n);
        k=(n==1||n==2||n==3||n==4||n==5);
    }while(k==0);
    return n;
}
void color(void)
{

    int n=cmenu();
    if(n==1)
        system("COLOR 1");
    else if(n==2)
        system("COLOR 2");
    else if(n==3)
        system("COLOR 4");
    else if(n==4)
        system("COLOR E");
    else
        system("COLOR F");
}


int dice()
{
    int num;
    srand(time(NULL));
    num=rand()%9;
    return num;
}

void boardv(int *p)
{

    int i,n=0,j=0;
    for(i=0;i<10;i++)
    {
        *(p+i)=n;
        n++;
    }
    p=b;
    for(i=1;i<=9;i++)
    {
        *p=i;
        p++;
    }
}

void print(int *p)
{
    //name();
    int i,j,k;
    for(i=0;i<3;i++)
    {
        printf("\t\t");
        for(j=0;j<3;j++)
        {
            printf("\t\t");
            if(*p=='X')
                printf("\tX");
            else if(*p=='O')
                printf("\tO");
            else
                printf("\t%d",b[i][j]);
            p++;
        }
        printf("\n\n");
    }
}


int chk(int n,int *p)
{
    int ck=*(p+n);
    if(ck=='X')
    {
        return 1;
    }
    else if(ck=='O')
    {
        return 1;
    }
    else
        return 0;
}


int user(int *p)
{
    name();
    int n,ck,nu;
    do
    {
        print(p);
        printf("\n\t\t\tENTER POSITION FOR 'X'            ");
        scanf("%d",&n);
        n--;
        int ck;
        ck=chk(n,p);
        //printf("\nck=%d",ck);
        if(ck==0)
        {
            *(p+n)='X';
            break;
        }
        else
        {
            printf("\n\t\t\t---------INVALID POSITION---------\n");
            nu=user(p);
        }
    }while(ck==1);
    system("cls");
}

int comp(int *p)
{
    name();
    int n,ck;
    do
    {
        n=dice();
        ck=chk(n,p);
        //printf("\nck=%d",ck);
        if(ck==0)
        {
            print(p);
            *(p+n)='O';
        }
    }while(ck==1);
    //printf("\n\t\t\tCOMPUTER PLAYS  ========    %d  \n",n+1);
    system("cls");
}




int main()
{
    name();
        //system("COLOR 1");
    int board[3][3],*p;
    p=board;
    boardv(p);
    //print(p);
    int opt;
    printf("\n\t\t\tSELECT DIFFICULTY\t\t\n");
    printf("\n\t\t\t1-PLAY\n");
    printf("\n\t\t\t2-CHANGE TERMINAL COLOR\n");
    printf("\n\t\t\tSELECT OPTION      ===========>>>>>>>>>         ");
    scanf("%d",&opt);
    system("cls");
    switch(opt)
    {
        case 1:
            system("cls");
            goto easy;
            break;
        case 2:
            color();
            system("cls");
            main();
        default:
            printf("\n\tINVALID MENU OPTION\n");
            main();
    }
    int nu,nc,ck,win,ex;
    easy:
        do
        {
            nu=user(p);
            win=winck(p);
            if(win==1)
            {
                name();
                printf("\n\t\t\t\t\t-------------------------");
                printf("\n\t\t\t\t\t|\tUSER WINS\t|");
                printf("\n\t\t\t\t\t-------------------------");
                break;
            }
            nc=comp(p);
            win=winck(p);
            if(win==2)
            {
                name();
                printf("\n\t\t\t\t\t-------------------------");
                printf("\n\t\t\t\t\t|\tCOMP WINS\t|");
                printf("\n\t\t\t\t\t-------------------------");
                break;
            }
            //print(p);
            ex=win==1||win==2;
        }while(ex==0);
}
