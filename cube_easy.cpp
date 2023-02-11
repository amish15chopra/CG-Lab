#include <GL/glut.h>


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_QUADS);
	// Draw the cube
	glColor3f(1.0, 1.0, 0.0); // Yellow
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);

	glColor3f(1.0, 0.0, 1.0); // Magenta
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);

	glColor3f(1.0, 1.0, 1.0); // White
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);

	glColor3f(1.0, 0.0, 0.0); // Red
	glVertex3f(1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);

	glColor3f(0.0, 0.0, 1.0); // Blue
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);

	glColor3f(0.0, 1.0, 0.0); // Green
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void idle() {
	glRotatef(.01, 1, 0, 0);
	glRotatef(.02, 0, 1, 0);
	glRotatef(.03, 0, 0, 1);
	glutPostRedisplay();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
}

void myInit() {
	glEnable(GL_DEPTH_TEST);
	gluPerspective(80, 1, .1, 10);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0, 0, -6);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cube Spin");

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);

	myInit();
	glutMainLoop();
}
