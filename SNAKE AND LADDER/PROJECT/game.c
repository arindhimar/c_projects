#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i=0,j,k;
    int board[100];
    int pos=0;
    int dice;
    int lad,snk;
        do
        {
            printf("\nENTER 1 TO ROLL DICE OR ANY OTHER INPUT TO QUIT\n");
            scanf("%d",&i);
            if(i!=1)
                break;
            do
            {
                srand(time(NULL));
                dice=rand()%7;
            }while(dice==0);
            /*pos=99;*/
            printf("DICE=%d",dice);
            if(pos==0)
            {
                if(dice==6)
                {
                    pos=pos+dice;
                }
                else
                    pos=pos;
            }
            else
            {
                pos=pos+dice;
            }
            switch(pos)
            {
            case 19:
                pos=pos+47;
                break;
            case 25:
                pos=pos-19;
                break;
            case 32:
                pos=pos+21;
                break;
            case 46:
                pos=pos-32;
                break;
            case 67:
                pos=pos+32;
                break;
            case 73:
                pos=92;
                break;
            case 88:
                pos=76;
                break;
            default:
                break;
            }
            printf("\nYOUR POSITION ON BOARD=%d",pos);
        }while(pos<=100);

    printf("\nTHANK YOU");
    return 0;
}
