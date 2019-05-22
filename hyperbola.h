#include<GLUT/GLUT.h>

void draw_pixel_hyperbola(int x, int y)
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

double round_hyperbola(double d) //Rounding Function
{
    return floor(d + 0.5);
}

void draw_hyperbola(int xc,int yc,int a,int b) //Mid-point Hyperbola drawing Algorithm
{
    double d2;
    int x=a,y=0;
    int sa=a*a;
    int sb=b*b;
    int aa2=2*sa;
    int bb2=2*sb;
    double d1=a*sb+sb/4-sa;
    double fx=bb2*a,fy=0;

    draw_pixel_hyperbola(xc+x,yc+y);
    draw_pixel_hyperbola(xc-x,yc+y);
    draw_pixel_hyperbola(xc+x,yc-y);
    draw_pixel_hyperbola(xc-x,yc-y);
    while(fx>fy && x<=500){
        y++;
        fy+=aa2;
        if(d1>=0){
            d1-=sa*(2*y+1);
        }
        else{
            x++;
            fx+=bb2;
            d1+=bb2*x-sa*(2*y+1);
        }
        draw_pixel_hyperbola(xc+x,yc+y);
        draw_pixel_hyperbola(xc-x,yc+y);
        draw_pixel_hyperbola(xc+x,yc-y);
        draw_pixel_hyperbola(xc-x,yc-y);
    }
    d2=sb*(x+1)*(x+1)-sa*(y+0.5)*(y+0.5)-sa*sb;
    while(x<=500){
        x++;
        if(d2<0){
            d2+=sb*(1+2*x);
        }
        else{
            y++;
            d2+=sb*(1+2*x);
        }
        draw_pixel_hyperbola(xc+x,yc+y);
        draw_pixel_hyperbola(xc-x,yc+y);
        draw_pixel_hyperbola(xc+x,yc-y);
        draw_pixel_hyperbola(xc-x,yc-y);
    }
}
