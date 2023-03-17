// Write the code to have a linear progression of colors from the angle 0 to 2π like in Figure 4
// 그라데이션 원 만들기

#include <stdlib.h>
#include "GUI.h"

#define pi 3.1415956

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // use color

	double theta = 2 * pi / 128;

	glBegin(GL_TRIANGLES); // i want to draw something
        float red, green, blue;
		for(int i=0; i<16; i++){
            red=0;
            green=0;
            blue=(float)i/16;
            glColor3f(red, green, blue);
            glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));
		}

        for(int i=16; i<32; i++){
            red=0;
            green=(float)i/16-1;
            blue=1;
            glColor3f(red, green, blue);
            glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));
		}

        for(int i=32; i<48; i++){
            red=(float)i/16-2;
            green=1;
            blue=1;
            glColor3f(red, green, blue);
            glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));
		}

		for(int i=48; i<64; i++){
            red=1;
            green=4-(float)i/16;
            blue=1;
            glColor3f(red, green, blue);
            glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));
		}

		for(int i=64; i<80; i++){
            red=1;
            green=0;
            blue=5-(float)i/16;
            glColor3f(red, green, blue);
            glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));
		}

		for(int i=80; i<96; i++){
            red=1;
            green=(float)i/16-5;
            blue=0;
            glColor3f(red, green, blue);
            glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));
		}

		for(int i=96; i<112; i++){
            red=7-(float)i/16;
            green=1;
            blue=0;
            glColor3f(red, green, blue);
            glVertex2f(0.0, 0.0);
			glVertex2f(0.5*cos(theta*i), 0.5*sin(theta*i));
			glVertex2f(0.5*cos(theta*(i+1)), 0.5*sin(theta*(i+1)));
		}

		for(int i=112; i<128; i++){
            red=0;
            green=8-(float)i/16;
            blue=0;
            glColor3f(red, green, blue);
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
