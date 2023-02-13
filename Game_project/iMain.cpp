#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include<math.h>


int x = 400, y = 400, r =60,hour;
char lastKey,key;
int red=0,i;
int bx=200,sx=230,sy=100,by=410;// rx1 hoche boro box==bx
int cx=100,cy=175,c=0,bdy=40,sdy=40,bdx=30,sdx=30;
int l=1,R=0,g=255,b=255;
int b1x=bx-50,b1y=by+30,b2x=bx-90,b2y=by+190,b3x=bx+140,b3y=by-100;
char bc[2][10]= { "bc\\8.bmp","bc\\5.bmp"};


/*

	function iDraw() is called again and again by the system.

	*/
life()
{
    // l--;
    l=0;
    // printf("your life=%d\n",l);

}
void coll()
{
    if((((sx+sdx)>bx)&&(sx<(bdx+bx)))&&(((sy+sdy)>by)&&(sy<(bdy+by))))
    {

        life();

    }
    else if((((sx+sdx)>b1x)&&(sx<(bdx+b1x)))&&(((sy+sdy)>b1y)&&(sy<(bdy+b1y))))
    {

        life();
    }
    else if((((sx+sdx)>b2x)&&(sx<(bdx+b2x)))&&(((sy+sdy)>b2y)&&(sy<(bdy+b2y))))
    {

        life();
    }
    else if((((sx+sdx)>b3x)&&(sx<(bdx+b3x)))&&(((sy+sdy)>b3y)&&(sy<(bdy+b3y))))
    {

        life();
    }

    else if(((sx+sdx)>373)||(sx<93))
    {

        life();
    }

}
void time()
{
    by-=3.65;
    b1y-=3.852;
    b2y-=3.75;

    b3y-=3.5;
    coll();

}


void iDraw()
{


    iText(250,450,"Your score is : ");
    iClear();

    if(l==0)
    {
        iSetColor(255,0,0 );
        iFilledRectangle(0,0,600,600);
        iSetColor(0,0,0);
        iText(230,300,"GAME OVER");
        iText(230,270,"Press 'R' to replay");


    }

    else
    {
        iSetColor(0,250,50);
        iFilledRectangle(0,0,95,600);

        iFilledRectangle(373,0,400,700);
        iSetColor(0,0,0);
        iFilledRectangle(b1x, b1y,bdx, bdy);
        iShowBMP(b1x,b1y,bc[1]);

        iFilledRectangle(b2x, b2y,bdx, bdy);
        iShowBMP(b2x,b2y,bc[1]);

        iFilledRectangle(b3x, b3y,bdx, bdy);
        iShowBMP(b3x,b3y,bc[1]);


        iFilledRectangle(bx, by,bdx, bdy);
        iShowBMP(bx,by,bc[1]);
        iSetColor(0,0,0);
        iRectangle(sx,sy,sdx,sdy );
        iShowBMP(sx,sy,bc[0]);
    }



    if(by<10)
    {
        by=700-(rand()%20+50);
        bx=300+rand()%50+60;

    }
    if(b1y<10)
    {
        b1y=600+rand()%50+100;
        b1x=300+(rand()%90+120);
    }
    if(b2y<10)
    {

        b2y=400+rand()%750+100;
        b2x=350-(rand()%100+160);

    }
    if(b3y<10)
    {

        b3y=600-rand()%10+30;
        b3x=450-(rand()%120+230);



    }
}

    /*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my)
{
    //	printf("x = %d, y= %d\n",mx,my);
    //place your codes here

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

void iKeyboard(unsigned char key)
{
    static int c=0;
    if (key == 'q')
    {
        exit(0);

    }

    if(key=='r')
        l=300;
    by=700;
    b2y=600;
    b3y=650;
    b1y=400;
    sx=250;
}

void iSpecialKeyboard(unsigned char key)
{

    if (key == GLUT_KEY_END)
    {
        exit(0);
    }

    if (key == GLUT_KEY_UP)
    {
        sy+=10;


    }
    if (key ==GLUT_KEY_LEFT)
    {
        sx-=10;


    }
    if (key == GLUT_KEY_DOWN)
    {
        sy-=10;


    }
    if (key == GLUT_KEY_RIGHT)
    {
        sx+=10;


    }

}


int main()
{


    iSetTimer(10,time);



    //place your own initialization codes here.

    iInitialize(600, 600, "Simple Game");

    return 0;

}
