#include<GLUT/GLUT.h>

void draw_pixel_circle(int x,int y)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void draw_circle(int xc,int yc,int r)
{
	int x=0;
	int y=r;
	float p=5/4-r;          // p - Decision Parameter
	draw_pixel_circle(x+xc,y+yc);              // p(k+1) = p(k) + 2*(x(k)+1) + 2*(sqr(y(k+1))-sqr(y(k))) - 2*(y(k+1)-y(k)) + 1
	while(y>x)
	{
		if(p<0)
		{
			x++;
			p+=2*x+1;
		}
		else
		{
			y--;
			x++;
			p+=2*(x-y)+1;
		}
		draw_pixel_circle(xc+x,yc+y);
		draw_pixel_circle(xc+x,yc-y);
		draw_pixel_circle(xc-x,yc+y);
		draw_pixel_circle(xc-x,yc-y);
		draw_pixel_circle(xc+y,yc+x);
		draw_pixel_circle(xc-y,yc+x);
		draw_pixel_circle(xc+y,yc-x);
		draw_pixel_circle(xc-y,yc-x);
	}
}
