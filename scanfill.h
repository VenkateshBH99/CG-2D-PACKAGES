#include<GLUT/GLUT.h>

void draw_pixel_scanline(int x,int y,GLfloat r,GLfloat g,GLfloat b)
{
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void edgedetect(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,int *le,int *re,GLfloat r,GLfloat g,GLfloat b)
{
    float mx,x,temp;
    int i,k;
    if((y2-y1)<0)
    {
        temp=x1;
        x1=x2;
        x2=temp;
        temp=y1;
        y1=y2;
        y2=temp;
    }
    if((y2-y1)!=0)
        mx=(x2-x1)/(y2-y1);
    else
        mx=x2-x1;
    x=x1;
    for(i=(int)y1;i<(int)y2;i++)
    {
        int t=0;                //flag
        if(x<(float)le[i])
        {
            if((float)le[i]!=500)
            {
                le[i]=(int)x;
                for(k=re[i]-1;k>le[i];k--)
                    draw_pixel_scanline(k,i,r,g,b);
                le[i]=500;
                re[i]=0;
                t=1;
            }
            else
                le[i]=(int)x;
        }
        if(t==0)
        if(x>(float)re[i])
        {
            if((float)re[i]!=0)
            {
                re[i]=(int)x;
                for(k=le[i]+1;k<re[i];k++)
                    draw_pixel_scanline(k,i,r,g,b);
                le[i]=500;
                re[i]=0;
            }
            else
                re[i]=(int)x;
        }
        x+=mx;
    }
}

void scanfill(GLfloat *x,GLfloat *y,int n,GLfloat r,GLfloat g,GLfloat b)
{
    int le[500],re[500];
    int i;
    for(i=0;i<500;i++)
    {
        le[i]=500;
        re[i]=0;
    }

    for(int k=0;k<n-1;k++)
    {
        edgedetect(x[k],y[k],x[k+1],y[k+1],le,re,r,g,b);

    }
    edgedetect(x[n-1],y[n-1],x[0],y[0],le,re,r,g,b);
}
