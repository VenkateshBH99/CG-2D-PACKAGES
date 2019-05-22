
#include<GLUT/GLUT.h>
#include<vector>
#include<cmath>

double round(double d)
{
	return floor(d+0.5);
}

void draw_Polygon(std::vector<int> pntX,std::vector<int> pntY,int edges_trans)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	for(int i=0;i<edges_trans;i++)
	{
		glVertex2i(pntX[i],pntY[i]);
	}
	glEnd();
}

void draw_Polygon_Trans(int x,int y,std::vector<int> pntX,std::vector<int> pntY,int edges_trans)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	for (int i=0;i<edges_trans;i++)
	{
		glVertex2i(pntX[i]+x,pntY[i]+y);
	}
	glEnd();
}

void draw_Polygon_Scale(double x,double y,std::vector<int> pntX,std::vector<int> pntY,int edges_trans)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	for (int i=0;i<edges_trans;i++)
	{
		glVertex2i(round(pntX[i]*x),round(pntY[i]*y));
	}
	glEnd();
}

void draw_Polygon_Rotation(double angleRad,std::vector<int> pntX,std::vector<int> pntY,int edges_trans)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	for (int i=0;i<edges_trans;i++)
	{
		glVertex2i(round((pntX[i]*cos(angleRad))-(pntY[i]*sin(angleRad))),round((pntX[i]*sin(angleRad))+(pntY[i]*cos(angleRad))));
	}
	glEnd();
}

void draw_Polygon_MirrorReflection(char reflectionAxis,std::vector<int> pntX,std::vector<int> pntY,int edges_trans)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	if(reflectionAxis=='x'||reflectionAxis=='X')
	{
		for(int i=0;i<edges_trans;i++)
		{
			glVertex2i(round(pntX[i]),round(pntY[i]*-1));

		}
	}
	else if(reflectionAxis=='y'||reflectionAxis=='Y')
	{
		for(int i=0;i<edges_trans;i++)
		{
			glVertex2i(round(pntX[i]*-1),round(pntY[i]));
		}
	}
	glEnd();
}

void draw_Polygon_Shearing(int shearingX,int shearingY,char shearingAxis,std::vector<int> pntX,std::vector<int> pntY,int edges_trans)
{
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);

	if(shearingAxis=='x'||shearingAxis=='X')
	{
		glVertex2i(pntX[0], pntY[0]);
		glVertex2i(pntX[1] + shearingX, pntY[1]);
		glVertex2i(pntX[2] + shearingX, pntY[2]);
		glVertex2i(pntX[3], pntY[3]);
	}
	else if (shearingAxis == 'y' || shearingAxis == 'Y')
	{
		glVertex2i(pntX[0], pntY[0]);
		glVertex2i(pntX[1], pntY[1]);
		glVertex2i(pntX[2], pntY[2] + shearingY);
		glVertex2i(pntX[3], pntY[3] + shearingY);
	}
	glEnd();
}
