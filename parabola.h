#include<GLUT/GLUT.h>

void horizontal_draw_pixel_parabola(int x,int y)
{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void vertical_draw_pixel_parabola(int x,int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void draw_horizontal_parabola(int xc,int yc,double a)
{
    double x=0,y=0;  /* initial coorodinates */
    double d=0;
    d=2*a-1;
    horizontal_draw_pixel_parabola(xc+x,yc+y);
    horizontal_draw_pixel_parabola(xc+x,yc-y);
    while(y<=(2*a*1.0))
    {
        if(d<0)
        {
            d+= 4*a-3-2*y;
            x++;
            y++;
        }
        else
        {
            d-= 3 + 2*y;
            y++;
        }
        horizontal_draw_pixel_parabola(xc+x,yc+y);
        horizontal_draw_pixel_parabola(xc+x,yc-y);
    }
    d=4*a*((x+1))-(y+0.5)*(y+0.5);
    while(y<240)
    {
        if(d<0)
        {
            d+= 4*a;
            x++;
        }
        else
        {
            d+=4*a-2*y-2;
            x++;
            y++;
        }
        horizontal_draw_pixel_parabola(xc+x,yc+y);
        horizontal_draw_pixel_parabola(xc+x,yc-y);
    }
}

void draw_vertical_parabola(int xc,int yc,double a)
{
    double x=0,y=0;  /* initial coorodinates */
    double d=0;
    d=2*a-1;
    vertical_draw_pixel_parabola(xc+x,yc+y);
    vertical_draw_pixel_parabola(xc-x,yc+y);
    while(x<=(2*a*1.0))
    {
        if(d<0)
        {
            d+= 4*a-3-2*x;
            x++;
            y++;
        }
        else
        {
            d-= 3 + 2*x;
            x++;
        }
        vertical_draw_pixel_parabola(xc+x,yc+y);
        vertical_draw_pixel_parabola(xc-x,yc+y);
    }
    d=4*a*((y+1))-(x+0.5)*(x+0.5);
    while(x<320)
    {
        if(d<0)
        {
            d+= 4*a;
            y++;
        }
        else
        {
            d+=4*a-2*x-2;
            x++;
            y++;
        }
        vertical_draw_pixel_parabola(xc+x,yc+y);
        vertical_draw_pixel_parabola(xc-x,yc+y);
    }
}

