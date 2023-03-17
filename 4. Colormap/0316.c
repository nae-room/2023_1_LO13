// 빨간색에서 시작해서 파란색까지 그라데이션인 원

#include <stdlib.h>
#include "GUI.h"

#define pi 3.1415956

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // use color

	double theta = 2 * pi / 128;

	glBegin(GL_TRIANGLES); // i want to draw something
		for(int i=0; i<128; i++)
		{
		    float color = (float)i/127; // i�� int ���ε� color�� �鳯 �ݿø� �غ��� ���� ����
            glColor3f(1-color, 0, color);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));

		}
	glEnd();

	glFlush();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // ���� ���� RGB (������)

	glColor3f(1.0, 1.0, 1.0); // �׸��� ���� (�Ͼ��)

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // important ��ǥ�� �缳��

}

int main(int argc, char **argv)
{
	// 1�ܰ� init �ϱ�
	glutInit(&argc, argv);

	// 2�ܰ� ������ â �����
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("LO13_Kim Da-Yeon");

	// 3�ܰ�
	init();

	// 4�ܰ�
	glutDisplayFunc(display);

	// 5�ܰ�
	glutMainLoop();
	return (0);
}