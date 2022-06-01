#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i,j,k;
    int comp;
    int user;
    int scu=0,scc=0;
    do
    {
        do
        {
            srand(time(NULL));
            comp=rand()%4;

        }while(comp==0);
        //printf("\nCOMP=%d\n",comp);
        printf("1(STONE) 2(PAPER) 3(SCISSOR)");
        scanf("%d",&user);
        if(user==1)
        {
            if(comp==1)
            {
                scc=scc;
                printf("\nUSER=STONE COMP=STONE\n");
                printf("\nNO POINT");
            }
            else
            {
                if(comp==2)
                {
                    scc++;
                    printf("\nUSER=STONE COMP=PAPER\n");
                    printf("\n1 POINT TO COMPUTER");
                }
                else
                {
                    if(comp==3)
                    {
                        scu++;
                        printf("\nUSER=STONE COMP=SCISSOR\n");
                        printf("\n1 POINT TO USER");
                    }
                }
            }
        }
        else
        {
            if(user==2)
            {
                if(comp==1)
                {
                    scu++;
                    printf("\nUSER=PAPER COMP=STONE\n");
                    printf("\n1 POINT TO USER");
                }
                else
                {
                    if(comp==2)
                    {
                        scc=scc;
                        printf("\nUSER=PAPER COMP=PAPER\n");
                        printf("\nNO POINT");

                    }
                    else
                    {
                        if(comp==3)
                        {
                            scc++;
                            printf("\nUSER=PAPER COMP=SCISSOR\n");
                            printf("\n1 POINT TO COMPUTER");
                        }
                    }
                }
            }
            else
            {
                if(user==3)
                {
                    if(comp==1)
                    {
                        scc++;
                         printf("\nUSER=SCISSOR COMP=STONE\n");
                         printf("\n1 POINT TO COMPUTER");
                    }
                    else
                    {
                        if(comp==2)
                        {
                            scu++;
                             printf("\nUSER=SCISSOR COMP=PAPER\n");
                             printf("\n1 POINT TO USER");
                        }
                        else
                        {
                            if(comp==3)
                            {
                                scc=scc;
                                printf("\nUSER=SCISSOR COMP=SCISSOR\n");
                                printf("\nNO POINT");
                            }
                        }
                    }
                }
            }
        }
        printf("\nUSER=%d COMP=%d\n",scu,scc);
        k=scu==3||scc==3;
       //printf("%d",k);
    }while(k!=1);
    if(scu==3)
        printf("\nUSER WINS");
    else
        printf("\nCOMP WINS");
    return 0;
}
