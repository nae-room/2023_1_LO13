#include <stdlib.h>
#include <malloc.h>
#include "GUI.h"

#define pi 3.1415956

typedef struct mesh
{
    int nv;
    float *vertics;
    int nt;
    int *triangle;
} Mesh;

Mesh msh;

void init(void)
{
    glClearColor(0.0 , 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0 ,1.0);
}

void Geometry(void)
{
    msh.nv = 8;
    msh.vertics = (float *) malloc(msh.nv*3*sizeof(float));
    msh.vertics[0] = 0.0;
    msh.vertics[1] = 0.0;
    msh.vertics[2] = 0.0;

    msh.vertics[3] = 1.0;
    msh.vertics[4] = 0.0;
    msh.vertics[5] = 0.0;

    msh.vertics[6] = 1.0;
    msh.vertics[7] = 1.0;
    msh.vertics[8] = 0.0;

    msh.vertics[9] = 0.0;
    msh.vertics[10] = 1.0;
    msh.vertics[11] = 0.0;

    msh.vertics[12] = 0.0;
    msh.vertics[13] = 0.0;
    msh.vertics[14] = 1.0;

    msh.vertics[15] = 1.0;
    msh.vertics[16] = 0.0;
    msh.vertics[17] = 1.0;

    msh.vertics[18] = 1.0;
    msh.vertics[19] = 1.0;
    msh.vertics[20] = 1.0;

    msh.vertics[21] = 0.0;
    msh.vertics[22] = 1.0;
    msh.vertics[23] = 1.0;

    msh.nt = 12;
    msh.triangle = (int *) malloc(msh.nt*3*sizeof(int));
    msh.triangle[0] = 2;
    msh.triangle[1] = 3;
    msh.triangle[2] = 6;

    msh.triangle[3] = 3;
    msh.triangle[4] = 7;
    msh.triangle[5] = 6;

    msh.triangle[6] = 3;
    msh.triangle[7] = 4;
    msh.triangle[8] = 7;

    msh.triangle[9] = 4;
    msh.triangle[10] = 8;
    msh.triangle[11] = 7;

    msh.triangle[12] = 4;
    msh.triangle[13] = 1;
    msh.triangle[14] = 8;

    msh.triangle[15] = 1;
    msh.triangle[16] = 5;
    msh.triangle[17] = 8;

    msh.triangle[18] = 1;
    msh.triangle[19] = 2;
    msh.triangle[20] = 5;

    msh.triangle[21] = 2;
    msh.triangle[22] = 6;
    msh.triangle[23] = 5;

    msh.triangle[24] = 5;
    msh.triangle[25] = 6;
    msh.triangle[26] = 7;

    msh.triangle[27] = 7;
    msh.triangle[28] = 8;
    msh.triangle[29] = 5;

    msh.triangle[30] = 3;
    msh.triangle[31] = 2;
    msh.triangle[32] = 1;

    msh.triangle[33] = 1;
    msh.triangle[34] = 4;
    msh.triangle[35] = 3;
}

void ViewMatrix(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4, 3, 3, 0.5, 0.5, 0.5, 0, 0, 1);
}

void ProjectionMatrix(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-0.5, 0.5, -0.5, 0.5, 1.0, 100.0);
}

void DrawObject(void)
{
    int i, j, s;

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);
    for(i=1; i<=msh.nt; i++)
    {
        for(j=0; j<=2; j++)
        {
            glColor3f(1.0, 1.0, 1.0);
            s = msh.triangle[3*(i-1)+j];
            glVertex3f(msh.vertics[3*(s-1)], msh.vertics[3*(s-1)+1],msh.vertics[3*(s-1)+2]);
        }
    }
    glEnd();
}

void PutScreen(void)
{
    glFlush();
}

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    ViewMatrix();
    ProjectionMatrix();

    DrawObject();
    PutScreen();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    Geometry();

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("LO13_Kim Da-Yeon");

    init();

    glutDisplayFunc(Display);

    glutMainLoop();
    return 0;
}
