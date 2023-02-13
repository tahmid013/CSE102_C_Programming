#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include<math.h>
void func2();
void func3();
int x = 400, y = 400, r =60,hour;
char str[100],lastKey = 0;
int red=0,i;
double deg1,deg2,deg3,theta1,theta2,theta3,xp;
int c=0,cx=100,cy=175,tm=300;

/*

	function iDraw() is called again and again by the system.

	*/
void func1()
{
    deg1=deg1+6;

    if(int(deg1)%360==0&&deg1!=0)
    {
        func2();
        deg1=0;
    }
}
void func2()
{
    deg2=deg2+6;
    func3();
    /*
    if(int(deg2)%360==0&&deg2!=0){

    func3()*/


}
void func3()
{
    deg3=deg3+0.5;
}

void iDraw()
{


    theta1=deg1*3.14159/180;
    theta2=deg2*3.14159/180;
    theta3=deg3*3.14159/180;
    //place your drawing codes here
    iClear();
    //theta1=(deg1*3.14159)/(180);
    iSetColor(red, 250-red, 250);
    //iCircle(x, y, r);
    for(i=0; i<20; i++)
        iCircle(x, y, 20+r+i*0.15);
    iSetColor(0, 200, 0);
    iText(40, 540, "This is an analog clock built by iGraphics ");
    //for(i=0;i<10;i++)

    iLine(x, y,x+r*cos(-theta1),y+r*sin(-theta1));


    iSetColor(0,250,0);
    iLine(x, y,x+(r-10)*cos(-theta2),y+(r-10)*sin(-theta2));
    iSetColor(255,255,255);
    iLine(x, y,x+(r-25)*cos(-theta3),y+(r-25)*sin(-theta3));



    /*  iSetTimer(1000,func3);
      iSetColor(0,250,250);
          	iLine(x, y ,x+r*cos(-deg3) ,y+r*sin(-deg3));*/

    //  iLine(x, y ,x+(r-15)*cos(-theta3) ,y+(r-15)*sin(-theta3));
    //  iSetTimer(1000,func3);
    iSetColor(204,204,255);


    iText(x-10,y+r+5,"12");
    iText(x-5,y-r-10,"6");
    iText(x+r+7,y,"3");
    iText(x-r-15,y,"9");
    iText(x+r*0.5+2,y+r*0.866+3,"1");
    iText(x+r*0.866+3,y+r*0.5+3,"2");
    iText(x+r*0.5-4,y-r*0.866-10,"5");
    iText(x+r*0.866+3,y-r*0.5-3,"4");
    iText(x-r*0.5-15,y+r*0.866+2,"11");
    iText(x-r*0.866-15,y+r*0.5-1,"10");
    iText(x-r*0.5-8,y-r*0.866-10,"7");
    iText(x-r*0.866-10,y-r*0.5-7,"8");
    //  iText(x-3,y+r-2,"12");

//iRectangle(100, 100 , 200, 100);
    /*  iFilledCircle(cx,cy,25);
      if(cy==190)
          cy--;
    */
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    //	printf("x = %d, y= %d\n",mx,my);
    //place your codes here
    if(mx>=100&&mx<=200&&my>=100&&my<=100)
        scanf("%s",str);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
//place your codes here
        //	printf("x = %d, y= %d\n",mx,my);

    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
    static int c=0;
    if (key == 'q')
    {
        exit(0);

    }
    if (key == 'l')
    {
        func1();
    }
    else if(lastKey == key)
    {
        c++;
    }
    else
    {
        printf("lastKey:%c  %d times\n",lastKey,c);
        c = 0;
        lastKey = key;
    }

    //printf("%c\n",key);
    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
    //place your codes for other keys here
}


int main()
{
    double hour,minit,sec;
//scanf("%lf%lf%lf",&hour,&minit,&sec);
    deg1=sec*6-90;

    deg2=(minit+sec/60)*6-90;

    deg3=(hour+minit/60)*30-90;
    iSetTimer((1000),func1);


    //place your own initialization codes here.
    iInitialize(600, 600, "Analougue Clock");

    return 0;
}
