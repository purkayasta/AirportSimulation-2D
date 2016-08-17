#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

int viewY1, viewX1, viewX2, viewX3, viewY2, viewY3, watX, cloudX1, cloudX2, cloudX3;
float move_unit = 5;
float move_units = 4;
float unit = 0.7;
float cldU1 = 0.045;
float cldU2 = 0.015;
float cldU3 = 0.2;
int weather_const = 0;



void weather() {
	switch (weather_const)
	{
	case(0):
		glClearColor(0.18039, 0.18039, 0.18039, 0.0);
		weather_const++;
		break;
	case(1): {
		glClearColor(0.21960, 0.21960, 0.21960, 0.0);
		weather_const++;
		break; }
	case(2): {
		glClearColor(0.278431, 0.278431, 0.278431, 0.0);
		weather_const++;
		break; }
	case(3): {
		glClearColor(0.301960, 0.301960, 0.301960, 0.0);
		weather_const++;
		break; }
	case(4): {
		glClearColor(0.38039, 0.38039, 0.38039, 0.0);
		weather_const++;
		break; }
	case(5): {
		glClearColor(0.5490196, 0.5490196, 0.549016, 0.0);
		weather_const++;
		break; }
	case(6): {
		glClearColor(0.611764, 0.611764, 0.611764, 0.0);
		weather_const++;
		break; }
	case(7): {
		glClearColor(0.74156, 0.74156, 0.74156, 0.0);
		weather_const++;
		break; }
	case(8): {
		glClearColor(0.87058, 0.87058, 0.87058, 0.0);
		weather_const++;
		break; }
	case(9): {
		glClearColor(0.89019, 0.89019, 0.89019, 0.0);
		weather_const++;
		break; }

	case(10): {
		glClearColor(1.0, 1.0, 1.0, 0.0);
		weather_const = 0;
		break; }
	}

}

void delay(int value) {
	glutPostRedisplay();
	glutTimerFunc(10, delay, 1000);
}


void boat() {
	watX += unit;

	//boat in the river
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2i(0 + watX, 30);
	glVertex2i(100 + watX, 30);
	glVertex2i(130 + watX, 50);
	glVertex2i(-20 + watX, 50);
	glEnd();
	//boat properties

	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(110 + watX, 30);
	glVertex2i(115 + watX, 30);
	glVertex2i(80 + watX, 70);
	glVertex2i(75 + watX, 70);
	glEnd();
	watX += 1;
	if (watX > 768) {
		watX = 0;
	}
}


void drawCircle(float x, float y, float radius) {
	int i;
	int triangleAmount = 500;
	GLfloat twicePi = 2.0f * 3.1416;

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(10.0);

	glBegin(GL_LINES);
	for (i = 0; i <= triangleAmount; i++)
	{
		glVertex2f(x, y);
		glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
	}
	glEnd();
}

void cloud1() {
	cloudX1 += cldU1;

	//wind left

	glColor3ub(119, 136, 153);
	drawCircle(53 + cloudX1, 440, 20);
	drawCircle(111 + cloudX1, 440, 20);
	drawCircle(80 + cloudX1, 435, 20);
	drawCircle(80 + cloudX1, 450, 20);



	cloudX1 += 1;
	if (cloudX1> 640) {
		cloudX1 = 0;
	}
}


void cloud2() {
	cloudX2 += cldU2;



	//wind middle
	drawCircle(253 + cloudX2, 440, 20);
	drawCircle(311 + cloudX2, 440, 20);
	drawCircle(280 + cloudX2, 435, 20);
	drawCircle(280 + cloudX2, 450, 20);



	cloudX2 += 1;
	if (cloudX2> 768) {
		cloudX2 = 0;
	}
}


void cloud3() {
	cloudX3 += cldU3;



	glColor3ub(119, 136, 153);
	//wind right
	drawCircle(453 + cloudX3, 440, 20);
	drawCircle(511 + cloudX3, 440, 20);
	drawCircle(480 + cloudX3, 435, 20);
	drawCircle(480 + cloudX3, 450, 20);

	cloudX3 += 1;
	if (cloudX3> 768) {
		cloudX3 = 0;
	}
}


