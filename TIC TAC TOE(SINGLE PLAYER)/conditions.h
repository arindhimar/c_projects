#ifndef CONDITIONS_H_INCLUDED
#define CONDITIONS_H_INCLUDED
int wu(int *p1,int *p2,int *p3)
{
    if(*p1=='X'&&*p2=='X'&&*p3=='X')
        return 1;
    else
        return 0;
}
int wc(int *p1,int *p2,int *p3)
{
    if(*p1=='O'&&*p2=='O'&&*p3=='O')
        return 1;
    else
        return 0;
}

int winck(int *p)
{
    int i,u[8],c[8];
    u[0]=wu(p,(p+1),(p+2));
    u[1]=wu((p+3),(p+4),(p+5));
    u[2]=wu((p+6),(p+7),(p+8));
    u[3]=wu(p,(p+3),(p+6));
    u[4]=wu((p+1),(p+4),(p+7));
    u[5]=wu((p+2),(p+5),(p+8));
    u[6]=wu((p+0),(p+4),(p+8));
    u[7]=wu((p+6),(p+4),(p+2));

    c[0]=wc(p,(p+1),(p+2));
    c[1]=wc((p+3),(p+4),(p+5));
    c[2]=wc((p+6),(p+7),(p+8));
    c[3]=wc(p,(p+3),(p+6));
    c[4]=wc((p+1),(p+4),(p+7));
    c[5]=wc((p+2),(p+5),(p+8));
    c[6]=wc((p+0),(p+4),(p+8));
    c[7]=wc((p+6),(p+4),(p+2));

    for(i=0;i<8;i++)
    {
        if(u[i]==1)
        {
            return 1;
        }
        else if(c[i]==1)
        {
            return 2;
        }
    }
    return 0;
}


#endif // CONDITIONS_H_INCLUDED
