//
//  main.cpp
//  cgP1
//
//  Created by Venkatesh B h on 5/23/19.
//  Copyright © 2019 Apple Inc. All rights reserved.
//

#include<GLUT/GLUT.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<iostream>
#include"line.h"
#include"circle.h"
#include"ellipse.h"
#include"hyperbola.h"
#include"parabola.h"
#include"scanfill.h"
#include"cohen-clipping.h"
#include"asteroid.h"
#include"transformation.h"
#include"dotted_line.h"
#include"dashed_line.h"

int xs,ys,xd,yd;                                        // Line drawing

int xs_dot,ys_dot,xd_dot,yd_dot;                        // Dotted Line Drawing

int xs_dash,ys_dash,xd_dash,yd_dash;                    // Dashed Line Drawing

int x_circle,y_circle,r_circle;                         // Circle

int x_ellipse,y_ellipse,a_ellipse,b_ellipse;            // Ellipse

int x_hyperbola,y_hyperbola,a_hyperbola,b_hyperbola;    // Hyperbola

int x_parabola,y_parabola,choice_parabola;              // Parabola
double a_parabola;

int x_asteroid,y_asteroid;                              // Asteroid
float r_asteroid;

GLfloat x_scanline[10],y_scanline[10];                  // Scan-line Polygon-fill
GLfloat r_scanfill,g_scanfill,b_scanfill;
int n_scanfill;

float xmin_cohen,ymin_cohen,xmax_cohen,ymax_cohen,n_cohen;    // Cohen-Sutherland Line Clipping
float x1_cohen[10],y1_cohen[10],x2_cohen[10],y2_cohen[10];

int pntX1,pntY1,choice_trans=0,edges_trans;                                // Transformation
std::vector<int> pntX;
std::vector<int> pntY;
int transX, transY;
double scaleX,scaleY;
double angle,angleRad;
char reflectionAxis,shearingAxis;
int shearingX,shearingY;
 int ch;
void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(-320,320,-240,240);
}

void display()
{ if(ch==1)
   draw_line(xs,xd,ys,yd);
    else if(ch==2)
    draw_dotted_line(xs_dot,ys_dot,xd_dot,yd_dot);
    else if(ch==3)
    draw_dashed_line(xs_dash,ys_dash,xd_dash,yd_dash);
    else if(ch==4)
    draw_circle(x_circle,y_circle,r_circle);
    else if(ch==5)
    draw_ellipse(x_ellipse,y_ellipse,a_ellipse,b_ellipse);
    else if(ch==6)
    draw_hyperbola(x_hyperbola,y_hyperbola,a_hyperbola,b_hyperbola);
    else if(ch==7)
    draw_asteroid(x_asteroid,y_asteroid,r_asteroid);
    else if(ch==8){
    if(choice_parabola==1)
        draw_horizontal_parabola(x_parabola,y_parabola,a_parabola);
    else if(choice_parabola==2)
        draw_vertical_parabola(x_parabola,y_parabola,a_parabola);
    }
    else if(ch==9){
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0);
    for(int k=0;k<n_scanfill;k++)
    {
        glVertex2f(x_scanline[k],y_scanline[k]);
    }
        glEnd();
    scanfill(x_scanline,y_scanline,n_scanfill,r_scanfill,g_scanfill,b_scanfill);
    }
    else if(ch==10){
    if(choice_trans==1)
    {
        draw_Polygon(pntX,pntY,edges_trans);
        draw_Polygon_Trans(transX,transY,pntX,pntY,edges_trans);
    }
    else if(choice_trans==2)
    {
        draw_Polygon(pntX,pntY,edges_trans);
        draw_Polygon_Scale(scaleX,scaleY,pntX,pntY,edges_trans);
    }
    else if(choice_trans==3)
    {
        draw_Polygon(pntX,pntY,edges_trans);
        draw_Polygon_Rotation(angleRad,pntX,pntY,edges_trans);
    }
    else if(choice_trans==4)
    {
        draw_Polygon(pntX,pntY,edges_trans);
        draw_Polygon_MirrorReflection(reflectionAxis,pntX,pntY,edges_trans);
    }
    else if(choice_trans==5)
    {
        draw_Polygon(pntX,pntY,edges_trans);
        draw_Polygon_Shearing(shearingX,shearingY,shearingAxis,pntX,pntY,edges_trans);
    }
    }
    else if(ch==11){
    for(int k=0;k<n_cohen;k++){
        cohen_Line(x1_cohen[k], y1_cohen[k], x2_cohen[k], y2_cohen[k], k, x1_cohen, y1_cohen, x2_cohen, y2_cohen, xmin_cohen, ymin_cohen, xmax_cohen, ymax_cohen, n_cohen);
    }}
    glFlush();
}