void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void plane1() {
	/*----------------------- Plane ------------- */
	//plane tail


	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glPointSize(4.0);

	glVertex2i(10 + viewX1, 245 + viewY1);
	glVertex2i(15 + viewX1, 245 + viewY1);
	glVertex2i(35 + viewX1, 235 + viewY1);
	glVertex2i(15 + viewX1, 225 + viewY1);
	glEnd();

	//plane wing back
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(80 + viewX1, 225 + viewY1);
	glVertex2i(90 + viewX1, 245 + viewY1);
	glVertex2i(85 + viewX1, 245 + viewY1);
	glVertex2i(50 + viewX1, 225 + viewY1);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(80 + viewX1, 225 + viewY1);
	glVertex2i(90 + viewX1, 245 + viewY1);
	glVertex2i(88 + viewX1, 245 + viewY1);
	glVertex2i(55 + viewX1, 225 + viewY1);
	glEnd();

	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(90 + viewX1, 220 + viewY1);
	glVertex2i(30 + viewX1, 220 + viewY1);
	glVertex2i(15 + viewX1, 225 + viewY1);
	glVertex2i(35 + viewX1, 235 + viewY1);
	glVertex2i(80 + viewX1, 235 + viewY1);
	glVertex2i(90 + viewX1, 230 + viewY1);
	glEnd();

	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(90 + viewX1, 227 + viewY1);
	glVertex2i(30 + viewX1, 227 + viewY1);
	glVertex2i(30 + viewX1, 230 + viewY1);
	glVertex2i(90 + viewX1, 230 + viewY1);
	glEnd();

	glColor3ub(255, 0, 0);//head
	glBegin(GL_POLYGON);
	glVertex2i(90 + viewX1, 220 + viewY1);
	glVertex2i(90 + viewX1, 230 + viewY1);
	glVertex2i(100 + viewX1, 222 + viewY1);
	glVertex2i(100 + viewX1, 220 + viewY1);
	glEnd();

	glColor3ub(204, 255, 255);//glass
	glBegin(GL_POLYGON);
	glVertex2i(80 + viewX1, 225 + viewY1);
	glVertex2i(90 + viewX1, 225 + viewY1);
	glVertex2i(90 + viewX1, 228 + viewY1);
	glVertex2i(78 + viewX1, 237 + viewY1);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(80 + viewX1, 225 + viewY1);
	glVertex2i(35 + viewX1, 212 + viewY1);
	glVertex2i(25 + viewX1, 212 + viewY1);
	glVertex2i(50 + viewX1, 225 + viewY1);
	glEnd();

	delay(1);
	glutTimerFunc(5, delay, 0);



	//glutSwapBuffers();
	glutPostRedisplay();

}
void plane2() {
	//delay(1000);
	viewX2 += move_unit;
	viewY2 += move_units;
	
	//plane tail

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glPointSize(4.0);

	glVertex2i(-90 + viewX2, 445);
	glVertex2i(-85 + viewX2, 445);
	glVertex2i(-65 + viewX2, 435);
	glVertex2i(-85 + viewX2, 425);
	glEnd();

	//plane wing back
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX2, 425);
	glVertex2i(-10 + viewX2, 445);
	glVertex2i(-15 + viewX2, 445);
	glVertex2i(-50 + viewX2, 425);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX2, 425);
	glVertex2i(-10 + viewX2, 445);
	glVertex2i(-12 + viewX2, 445);
	glVertex2i(-45 + viewX2, 425);
	glEnd();

	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-10 + viewX2, 420);
	glVertex2i(-70 + viewX2, 420);
	glVertex2i(-85 + viewX2, 425);
	glVertex2i(-65 + viewX2, 435);
	glVertex2i(-20 + viewX2, 435);
	glVertex2i(-10 + viewX2, 430);
	glEnd();

	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-10 + viewX2, 427);
	glVertex2i(-70 + viewX2, 427);
	glVertex2i(-70 + viewX2, 430);
	glVertex2i(-10 + viewX2, 430);
	glEnd();

	glColor3ub(255, 0, 0);//head
	glBegin(GL_POLYGON);
	glVertex2i(-10 + viewX2, 420);
	glVertex2i(-10 + viewX2, 430);
	glVertex2i(0 + viewX2, 422);
	glVertex2i(0 + viewX2, 420);
	glEnd();

	glColor3ub(204, 255, 255);//glass
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX2, 425);
	glVertex2i(-10 + viewX2, 425);
	glVertex2i(-10 + viewX2, 428);
	glVertex2i(-22 + viewX2, 437);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX2, 425);
	glVertex2i(-65 + viewX2, 412);
	glVertex2i(-75 + viewX2, 412);
	glVertex2i(-50 + viewX2, 425);
	glEnd();
	viewX2 += 1;
	viewY2 += 1;

	delay(1);
	glutTimerFunc(5, delay, 0);
	if (viewX2 > 768) {
		viewX2 = 0;
		viewY2 = 0;
	}
	glutPostRedisplay();


	//glutSwapBuffers();
	//glutPostRedisplay();
}
void plane3() {

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glPointSize(4.0);

	glVertex2i(-90 + viewX3, 445 - viewY3);
	glVertex2i(-85 + viewX3, 445 - viewY3);
	glVertex2i(-65 + viewX3, 435 - viewY3);
	glVertex2i(-85 + viewX3, 425 - viewY3);
	glEnd();

	//plane wing back
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX3, 425 - viewY3);
	glVertex2i(-10 + viewX3, 445 - viewY3);
	glVertex2i(-15 + viewX3, 445 - viewY3);
	glVertex2i(-50 + viewX3, 425 - viewY3);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX3, 425 - viewY3);
	glVertex2i(-10 + viewX3, 445 - viewY3);
	glVertex2i(-12 + viewX3, 445 - viewY3);
	glVertex2i(-45 + viewX3, 425 - viewY3);
	glEnd();

	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-10 + viewX3, 420 - viewY3);
	glVertex2i(-70 + viewX3, 420 - viewY3);
	glVertex2i(-85 + viewX3, 425 - viewY3);
	glVertex2i(-65 + viewX3, 435 - viewY3);
	glVertex2i(-20 + viewX3, 435 - viewY3);
	glVertex2i(-10 + viewX3, 430 - viewY3);
	glEnd();

	glColor3ub(0, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-10 + viewX3, 427 - viewY3);
	glVertex2i(-70 + viewX3, 427 - viewY3);
	glVertex2i(-70 + viewX3, 430 - viewY3);
	glVertex2i(-10 + viewX3, 430 - viewY3);
	glEnd();

	glColor3ub(255, 0, 0);//head
	glBegin(GL_POLYGON);
	glVertex2i(-10 + viewX3, 420 - viewY3);
	glVertex2i(-10 + viewX3, 430 - viewY3);
	glVertex2i(0 + viewX3, 422 - viewY3);
	glVertex2i(0 + viewX3, 420 - viewY3);
	glEnd();

	glColor3ub(204, 255, 255);//glass
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX3, 425 - viewY3);
	glVertex2i(-10 + viewX3, 425 - viewY3);
	glVertex2i(-10 + viewX3, 428 - viewY3);
	glVertex2i(-22 + viewX3, 437 - viewY3);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2i(-20 + viewX3, 425 - viewY3);
	glVertex2i(-65 + viewX3, 412 - viewY3);
	glVertex2i(-75 + viewX3, 412 - viewY3);
	glVertex2i(-50 + viewX3, 425 - viewY3);
	glEnd();

	delay(1);
	glutTimerFunc(5, delay, 0);
	//glutSwapBuffers();
	glutPostRedisplay();


}

