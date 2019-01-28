/*****************************************************************************
		FILE : submit.c (Assignment 1)
		NOTE : you have to implement functions in this file
*****************************************************************************/
/*****************************************************************************
		Student Information
		Student ID: 1616120312
		Student Name: Ren Shuai Chen
*****************************************************************************/

#include <stdlib.h>
#include <gl\glut.h>
#include<math.h>
const GLdouble FRUSTDIM = 100.0f;

int option = 0, i = 0;
bool enableLight = 1;

/* Do  animation*/
GLfloat angle = 0, board_pos = 65;
GLfloat catinet = 150,circle_ro=0, circle_ro1 = 0,windows_tr=-20,lightsize=6, donut_size = 10;
GLUquadricObj *quadobj;
float PI = 3.1415926f;

/* For lighting*/
GLfloat light0pos[] = { 0.0f, 76.f, 0.f, 0.f };
GLfloat light0_mat1[] = { 1.0, 1.0, 1.0, 1.f };
GLfloat light0_diff[] = { 1.0, 1.0, 1.0, 0.3 };

void init(void) // All Setup For OpenGL Goes Here 
{
	/* Light 0 Settings */

	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);

	quadobj = gluNewQuadric();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);		/* Define Counter-Clockwise as front face */
	glEnable(GL_COLOR_MATERIAL);
}