using namespace std;

int main(int argc, char **argv)
{
    //Line Drawing
   
    cout<<"1. Normal line\n"<<"2. Dotted line\n"<<"3.Dashed line\n"<<"4.Circle\n"<<"5.Ellipse\n"<<"6.Hyperbola\n"<<"7.parabola\n"<<"8.Scanfill\n"<<"9.Asteroid\n"<<"10.transformation\n"<<"11.line clipping\n"<<"Enter ur choice:";
    cin>>ch;
    if(ch==1){
   cout<<"Enter the co-ordinate for Normal line"<<endl;
    cout<<"Enter the First co-ordinate : ";
    cin>>xs>>ys;
    cout<<"Enter the Second co-ordinate : ";
    cin>>xd>>yd;
    }
    // Dotted Line Drawing
    else if(ch==2){
    cout<<"Enter the co-ordinate for Dotted line"<<endl;
    cout<<"Enter the First co-ordinate : ";
    cin>>xs_dot>>ys_dot;
    cout<<"Enter the Second co-ordinate : ";
    cin>>xd_dot>>yd_dot;
    }
    // Dashed Line Drawing
    else if(ch==3){
    cout<<"Enter the co-ordinate for Dashed line"<<endl;
    cout<<"Enter the First co-ordinate : ";
    cin>>xs_dash>>ys_dash;
    cout<<"Enter the Second co-ordinate : ";
    cin>>xd_dash>>yd_dash;
    }
    // Circle Drawing
    else if(ch==4){
    cout<<"Enter the coordinates of the center for Circle"<<endl;
    cout<<"X-coordinate : ";
    cin>>x_circle;
    cout<<"Y-coordinate : ";
    cin>>y_circle;
    cout<<"Window range : (-320 to 320) and (-240 to 240)"<<endl;
    cout<<"Enter radius : ";
    cin>>r_circle;
    }
    // Ellipse Drawing
    else if(ch==5){
    cout<<"Enter the coordinates of the center for Ellipse"<<endl;
    cout<<"X-coordinate : ";
    cin>>x_ellipse;
    cout<<"Y-coordinate : ";
    cin>>y_ellipse;
    cout<<"Window range : (-320 to 320) and (-240 to 240)"<<endl;
    cout<<"Enter the value of x-intercept for Ellipse (=a) : ";
    cin>>a_ellipse;
    cout<<"Enter the value of y-intercept for Ellipse (=b) : ";
    cin>>b_ellipse;
    }
    // Hyperbola Drawing
    else if(ch==6){
    cout<<"Enter the coordinates of the center for Hyperbola"<<endl;
    cout<<"X-coordinate : ";
    cin>>x_hyperbola;
    cout<<"Y-coordinate : ";
    cin>>y_hyperbola;
    cout<<"Window range : (-320 to 320) and (-240 to 240)"<<endl;
    cout<<"Enter the value of x-intercept for Hyperbola (=a) : ";
    cin>>a_hyperbola;
    cout<<"Enter the value of y-intercept for Hyperbola (=b) : ";
    cin>>b_hyperbola;
    }
    // Parabola Drawing
    else if(ch==7){
    cout<<"Enter \n1. For Horizontal Parabola \n2. For Vertical Parabola\n";
    cin>>choice_parabola;
    cout<<"Enter the coordinates of the center for Parabola"<<endl;
    cout<<"X-coordinate : ";
    cin>>x_parabola;
    cout<<"Y-coordinate : ";
    cin>>y_parabola;
    cout<<"Window range : (-320 to 320) and (-240 to 240)"<<endl;
    cout<<"Enter the value of intercept for Parabola (=a) :";
    cin>>a_parabola;
    }
    // Scan-line Polygon filling
    else if(ch==8){
    cout<<"Enter the number of edges of the polygon for Scan-fill : ";
    cin>>n_scanfill;
    for(int i=0;i<n_scanfill;i++)
    {
        cout<<"Enter line "<<i+1<<" co-ordinates :  ";
        cin>>x_scanline[i]>>y_scanline[i];
    }
    cout<<"Enter the RGB value for Scan-fill : ";
    cin>>r_scanfill>>g_scanfill>>b_scanfill;
    }
    // Asteroid
    else if(ch==9){
    cout<<"Enter the coordinates of the center for Asteroid"<<endl;
    cout<<"X-coordinate : ";
    cin>>x_asteroid;
    cout<<"Y-coordinate : ";
    cin>>y_asteroid;
    cout<<"Window range : (-320 to 320) and (-240 to 240)"<<endl;
    cout<<"Enter radius for Asteroid : ";
    cin>>r_asteroid;
    }
    // Transformation
    else if(ch==10){
    cout<<"Enter your choice:\n\n"<<endl;
    cout<<"1. Translation"<<endl;
    cout<<"2. Scaling"<<endl;
    cout<<"3. Rotation"<<endl;
    cout<<"4. Mirror Reflection"<<endl;
    cout<<"5. Shearing"<<endl;
    cout<<"6. Exit"<<endl;
    cin >> choice_trans;
    if(choice_trans==6)
    {
        return 0;
    }
    
    cout<<"\n\nFor Polygon:\n"<<endl;
    cout<<"Enter no of edges : ";
    cin>>edges_trans;
    
    for(int i=0;i<edges_trans;i++)
    {
        cout<<"Enter co-ordinates for vertex "<<i+1<<" : ";
        cin>>pntX1>>pntY1;
        pntX.push_back(pntX1);
        pntY.push_back(pntY1);
    }
    if(choice_trans==1)
    {
        cout<<"Enter the translation factor for X and Y : ";
        cin>>transX>>transY;
    }
    else if(choice_trans==2)
    {
        cout <<"Enter the scaling factor for X and Y : ";
        cin>>scaleX>>scaleY;
    }
    else if(choice_trans==3)
    {
        cout<<"Enter the angle for rotation : ";
        cin>>angle;
        angleRad=angle*3.1416/180;
    }
    else if(choice_trans==4)
    {
        cout<<"Enter reflection axis ( x or y ) : ";
        cin>>reflectionAxis;
    }
    else if(choice_trans==5)
    {
        cout<<"Enter shearing axis ( x or y ) : ";
        cin>>shearingAxis;
        if(shearingAxis=='x'||shearingAxis=='X')
        {
            cout<<"Enter the shearing factor for X : ";
            cin>>shearingX;
        }
        else
        {
            cout<<"Enter the shearing factor for Y : ";
            cin>>shearingY;
        }
    }
    }
    else if(ch==11){
       cout<<"Enter the number of lines to be drawn for Line Clipping ( <= 10) : ";
     cin>>n_cohen;
     for(int i=0;i<n_cohen;i++)
     {
     cout<<"Enter line "<<i+1<<" co-ordinates :  ";
     cin>>x1_cohen[i]>>y1_cohen[i]>>x2_cohen[i]>>y2_cohen[i];
     }
     cout<<"Enter the Clipping window value in the order xmin,ymin,xmax,ymax";
     cin>>xmin_cohen>>ymin_cohen>>xmax_cohen>>ymax_cohen;
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,100);
    glutCreateWindow("2D Packages 2.0");
    init();
    glutDisplayFunc(display);
    //glutKeyboardFunc(mykey);
    glutMainLoop();
    return 0;
}
