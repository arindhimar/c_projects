#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i,j,k=0,rn;
    int flag;
    int r,c,ch,w;
    char O='O';
    int b[3][3];
    /*int num;
    srand(time(NULL));
    num=rand()%2;
    printf("%d",num);*/
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            b[i][j]=83;
        }
    }
    /*for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t%d",b[i][j]);
        }
        printf("\n");
    }*/
    printf("\nUSER 1 HAS X\n");
    printf("\nUSER 2 HAS O\n");
    int u1[1][1];
    int u2[1][1];
    for(rn=0;rn<9;rn++)
    {
        do
        {
            printf("\nUSER 1 ENTER POSITION FOR X IN ROW AND COL\n");
            scanf("%d %d",&r,&c);
            if(b[r][c]==83)
            {
                b[r][c]=88;
                ch=1;
            }
            else
                {
                    printf("\nINVALID INPUT\n");
                    ch=0;
                }
        }while(ch==0);
        do
        {
            printf("\nUSER 2 ENTER POSITION FOR O IN ROW AND COL\n");
            scanf("%d %d",&r,&c);
            if(b[r][c]==83)
            {
                b[r][c]=79;
                ch=1;
            }
            else
                {
                    printf("\nINVALID INPUT\n");
                    ch=0;
                }
        }while(ch==0);
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("\t%c",b[i][j]);
            }
            printf("\n");
        }
        int rr,cc;
        for(rr=0;rr<2;rr++)
        {
           // printf("loop1");
            k=b[rr][0]==88&&b[rr][1]==88&&b[rr][2]==88;
        if(k==1)
            {
              //  printf("true %d",rr);
                printf("\nUSER 1 WINS\n");
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
         for(cc=0;cc<2;cc++)
        {
          //  printf("loop1");
            k=b[0][cc]==88&&b[1][cc]==88&&b[2][cc]==88;
            if(k==1)
            {
               // printf("true 1");
                printf("\nUSER 1 WINS\n");
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
        for(rr=0;rr<2;rr++)
        {
           // printf("loop1");
            k=b[rr][0]==79&&b[rr][1]==79&&b[rr][2]==79;
            if(k==1)
            {
                //printf("true 1");
                printf("\nUSER 2 WINS\n");
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
         for(cc=0;cc<2;cc++)
        {
          //  printf("loop1");
            k=b[0][cc]==79&&b[1][cc]==79&&b[2][cc]==79;
            if(k==1)
            {
               // printf("true 1");
                printf("\nUSER 2 WINS\n");
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
        k=b[0][0]==88&&b[1][1]==88&&b[2][2]==88;
        if(k==1)
        {
            printf("\nPLAYER 1 WINS\n");
            break;
        }
        k=b[0][2]==88&&b[1][1]==88&&b[2][0]==88;
        if(k==1)
        {
            printf("\nPLAYER 1 WINS\n");
            break;
        }
        k=b[0][0]==79&&b[1][1]==79&&b[2][2]==79;
        if(k==1)
        {
            printf("\nPLAYER 2 WINS\n");
            break;
        }
        k=b[0][2]==79&&b[1][1]==79&&b[2][0]==79;
        if(k==1)
        {
            printf("\nPLAYER 2 WINS\n");
            break;
        }
    }
    return 0;
}