void keyboard(int key, int x, int y) {
	if (key == GLUT_KEY_DOWN) {
		weather();
	}
	if (key == GLUT_KEY_F1) {
		exit(0);
	}
	
	if (key == GLUT_KEY_UP) {

		viewX1 += move_unit;
		viewY1 += move_units;
		plane1();
		viewX1 += 3;
		viewY1 += 3;
		if (viewY1 > 640) {
			viewX1 = 0;
			viewY1 = 0;
		}
		glutPostRedisplay();
	}
	/*
	if (key == GLUT_KEY_RIGHT) {

		viewX2 += move_unit;
		viewY2 += move_units;
		plane2();
		viewX2 += 1;
		viewY2 += 1;
		if (viewX2 > 768) {
			viewX2 = 0;
			viewY2 = 0;
		}
		glutPostRedisplay();
	}*/
	if (key == GLUT_KEY_LEFT) {

		viewX3 += move_unit;
		viewY3 += move_units;
		plane3();
		viewX3 += 3;
		viewY3 += 3;
		//printf("%d\n", viewX3);
		if (viewY3 >= 250) {
			viewY3 = 250;

			if (viewX3 >640) {

				viewX3 = 0;
				viewY3 = 0;
			}



		}

		glutPostRedisplay();
	}
}

