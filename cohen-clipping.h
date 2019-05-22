#include<GLUT/GLUT.h>

int code(float x,float y,float xmin,float ymin,float xmax,float ymax)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=2;
    if(x<xmin)c=1;
    return c;
}

void display_after_clip(float *x1_cohen,float *y1_cohen,float *x2_cohen,float *y2_cohen,float xmin,float ymin,float xmax,float ymax,int n_cohen)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0,1.0,0.0);
   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();

   glColor3f(1.0,0.0,0.0);
   glBegin(GL_LINES);
   for(int i=0;i<n_cohen;i++)
   {
       glVertex2i(x1_cohen[i],y1_cohen[i]);
       glVertex2i(x2_cohen[i],y2_cohen[i]);
   }
   glEnd();
   glFlush();
}

void cohen_Line(float x1,float y1,float x2,float y2,int i,float *x1_cohen,float *y1_cohen,float *x2_cohen,float *y2_cohen,float xmin,float ymin,float xmax,float ymax,int n_cohen)
{
    int c1=code(x1,y1,xmin,ymin,xmax,ymax);
    int c2=code(x2,y2,xmin,ymin,xmax,ymax);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
           exit(0);
        }

    float xi=x1;
    float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else
       if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else
       if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           x1_cohen[i]=x;
           y1_cohen[i]=y;
           c1=code(x1_cohen[i],y1_cohen[i],xmin,ymin,xmax,ymax);
       }

       if(c==c2)
       {
           x2_cohen[i]=x;
           y2_cohen[i]=y;
           c2=code(x2_cohen[i],y2_cohen[i],xmin,ymin,xmax,ymax);
       }
}
 display_after_clip(x1_cohen,y1_cohen,x2_cohen,y2_cohen,xmin,ymin,xmax,ymax,n_cohen);
}

