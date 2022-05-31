#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int num;
    srand(time(NULL));
    num=rand()%6;

    printf("%d",num);
    return 0;
}
