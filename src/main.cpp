#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include "Draw.h"
#include "Constants.h"
#include "Balls.h"
#include "Handlers.h"

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(7, timer, 0);  // FPS настроить как-то можно
}

void initializeDisplay(int args, char **argv) {
    glutInit(&args, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Billiards");
    glutFullScreen();
    glTranslatef(-1, 1, 0);
    glScalef(2.f / APP_WIDTH, -2.f / APP_HEIGHT, 1);

    createBalls();

    glutPassiveMotionFunc(mousePassiveMove);
    glutMouseFunc(mouseActivePress);
    glutMotionFunc(mouseActiveMove);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
}

int main(int args, char **argv) {
    initializeDisplay(args, argv);
    return 0;
}