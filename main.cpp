#include<stdio.h>
#include<GL/freeglut.h>

int main (int argc, char** argv)
{
    void initialize();
    void RenderSceneCB();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    const int init_win_size_width = 640;
    const int init_win_size_height = 480;
    glutInitWindowSize(init_win_size_width, init_win_size_height);

    const int init_win_pos_x = 100;
    const int init_win_pos_y = 100;
    glutInitWindowPosition(init_win_pos_x, init_win_pos_y);

    glutCreateWindow("Creating shapes >>>");

    initialize();

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();
    return 0;
}

void initialize ()
{
    GLclampf Red = 1.0f, Green = 1.0f, Blue = 1.0f, Alpha = 1.0f;
    glClearColor(Red, Green, Blue, Alpha);
}

void RenderSceneCB ()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(0.0, 0.0, 0.0, 0.0);
    glScalef(0.5,1.0,2.0);

    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.0, 0.5, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.5, -0.5, 0.0);

    glEnd();

    //glutSwapBuffers();
    glFlush();
}