void myDisplay(void)
{


	glClear(GL_COLOR_BUFFER_BIT);

	//moon
	glColor3f(1.0, 1.0, 1.0);
	drawCircle(600, 480, 50);

	cloud1();
	cloud2();
	cloud3();
	//buildings
	glColor3f(0.5, 1.0, 0.0);//
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(180, 380);
	glVertex2i(255, 380);
	glVertex2i(255, 440);
	glVertex2i(180, 440);
	glEnd();




	glBegin(GL_POLYGON);
	glVertex2i(180, 370);
	glVertex2i(255, 370);
	glVertex2i(255, 380);
	glVertex2i(180, 380);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(2.0);

	glBegin(GL_POLYGON);
	glVertex2i(200, 390);
	glVertex2i(215, 390);
	glVertex2i(215, 400);
	glVertex2i(200, 400);

	glEnd();
	glBegin(GL_POLYGON);
	glVertex2i(200, 410);
	glVertex2i(215, 410);
	glVertex2i(215, 425);
	glVertex2i(200, 425);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(230, 390);
	glVertex2i(245, 390);
	glVertex2i(245, 400);
	glVertex2i(230, 400);

	glEnd();



	glBegin(GL_POLYGON);
	glVertex2i(230, 410);
	glVertex2i(245, 410);
	glVertex2i(245, 425);
	glVertex2i(230, 425);
	glEnd();



	//middle building first piller//
	glColor3f(0.5, 1.0, 0.0); // middle building
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(180, 350);
	glVertex2i(186, 350);
	glVertex2i(186, 370);
	glVertex2i(180, 370);
	glEnd();

	//first buliding curve
	glBegin(GL_POLYGON);
	glVertex2i(255, 290);
	glVertex2i(265, 290);
	glVertex2i(265, 430);
	glVertex2i(255, 440);
	glEnd();




	//first building last piller//
	glBegin(GL_POLYGON);
	glVertex2i(249, 350);
	glVertex2i(255, 350);
	glVertex2i(255, 370);
	glVertex2i(249, 370);
	glEnd();
	//first building middle piller//
	glBegin(GL_POLYGON);
	glVertex2i(212, 350);
	glVertex2i(218, 350);
	glVertex2i(218, 370);
	glVertex2i(212, 370);
	glEnd();
	//2nd floor first building//
	glBegin(GL_POLYGON);
	glVertex2i(180, 350);
	glVertex2i(180, 340);
	glVertex2i(255, 340);
	glVertex2i(255, 350);
	glEnd();

	//2nd floor first building left piller//
	glBegin(GL_POLYGON);
	glVertex2i(180, 340);
	glVertex2i(186, 340);
	glVertex2i(186, 310);
	glVertex2i(180, 310);
	glEnd();
	//2nd floor first building 2nd pillar right piller//
	glBegin(GL_POLYGON);
	glVertex2i(249, 340);
	glVertex2i(255, 340);
	glVertex2i(255, 310);
	glVertex2i(249, 310);
	glEnd();

	//2nd floor first building 2nd pillar middle piller//
	glBegin(GL_POLYGON);
	glVertex2i(212, 340);
	glVertex2i(218, 340);
	glVertex2i(218, 310);
	glVertex2i(212, 310);
	glEnd();

	//1st floor first building//
	glBegin(GL_POLYGON);
	glVertex2i(180, 310);
	glVertex2i(255, 310);
	glVertex2i(255, 290);
	glVertex2i(180, 290);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);//right building
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(280, 370);
	glVertex2i(355, 370);
	glVertex2i(355, 380);
	glVertex2i(280, 380);

	glEnd();

	//first building first piller//
	glBegin(GL_POLYGON);
	glVertex2i(280, 350);
	glVertex2i(286, 350);
	glVertex2i(286, 370);
	glVertex2i(280, 370);
	glEnd();

	//2nd buliding curve   
	glBegin(GL_POLYGON);
	glVertex2i(369, 290);
	glVertex2i(350, 290);
	glVertex2i(350, 440);
	glVertex2i(369, 430);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(280, 380);
	glVertex2i(350, 380);
	glVertex2i(350, 440);
	glVertex2i(280, 440);
	glEnd();

	glColor3f(1.0, 1.0, 1.0); //windows
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(290, 380);
	glVertex2i(310, 380);
	glVertex2i(310, 400);
	glVertex2i(290, 400);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(290, 420);
	glVertex2i(305, 420);
	glVertex2i(305, 430);
	glVertex2i(290, 430);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(320, 420);
	glVertex2i(335, 420);
	glVertex2i(335, 430);
	glVertex2i(320, 430);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(320, 380);
	glVertex2i(335, 380);
	glVertex2i(335, 400);
	glVertex2i(320, 400);

	glEnd();



	glColor3f(1.0, 0.0, 1.0);
	glPointSize(2.0);
	//first building last piller//
	glBegin(GL_POLYGON);
	glVertex2i(349, 350);
	glVertex2i(355, 350);
	glVertex2i(355, 370);
	glVertex2i(349, 370);
	glEnd();
	//first building middle piller//
	glBegin(GL_POLYGON);
	glVertex2i(312, 350);
	glVertex2i(318, 350);
	glVertex2i(318, 370);
	glVertex2i(312, 370);
	glEnd();
	//2nd floor first building//
	glBegin(GL_POLYGON);
	glVertex2i(280, 350);
	glVertex2i(280, 340);
	glVertex2i(355, 340);
	glVertex2i(355, 350);
	glEnd();

	//2nd floor first building left piller//
	glBegin(GL_POLYGON);
	glVertex2i(280, 340);
	glVertex2i(286, 340);
	glVertex2i(286, 310);
	glVertex2i(280, 310);
	glEnd();
	//2nd floor first building 2nd pillar right piller//
	glBegin(GL_POLYGON);
	glVertex2i(349, 340);
	glVertex2i(355, 340);
	glVertex2i(355, 310);
	glVertex2i(349, 310);
	glEnd();

	//2nd floor first building 2nd pillar middle piller//
	glBegin(GL_POLYGON);
	glVertex2i(312, 340);
	glVertex2i(318, 340);
	glVertex2i(318, 310);
	glVertex2i(312, 310);
	glEnd();

	//1st floor first building//
	glBegin(GL_POLYGON);
	glVertex2i(280, 310);
	glVertex2i(355, 310);
	glVertex2i(355, 290);
	glVertex2i(280, 290);
	glEnd();

	glColor3f(1.0, 0.5, 0.0); // left building
	glPointSize(2.0);

	glBegin(GL_POLYGON);
	glVertex2i(80, 370);
	glVertex2i(155, 370);
	glVertex2i(155, 380);
	glVertex2i(80, 380);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(155, 290);
	glVertex2i(175, 290);
	glVertex2i(175, 370);
	glVertex2i(155, 380);

	glEnd();
	//first building first piller//
	glBegin(GL_POLYGON);
	glVertex2i(80, 350);
	glVertex2i(86, 350);
	glVertex2i(86, 370);
	glVertex2i(80, 370);

	glEnd();

	//first building last piller//
	glBegin(GL_POLYGON);
	glVertex2i(149, 350);
	glVertex2i(155, 350);
	glVertex2i(155, 370);
	glVertex2i(149, 370);
	glEnd();
	//first building middle piller//
	glBegin(GL_POLYGON);
	glVertex2i(112, 350);
	glVertex2i(118, 350);
	glVertex2i(118, 370);
	glVertex2i(112, 370);
	glEnd();
	//2nd floor first building//
	glBegin(GL_POLYGON);
	glVertex2i(80, 350);
	glVertex2i(80, 340);
	glVertex2i(155, 340);
	glVertex2i(155, 350);
	glEnd();

	//2nd floor first building left piller//
	glBegin(GL_POLYGON);
	glVertex2i(80, 340);
	glVertex2i(86, 340);
	glVertex2i(86, 310);
	glVertex2i(80, 310);
	glEnd();
	//2nd floor first building 2nd pillar right piller//
	glBegin(GL_POLYGON);
	glVertex2i(149, 340);
	glVertex2i(155, 340);
	glVertex2i(155, 310);
	glVertex2i(149, 310);
	glEnd();

	//2nd floor first building 2nd pillar middle piller//
	glBegin(GL_POLYGON);
	glVertex2i(112, 340);
	glVertex2i(118, 340);
	glVertex2i(118, 310);
	glVertex2i(112, 310);
	glEnd();

	//1st floor first building//
	glBegin(GL_POLYGON);
	glVertex2i(80, 310);
	glVertex2i(155, 310);
	glVertex2i(155, 290);
	glVertex2i(80, 290);
	glEnd();


	//tree from left sight
	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(40, 270);
	glVertex2i(60, 270);
	glVertex2i(60, 275);
	glVertex2i(40, 275);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(45, 275);
	glVertex2i(55, 275);
	glVertex2i(55, 290);
	glVertex2i(45, 290);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(60, 290);
	glVertex2i(50, 350);
	glVertex2i(40, 290);
	glEnd();

	//tst tree end

	//2nd tree 

	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(240, 270);
	glVertex2i(260, 270);
	glVertex2i(260, 275);
	glVertex2i(240, 275);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(245, 275);
	glVertex2i(255, 275);
	glVertex2i(255, 290);
	glVertex2i(245, 290);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(260, 290);
	glVertex2i(250, 350);
	glVertex2i(240, 290);
	glEnd();



	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(140, 270);
	glVertex2i(160, 270);
	glVertex2i(160, 275);
	glVertex2i(140, 275);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(145, 275);
	glVertex2i(155, 275);
	glVertex2i(155, 290);
	glVertex2i(145, 290);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(160, 290);
	glVertex2i(150, 350);
	glVertex2i(140, 290);
	glEnd();

	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(340, 270);
	glVertex2i(360, 270);
	glVertex2i(360, 275);
	glVertex2i(340, 275);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(345, 275);
	glVertex2i(355, 275);
	glVertex2i(355, 290);
	glVertex2i(345, 290);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(360, 290);
	glVertex2i(350, 350);
	glVertex2i(340, 290);
	glEnd();

	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(440, 270);
	glVertex2i(460, 270);
	glVertex2i(460, 275);
	glVertex2i(440, 275);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(445, 275);
	glVertex2i(455, 275);
	glVertex2i(455, 290);
	glVertex2i(445, 290);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(460, 290);
	glVertex2i(450, 350);
	glVertex2i(440, 290);
	glEnd();


	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(540, 270);
	glVertex2i(560, 270);
	glVertex2i(560, 275);
	glVertex2i(540, 275);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(545, 275);
	glVertex2i(555, 275);
	glVertex2i(555, 290);
	glVertex2i(545, 290);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(560, 290);
	glVertex2i(550, 350);
	glVertex2i(540, 290);
	glEnd();


	//tree end



	//Road Runway
	//Road
	glColor3f(0.32, 0.32, 0.32);
	glPointSize(2.0);


	glBegin(GL_POLYGON);
	glVertex2i(0, 120);
	glVertex2i(640, 120);
	glVertex2i(640, 270);
	glVertex2i(0, 270);
	glEnd();

	//glutSwapBuffers();

	//runway border
	glColor3f(1.0, 1.0, 0.0);
	glPointSize(2.0);

	glBegin(GL_POLYGON);
	glVertex2i(0, 190);
	glVertex2i(50, 190);
	glVertex2i(50, 200);
	glVertex2i(0, 200);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(70, 190);
	glVertex2i(120, 190);
	glVertex2i(120, 200);
	glVertex2i(70, 200);

	glEnd();


	glBegin(GL_POLYGON);
	glVertex2i(140, 190);
	glVertex2i(190, 190);
	glVertex2i(190, 200);
	glVertex2i(140, 200);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(210, 190);
	glVertex2i(260, 190);
	glVertex2i(260, 200);
	glVertex2i(210, 200);

	glEnd();


	glBegin(GL_POLYGON);
	glVertex2i(280, 190);
	glVertex2i(330, 190);
	glVertex2i(330, 200);
	glVertex2i(280, 200);

	glEnd();




	glBegin(GL_POLYGON);
	glVertex2i(350, 190);
	glVertex2i(400, 190);
	glVertex2i(400, 200);
	glVertex2i(350, 200);

	glEnd();


	glBegin(GL_POLYGON);
	glVertex2i(420, 190);
	glVertex2i(470, 190);
	glVertex2i(470, 200);
	glVertex2i(420, 200);

	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(490, 190);
	glVertex2i(540, 190);
	glVertex2i(540, 200);
	glVertex2i(490, 200);

	glEnd();



	glBegin(GL_POLYGON);
	glVertex2i(560, 190);
	glVertex2i(610, 190);
	glVertex2i(610, 200);
	glVertex2i(560, 200);

	glEnd();


	glBegin(GL_POLYGON);
	glVertex2i(630, 190);
	glVertex2i(680, 190);
	glVertex2i(680, 200);
	glVertex2i(630, 200);

	glEnd();

	//River

	glColor3ub(135, 206, 255);
	glPointSize(2.0);


	glBegin(GL_POLYGON);
	glVertex2i(0, 0);
	glVertex2i(640, 0);
	glVertex2i(640, 70);
	glVertex2i(0, 70);

	glEnd();

	//boat 
	boat();




	//plane
	plane1();
	//delay(1000);
	plane2();
	plane3();

	glutPostRedisplay();


	// river sight tree from left sight
	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(40, 70);
	glVertex2i(60, 70);
	glVertex2i(60, 75);
	glVertex2i(40, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(45, 75);
	glVertex2i(55, 75);
	glVertex2i(55, 90);
	glVertex2i(45, 90);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(60, 90);
	glVertex2i(50, 150);
	glVertex2i(40, 90);
	glEnd();

	//tst tree end

	//2nd tree 

	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(240, 70);
	glVertex2i(260, 70);
	glVertex2i(260, 75);
	glVertex2i(240, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(245, 75);
	glVertex2i(255, 75);
	glVertex2i(255, 90);
	glVertex2i(245, 90);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(260, 90);
	glVertex2i(250, 150);
	glVertex2i(240, 90);
	glEnd();



	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(140, 70);
	glVertex2i(160, 70);
	glVertex2i(160, 75);
	glVertex2i(140, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(145, 75);
	glVertex2i(155, 75);
	glVertex2i(155, 90);
	glVertex2i(145, 90);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(160, 90);
	glVertex2i(150, 150);
	glVertex2i(140, 90);
	glEnd();

	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(340, 70);
	glVertex2i(360, 70);
	glVertex2i(360, 75);
	glVertex2i(340, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(345, 75);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(345, 90);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(360, 90);
	glVertex2i(350, 150);
	glVertex2i(340, 90);
	glEnd();

	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(440, 70);
	glVertex2i(460, 70);
	glVertex2i(460, 75);
	glVertex2i(440, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(445, 75);
	glVertex2i(455, 75);
	glVertex2i(455, 90);
	glVertex2i(445, 90);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(460, 90);
	glVertex2i(450, 150);
	glVertex2i(440, 90);
	glEnd();


	glColor3ub(139, 69, 16);
	glPointSize(2.0);
	glBegin(GL_POLYGON);
	glVertex2i(540, 70);
	glVertex2i(560, 70);
	glVertex2i(560, 75);
	glVertex2i(540, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(545, 75);
	glVertex2i(555, 75);
	glVertex2i(555, 90);
	glVertex2i(545, 90);
	glEnd();

	glColor3ub(0, 139, 0);
	glBegin(GL_POLYGON);
	glVertex2i(560, 90);
	glVertex2i(550, 150);
	glVertex2i(540, 90);
	glEnd();


	//tree end river side


	glFlush();
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Airport View");
	glutDisplayFunc(myDisplay);
	glutSpecialFunc(keyboard);
	myInit();
	glutTimerFunc(10, delay, 1000);
	glutMainLoop();
}