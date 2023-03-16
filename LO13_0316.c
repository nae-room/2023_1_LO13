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
		    float color = (float)i/127; // i가 int 형인데 color에 백날 반올림 해봐야 뭐함 ㅋㅋ
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
	glClearColor(0.0, 0.0, 0.0, 0.0); // 배경색 설정 RGB (검은색)

	glColor3f(1.0, 1.0, 1.0); // 그릴색 선택 (하얀색)

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // important 좌표값 재설정

}

int main(int argc, char **argv)
{
	// 1단계 init 하기
	glutInit(&argc, argv);

	// 2단계 윈도우 창 만들기
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("LO13_Kim Da-Yeon");

	// 3단계
	init();

	// 4단계
	glutDisplayFunc(display);

	// 5단계
	glutMainLoop();
	return (0);
}
