//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */

class Grid {
public:
	int gridarray[10][10];
	bool s,b;
	Grid()
	{
		srand(time(0));
		s = false;
		for (int i = 0; i < 10;++i) {
			for (int j = 0; j < 10; ++j) {
				gridarray[i][j] = rand() % 7;
			}
			
		}
	}
	void gamedisplay()
	{
		if (b == false)
		{
			DrawString(270, 290, "PLAY", colors[SILVER]);
		}
		else
		{




			for (int x = 50, i = 0; x < 550; x += 50, ++i)
			{
				for (int y = 50, j = 0; y < 550; y += 50, ++j)
				{
					DrawLine(x, y, x + 50, y, 10, colors[MISTY_ROSE]);
					DrawLine(x, y, x, y + 50, 10, colors[MISTY_ROSE]);
					DrawLine(x, y + 50, x + 50, y + 50, 10, colors[MISTY_ROSE]);
					DrawLine(x + 50, y, x + 50, y + 50, 10, colors[MISTY_ROSE]);
					if (gridarray[i][j] == 0)
					{
						DrawSquare(x + 9, y + 12, 30, colors[INDIGO]);
					}
					if (gridarray[i][j] == 1)
					{
						DrawSquare(x + 9, y + 12, 30, colors[PURPLE]);
					}
					if (gridarray[i][j] == 2)
					{
						DrawSquare(x + 9, y + 12, 30, colors[GREEN]);
					}
					if (gridarray[i][j] == 3)
					{
						DrawSquare(x + 9, y + 12, 30, colors[AQUA]);
					}
					if (gridarray[i][j] == 4)
					{
						DrawSquare(x + 9, y + 12, 30, colors[TEAL]);
					}
					if (gridarray[i][j] == 5)
					{
						DrawSquare(x + 9, y + 12, 30, colors[RED]);
					}
					if (gridarray[i][j] == 6)
					{
						DrawSquare(x + 9, y + 12, 30, colors[YELLOW]);
					}
					if (gridarray[i][j] == 7)
					{
						DrawSquare(x + 9, y + 12, 30, colors[ORANGE_RED]);
					}
					if (gridarray[i][j] == 7)
					{
						DrawSquare(x + 9, y + 12, 30, colors[INDIAN_RED]);
					}
					if (gridarray[i][j] == 8)
					{
						DrawSquare(x + 9, y + 12, 30, colors[BROWN]);
					}
					if (gridarray[i][j] == 9)
					{
						DrawSquare(x + 9, y + 12, 30, colors[BLUE_VIOLET]);
					}
				}
			}
		}
	}
		void bash()
		{

			//srand(time(0));
			for (int i = 0; i < 10; ++i) 
			{
				for (int j = 0; j < 10; ++j)
				{
					if (gridarray[i][j] == gridarray[i][ j + 1] && gridarray[i][ j] ==gridarray[ i][ j +2])
					{
						
						gridarray[i][j] = rand() % 7;
						gridarray[i][j + 1] = rand() % 7;
						gridarray[i][j +2 ] = rand() % 7;
						s = true;
					}
					else
					{
						s = false;
					}
					if (gridarray[i][j] == gridarray[i][j - 1] && gridarray[i][j] == gridarray[i][j - 2])
					{
						
						gridarray[i][j] = rand() % 7;
						gridarray[i][j - 1] = rand() % 7;
						gridarray[i][j - 2] = rand() % 7;
						s = true;
					}
					else
					{
						s = false;
					}
					if (gridarray[i][j] == gridarray[i+1][j] && gridarray[i][j] == gridarray[i+2][j])
					{
						
						gridarray[i][j] = rand() % 7;
						gridarray[i+1][j ] = rand() % 7;
						gridarray[i+2][j] = rand() % 7;
						s = true;
					}
					else
					{
						s = false;
					}
					if (gridarray[i][j] == gridarray[i-1][j ] && gridarray[i][j] == gridarray[i-2][j])
					{
						
						gridarray[i][j] = rand() % 7;
						gridarray[i-1][j] = rand() % 7;
						gridarray[i-2][j ] = rand() % 7;
						s = true;
					}
					else
					{
						s = false;
					}
				}
			}
		}
};
Grid G;
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Fire Gun
	//DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Mushroom
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	/*DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	*/
	G.gamedisplay();

	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	//cout << x << " " << y << endl;
	//glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
int mousepressX, mousepressY;
int mousereleaseX, mousereleaseY;

void MouseClicked(int button, int state, int x, int y) 
{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		//cout << GLUT_DOWN << " " << GLUT_UP << endl;
		if (state == GLUT_DOWN)
		{
			cout << "Pressed" << x << " " << y << endl;
			mousepressX = x; mousepressY = y;

		}
		else if (state == GLUT_UP)
		{
			cout << "Release" << x << " " << y << endl;
			mousereleaseX = x; mousereleaseY = y;
		}
		int oldi = (mousepressX - 50) / 50;
		int oldj = (600 - mousepressY - 50) / 50;
		int  newi = (mousereleaseX - 50) / 50;
		int newj = (600 - mousereleaseY - 50) / 50;
		cout << "Pressed" << oldi << " " << oldj << endl;
		cout << "Release" << newi << " " << newj << endl;
		if ((newi == 4 || newi == 5) && (newj == 4 || newj == 5))
		{
			G.b = true;
		}
		if(((oldi == newi + 1) || (oldi == newi - 1)) || ((oldj == newj + 1) || (oldj == newj - 1)))
		{
			if ((x >= 54 && x < 544) && (y >= 54 && y < 544))
			{

				int temp = G.gridarray[newi][newj];
				G.gridarray[newi][newj] = G.gridarray[oldi][oldj];
				G.gridarray[oldi][oldj] = temp;
				//swap(G.gridarray[oldi][oldj], G.gridarray[newi][newj]);
				G.bash();


				if (G.s == false)
				{
					swap(G.gridarray[newi][newj], G.gridarray[oldi][oldj]);
				}
			}
		}

	}
		else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
		{
			cout << "Right Button Pressed" << endl;
		}
	
	glutPostRedisplay();
}


/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) 
{

	int width = 600, height = 600; // i have set my window size to be 800 x 600
	//B.DrawLine(400,20,30,500,50,colors[MISTY_ROSE]);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