void display(void) // Here's Where We Do All The Drawing
{
	/* Clear the buffer */
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glLoadIdentity();
	//gluLookAt(10.0, 10.0,50, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(0, 0, -540);
	/* Initialize material properties */
	GLfloat no_mat[] = { 0.0,0.0,0.0,1.0 };
	GLfloat mat_diffuse[] = { 0.9,0.9,0.9,1.0 };
	GLfloat mat_specular[] = { 0.3,0.3,0.3,1.0 };
	GLfloat high_shininess[] = { 20.0 };
	GLfloat high_mat[] = { 1.0,1.0,1.0,1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);


	/* Draw a Table START */
	glPushMatrix();
	glTranslatef(0.f, 0.f, 70.f);

	/*bed*/
	glPushMatrix();
	glColor4f(0.8f, 0.8f, 0.3f, 0.5f);
	glTranslatef(-45.f, -60.f, 65.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(20.f, 50.0f, 200.f);
	glutSolidCube(1.f);
	glPopMatrix();
	glPushMatrix();
	glColor4f(1.f, 1.f, 0.2f, 0.1f);
	glTranslatef(-45.f, -45.f, 85.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(10.f, 40.0f, 40.f);
	glutSolidCube(0.8f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.4f, 0.20f, 0.f);
	glTranslatef(30.f, donut_size-80, 250.f);
	glRotatef(-90.f, 1.f, 0.f, 0.f);
	glutSolidTorus(donut_size - 1, donut_size, 110.f, 110.f);
	glPopMatrix();

	/*cabiner*/
	glPushMatrix();
	glColor4f(1.f, 1.f, 0.2f, 0.1f);
	glTranslatef(30.f, -55.f, 150.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(20.f,70.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.2f, 0.2f, 0.f, 0.1f);
	glTranslatef(25.f, -50.f, 200.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(10.f, 20.0f, 10.f);
	glutSolidCube(0.3f);
	glPopMatrix();
	glPushMatrix();
	glColor4f(0.2f, 0.2f, 0.f, 0.1f);
	glTranslatef(26.5f, -40.f, catinet+50);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(2.f, 78.0f, 10.f);
	glutSolidCube(0.8f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.f, 1.f, 0.2f, 0.1f);
	glTranslatef(30.f, -35.f, catinet);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(20.f, 70.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.2f, 0.2f, 0.f, 0.1f);
	glTranslatef(25.f, -32.f, catinet+50);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(10.f, 20.0f, 10.f);
	glutSolidCube(0.3f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.2f, 0.2f, 0.f, 0.1f);
	glTranslatef(26.5f, -20.f, 200.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(5.f, 80.0f,10.f);
	glutSolidCube(0.8f);
	glPopMatrix();

	//glPushMatrix();
	//glColor4f(0.8f, 0.8f, 0.3f, 0.5f);
	//glTranslatef(20.f, -60.f, 65.f);
	//glRotatef(90.f, 0.f, 0.f, 30.f);
	//glScalef(20.f, 100.0f, 80.f);
	//glutSolidCube(1.f);
	//glPopMatrix();

	/*Draw Light bulb START*/
	glPushMatrix();
	glColor4f(0.4f, 0.5f, 0.7f, 1.f);
	glTranslatef(0.f, 95.f, 50);
	glRotatef(70.0f, 1.0f, 0.0f, 0.f);
	glutSolidTorus(6, 15, 110.f, 110.f);
	glPopMatrix();
	/*Draw Light bulb END*/
	/*clock*/

	glPushMatrix();
	glTranslatef(-40.f, 20.f, 40);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(0.54, 0., 0.78, 1);
	int n = 360;
	for (int i = 0; i < n; i++)
	{
		glVertex2f(20*cos(2 * PI*i / n), 20*sin(2 * PI*i / n)); 
	}
	glEnd();
	glPopMatrix();

	glBegin(GL_LINES);
	glLineWidth(100.0);
	glColor3f(255.f, 255.f, 0.0f);
	glVertex3f(-38, 14, 200);
	glVertex3f(-40,14, 200);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(100.0);
	glColor3f(255.f, 255.f, 0.0f);
	glVertex3f(-14,14, 200);
	glVertex3f(-16,14, 200);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(100.0);
	glColor3f(255.f, 255.f, 0.0f);
	glVertex3f(-27,27, 200);
	glVertex3f(-27, 25, 200);
	glEnd();
		
	glBegin(GL_LINES);
	glColor3f(255.f, 255.f, 0.0f);
	glVertex3f(-27, 0, 200);
	glVertex3f(-27, 2, 200);
	glEnd();
	//glBegin(GL_LINES);
	//glColor3f(0.0, 0.0, 0.0);
	//glVertex3f(-80.0, 80.0, -200);
	//glVertex3f(-80.0, -30.0, -200);
	//glVertex3f(80.0, -30.0, -200);
	//glVertex3f(80.0, 80.0, -200);
	//glVertex3f(80.0, -30.0, -200);
	//glVertex3f(-80.0, -30.0, -200);
	//glEnd();
	glPushMatrix();
	glTranslated(-27, 14, 0);
	glRotated(-(circle_ro+90),0,0,1);
	glBegin(GL_LINES);
	glColor3f(255.f, 255.f, 0.0f);
	glVertex3f(0, 0, 200);
	glVertex3f(0, -9, 200);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-27, 14, 0);
	glRotated(-(circle_ro/60), 0, 0, 1);
	glBegin(GL_LINES);
	glColor3f(255.f, 255.f, 0.0f);
	glVertex3f(0, 0, 200);
	glVertex3f(0, -4, 200);
	glEnd();
	glPopMatrix();

	/*windows*/
	glPushMatrix();
	glColor4f(0.2f, 0.2f, 0.f, 0.1f);
	glTranslatef(25.f, -10.f, 200.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(2.f, 60.0f, 10.f);
	glutSolidCube(0.8f);
	glPopMatrix();
	
	glPushMatrix();
	glColor4f(0.2f, 0.2f, 0.f, 0.1f);
	glTranslatef(25.f, 30.f, 200.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(1.f, 50.0f, 10.f);
	glutSolidCube(0.8f);
	glPopMatrix();
	
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.9f, 0.2f, 0.6f);
	glVertex3f(12.0f, 63.0f, -199.5f);	
	glVertex3f(12.0f,windows_tr, -199.5f);
	glVertex3f(97.0f, windows_tr, -199.5f);
	glVertex3f(97.0f, 63.0f, -199.5f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(55.f, 63.0f, -199.0f);
	glVertex3f(55.f, windows_tr, -199.0f);
	glEnd();

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(30.f, 63.0f, -199.0f);
	glVertex3f(30.f, windows_tr, -199.0f);
	glEnd();

	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.f, 1.f, 0.f);
	glVertex3f(80.f, 63.0f, -199.0f);
	glVertex3f(80.f, windows_tr, -199.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.f, 0.12f, 2.f);
	
	glVertex3f(12.0f, 63.0f, -199.8f);
	glVertex3f(12.0f, -20, -199.8f);
	glVertex3f(97.0f, -20, -199.8f);
	glVertex3f(97.0f, 63.0f, -199.8f);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(80.f, 40.f, -199.7f);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(100, 100, 100, 1);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(12 * cos(2 * PI*i / n), 12 * sin(2 * PI*i / n));
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(27.f, 52.f, -199.7f);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(100, 100, 100, 1);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(1 * cos(2 * PI*i / n), 1 * sin(2 * PI*i / n));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(64.f, 25.f, -199.7f);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(100, 100, 100, 1);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(1 * cos(2 * PI*i / n), 1 * sin(2 * PI*i / n));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(20.f, 20.f, -199.7f);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(100, 100, 100, 1);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(1 * cos(2 * PI*i / n), 1 * sin(2 * PI*i / n));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(40.f, 40.f, -199.7f);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(100, 100, 100, 1);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(1 * cos(2 * PI*i / n), 1 * sin(2 * PI*i / n));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(30.f,20.f, -199.7f);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(100, 100, 100, 1);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(1 * cos(2 * PI*i / n), 1 * sin(2 * PI*i / n));
	}
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(20.f, 40.f, -199.7f);
	glRotated(circle_ro1, 0, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(100, 100, 100, 1);
	for (int i = 0; i < n; i++)
	{
		glVertex2f(1 * cos(2 * PI*i / n), 1 * sin(2 * PI*i / n));
	}
	glEnd();
	glPopMatrix();
	
	/* Draw the wall START */
	/* Back wall */
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 1.0f, 0.4f);
	glVertex3f(-110.0f, 110.0f, -200.0f);
	glColor3f(0.1f, 0.7f, 0.7f);
	glVertex3f(-110.0f, -110.0f, -200.0f);
	glColor3f(0.2f, 0.8f, 0.7f);
	glVertex3f(110.0f, -110.0f, -200.0f);
	glColor3f(0.1f, 1.0f, 0.4f);
	glVertex3f(110.0f, 110.0f, -200.0f);
	glEnd();

	/* Top wall */
	glBegin(GL_POLYGON);
	glColor3f(0.6f, 0.9f, 0.89f);
	//glColor3f(0.93f, 1.0f, 0.7f);
	glVertex3f(-80.0f, 80.0f ,0.0f);
	glVertex3f(80.0f, 80.0f, 0.0f);
	glVertex3f(190.0f, 190.0f, 0.0f);
	
	glVertex3f(-190.0f, 190.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	/* Bottom wall */
	glColor3f(0.1f, 1.0f, 1.1f);
	glVertex3f(80.f, -80.f, 0.f);
	glVertex3f(-80.f, -80.f, 0.9f);
	glColor3f(0.89f, 0.88f, 0.7f);
	glVertex3f(-190.f, -190.f, 0.f);
	glVertex3f(190.f, -190.f, 0.f);

	/* Right wall */
	glColor3f(0.9f, 0.87f, 0.9f);
	glVertex3f(190.0f, 190.0f, 0.0f);
	glColor3f(0.1f, 1.0f, 0.5f);
	glVertex3f(80.0f, 80.0f, 0.0f);
	glColor3f(0.1f, 1.0f, 0.4f);
	glVertex3f(80.0f, -80.0f, 0.0f);
	glColor3f(1.f, 1.f, 1.f); glColor3f(0.7f, 0.7f, 0.7f); glVertex3f(190.0f, -190.0f, 0.0f);

	/* Left wall */
	glColor3f(0.9f, 0.87f, 0.9f);
	glVertex3f(-190.0f, 190.0f, 0.0f);
	glColor3f(0.1f, 1.0f, 0.5f);
	glVertex3f(-80.0f, 80.0f, 0.0f);
	glColor3f(0.1f, 1.0f, 0.4f);
	glVertex3f(-80.0f, -80.0f, 0.0f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-190.0f, -190.0f, 0.0f);
	glEnd();
	/* Draw the wall END */
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.f, 84.f, 200);
	glScalef(40,60,150);
	glutSolidCube(1);
	glPopMatrix();

	glutSwapBuffers();
	glFlush();

	/* Refresh the frame */
	glutPostRedisplay();
}

void reshape(int w, int h) // Resize the GL Window. w=width, h=height
{
	//	winWidth = w; winHeight = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Frustum Setting
	glFrustum(-FRUSTDIM, FRUSTDIM, -FRUSTDIM, FRUSTDIM, 300., 800.);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluLookAt(50.0, 0.0, 15.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) // Handle the keyboard events here
{
	switch (key)
	{
	case '\033':
		exit(0);
		break;
	case 'p': /*pause*/
		option = 1;
		break;

	case '1': /*decrease light*/
		if (enableLight)
			if (light0_mat1[0] >= 0) {
				for (i = 0; i <= 3; i++) {
					light0_mat1[i] -= 0.01;
					light0_diff[i] -= 0.01;
				}
				glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);
				glEnable(GL_LIGHT0);
			}
		break;

	case '2': /*increase light*/
		if (enableLight)
			if (light0_mat1[0] <= 1) {
				for (i = 0; i <= 3; i++) {
					light0_mat1[i] += 0.01;
					light0_diff[i] += 0.01;
				}
				glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);
				glEnable(GL_LIGHT0);
			}
		break;

	case 'z': /*switch on/off the light*/
		option = 4;
		break;
	case '4':
		option = 2;
		break;
	case '5':
		option = 3;
		break;
	case '6':
		option = 5;
		break;
	case '7':
		option = 6;
		break;
	case 'q':
		option = 7;
		break;
	case 'w':
		option = 8;
		break;
	case 'e':
		option = 9;
		break;
	case 'r':
		option = 10;
		break;
	}
}

void idle()
{
	if (circle_ro <= 10000)
	{
		circle_ro += 0.05;
	}
	if (option == 1)
	{

	}
	else if (option == 2)	/* Anti-clockwise */
	{
		if (angle >= 360)
			angle = 0;
		angle++;
	}
	else if (option == 3)	/* Clockwise */
	{
		if (angle <= -360)
			angle = 0;
		angle--;
	}
	else if (option == 4)
	{
		if (enableLight)
		{
			enableLight = 0;
			for (i = 0; i <= 3; i++) {
				light0_mat1[i] = 0.0;
			}
			glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
			glDisable(GL_LIGHT0);
			option = 1;
		}
		else
		{
			enableLight = 1;
			for (i = 0; i <= 3; i++) {
				light0_diff[i] = 1.0;
				light0_mat1[i] = 1.0;
			}
			glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);
			glEnable(GL_LIGHT0);
			option = 1;
		}
	}
	else if (option == 5)
	{
		if (windows_tr>=-20 && enableLight == 0)
			windows_tr -= 0.2;
	}
	else if (option == 6)
	{
		if (windows_tr<=63&&enableLight==0)
			windows_tr += 0.2;
	}
	else if (option == 7)
	{
		if (donut_size<17)
			donut_size += 1;
	}

	else if (option == 8)
	{
		if (donut_size>= 10)
			donut_size -= 1;
	}

	else if (option == 9)
	{
		if (catinet <= 180)
			catinet+= 1;
	}
	else if (option == 10)
	{
		if (catinet >=150)
			catinet -= 1;
	}
	else {}
}


void main(int argc, char** argv)
{

	/* Initialization of GLUT Library */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	/* Create a window with title specified */
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Assignment 1: Creating a 3D Room");

	init();	/* not GLUT call, initialize several parameters */

	/* Register different CALLBACK function for GLUT to response
	 * with different events, e.g. window sizing, mouse click or
	 * keyboard stroke*/
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	/*Enter the GLUT event processing loop which never returns.
	it will call different registered CALLBACK according
	to different events. */
	glutMainLoop();
}