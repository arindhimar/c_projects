#include<stdio.h>
#include<stdlib.h>




int main()
{
    int n=0,k;
    char ch[1];
    FILE *fp;
    fp=fopen("movies.txt","r");
    if(fp==NULL)
    {
        printf("\nNOt found!!");
    }

    for(k=getc(fp);k!=EOF;k=getc(fp))
    {
        if(k=='\n')
        {
            n=n+1;
        }
    }

    printf("\nT= %d",n);

    fclose(fp);
    return 0;
}