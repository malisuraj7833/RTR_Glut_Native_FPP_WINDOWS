#include <GL/freeglut.h>
#include<math.h>

#define PI 3.1415926535898

//global variable declaration
bool bFullscreen = false; //variable to toggle for fullscreen

int main(int argc, char** argv)
{
	//function prototypes
	void display(void);
	void resize(int, int);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void initialize(void);
	void uninitialize(void);

	//code
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowSize(800, 600); //to declare initial window size
	glutInitWindowPosition(100, 100); //to declare initial window position
	glutCreateWindow("OpenGL First Window : Graph paper"); //open the window with "OpenGL First Window : Hello World" in the title bar

	initialize();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	//	return(0); 
}

void display(void)
{

	void drawAxisLines();
	void drawGrid();
	void drawTriangle();
	void drawRectangle();
	void drawCircle(GLenum);

	//to clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	drawAxisLines();
	drawGrid();
	drawTriangle();
	drawRectangle();
	drawCircle(GL_LINE_LOOP);

	//to process buffered OpenGL Routines
	//glFlush();
	glutSwapBuffers();
}

void drawAxisLines()
{
	// red horizontal line
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glEnd();

	// green vertical line
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glEnd();
}
void drawGrid()
{
	// above horizontal 20 lines
	float i = 0;
	for (i = 0.05f;i <= 1.0f; i = i + 0.05f)
	{
		glLineWidth(1.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex3f(1.0f, i, 0.0f);
		glVertex3f(-1.0f, i, 0.0f);
		glEnd();
	}

	// below horizontal 20 lines
	float j = 0;
	for (j = -0.05f; j >= -1.0f; j = j + (-0.05f))
	{
		glLineWidth(1.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex3f(1.0f, j, 0.0f);
		glVertex3f(-1.0f, j, 0.0f);
		glEnd();
	}

	// right side vertical 20 lines
	float k = 0;
	for (k = 0.05f;k <= 1.0f; k = k + 0.05f)
	{
		glLineWidth(1.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex3f(k, 1.0f, 0.0f);
		glVertex3f(k, -1.0f, 0.0f);
		glEnd();
	}

	// left side vertical 20 lines
	float l = 0.0;
	for (l = -0.05f; l >= -1.0f; l = l + (-0.05f))
	{
		glLineWidth(1.0f);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 1.0f);

		glVertex3f(l, 1.0f, 0.0f);
		glVertex3f(l, -1.0f, 0.0f);
		glEnd();
	}
}
void drawTriangle()
{
	// yellow bordered triangle
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0f, 0.0f);

	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);

	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);

	glEnd();
}
void drawRectangle()
{
	// yellow bordered sqaure
	glBegin(GL_LINES);
	glLineWidth(1.0f);
	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glVertex3f(-0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.0f);

	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);

	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);

	glEnd();
}
void drawCircle(GLenum type)
{
	// drawing  of a circle using GL_POINTS
	float angle;
	if (type == GL_POINTS)
	{
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 0.0f);
		for (angle = 0.0f; angle < 2.0f * PI ;angle = angle + 0.001f)
		{
			glVertex3f(cos(angle), sin(angle), 0.0f);
		}
		glEnd();
	}
	else
		if (type == GL_LINE_LOOP)
		{
			glBegin(GL_LINE_LOOP); //GL_LINES will also do
			GLint circle_points = 100000; //you can try using 1000 or 10000

			for (int i = 0; i < circle_points; i++)
			{
				angle = 2 * PI * i / circle_points;

				glVertex2f(cos(angle), sin(angle));

			}
			glEnd();
		}
}

void initialize(void)
{
	//code
	//to select clearing (background) clear
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //blue 
}

void keyboard(unsigned char key, int x, int y)
{
	//code
	switch (key)
	{
	case 27: // Escape
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bFullscreen == false)
		{
			glutFullScreen();
			bFullscreen = true;
		}
		else
		{
			glutLeaveFullScreen();
			bFullscreen = false;
		}
		break;
	default:
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	//code
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		break;
	default:
		break;
	}
}

void resize(int width, int height)
{
	// code
	if (height == 0)
	{
		height = 1;
	}
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void uninitialize(void)
{
	// code
}

