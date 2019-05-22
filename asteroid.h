#include<GLUT/GLUT.h>

void draw_pixel_asteroid(int x,int y)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void draw_asteroid(int xc,int yc,float r)
{
	int x=0;
	int y=r;
	double p=pow(0.5,0.67)+pow(r-1,0.67)-pow(r,0.67);
	draw_pixel(x,y);
	while(y>x)
	{
		if(p<0)
		{
			y--;
			p+=pow(y-1,0.67)-pow(y-2,0.67);
		}
		else
		{
			y--;
			x++;
			p+=pow(x+0.5,0.67)-pow(x+1.5,0.67)+pow(y-1,0.67)-pow(y-2,0.67);
		}
		draw_pixel(xc+x,yc+y);
		draw_pixel(xc+x,yc-y);
		draw_pixel(xc-x,yc+y);
		draw_pixel(xc-x,yc-y);
		draw_pixel(xc+y,yc+x);
		draw_pixel(xc-y,yc+x);
		draw_pixel(xc+y,yc-x);
		draw_pixel(xc-y,yc-x);
	}
}
