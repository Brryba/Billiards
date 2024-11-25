#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Draw.h"
#include "Constants.h"

void display();
void timer(int);

float theta = 0.0f;  // Initialize theta
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

void initializeDisplay(int args, char **argv) {
    glutInit(&args, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(0, 0);
    //glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Billiards");
    glutFullScreen();

    // Register what to draw
    glutDisplayFunc(display);

    glTranslatef(-1, -1, 0);
    glScalef(2.f / SCREEN_WIDTH, 2.f / SCREEN_HEIGHT, 1);

    // Start the timer for continuous updates
    glutTimerFunc(0, timer, 0);

    // Event waits
    glutMainLoop();
}

int main(int args, char **argv) {
    initializeDisplay(args, argv);
    return 0;
}

void display() {
    glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glRotatef(theta, 0.0f, 0.0f, 0.0f);
    drawBall(1000, 430);
    // Increment theta for animation
    //theta += 0.01f;

    glFlush();
}

void timer(int) {
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);  // FPS настроить как-то можно
}