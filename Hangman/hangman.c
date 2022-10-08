#include <stdio.h>  
#include <stdlib.h>  
#include<string.h>
#include <time.h>

char guess[1],movie[100];
int l;

int ctlines()
{
    int n=0,ct=0;
    FILE *fp;
    fp=fopen("movies.txt","r");
    for(n=getc(fp);n!=EOF;n=getc(fp))
    {
        if(n=='\n')
        {
            ct=ct+1;
        }
    }  
    //printf("\nLines = %d",ct);
    return ct;
}

int genno(int ct)
{
    int n;
    time_t t1;
    srand(time(&t1));
    n=rand()%ct;
    return n;
}

void getmoviename(int n)
{
    char temp[100];
   // movie=(char *)calloc(100,sizeof(char));
    FILE *fp;
    int i=0;
    fp=fopen("movies.txt","r");
    for(i=0;i<n;i++)
    {
        //printf("\nloop");
        fgets(temp,100,fp);
        // printf("\nMovie = %s",temp);
    }
    strcpy(movie,temp);
    //printf("\nStr: %s",movie);
    fclose(fp); 
}

void disp()
{
    printf("\nGuess:");
    for(int i=0;i<l;i++)
    {
        printf("\t_");
    }
}

void guessch(char *ch)
{
    //for()
}


int main()  
{  
    int n;
    n=ctlines();
    n=genno(n);
    getmoviename(n);
    //printf("\nMoie name is %s",movie);
    l=strlen(movie);
    printf("\nLength of Movie Name is %d",l-1);
    disp();
    guessch(movie);

    


    return 0;  
}  