#include<GLUT/GLUT.h>

void draw_pixel_ellipse(int x,int y)
{
    glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}


void draw_ellipse(int xc,int yc,int a,int b)
{
    int aSq,bSq,twoASq,twoBSq,d,dx,dy,x,y;
    aSq = a*a;
    bSq = b*b;
    twoASq = 2*aSq;
    twoBSq = 2*bSq;
    d=bSq-b*aSq+aSq/4;
    dx = 0;
    dy = twoASq*b;
    x=0;
    y=b;
    draw_pixel_ellipse(xc+x,yc+y);
    draw_pixel_ellipse(xc-x,yc+y);
    draw_pixel_ellipse(xc+x,yc-y);
    draw_pixel_ellipse(xc-x,yc-y);

    while(dx<dy)
    {
        x++;
        dx+=twoBSq;
        if(d>=0)
        {
            y--;
            dy-=twoASq;
        }
        if(d<0)
            d+=bSq+dx;
        else
            d+=bSq+dx-dy;
        draw_pixel_ellipse(xc+x,yc+y);
        draw_pixel_ellipse(xc-x,yc+y);
        draw_pixel_ellipse(xc+x,yc-y);
        draw_pixel_ellipse(xc-x,yc-y);
    }

    d = (int)(bSq*(x)*(x) + aSq*(y)*(y) - aSq*bSq);
    while(y>0)
    {
        y--;
        dy-=twoASq;
        if(d<=0)
        {
            x++;
            dx+=twoBSq;
        }
        if(d>0)
            d+=aSq-dy;
        else
            d+=aSq-dy+dx;
        draw_pixel_ellipse(xc+x,yc+y);
        draw_pixel_ellipse(xc-x,yc+y);
        draw_pixel_ellipse(xc+x,yc-y);
        draw_pixel_ellipse(xc-x,yc-y);
    }
    glFlush();
}
