#include <GL/gl.h>
#include <cmath>
#include <iostream>
#include "Draw.h"
#include "Constants.h"
#include "Balls.h"
#include "GL/glut.h"
#include "Handlers.h"

void drawCircle(float x, float y, float size) {
    const int POINTS_NUM = 52;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);

    for (int i = 0; i <= POINTS_NUM; i++) {
        float angle = M_PI * 2 * (float) i / POINTS_NUM;
        float dx = size * cosf(angle);
        float dy = size * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void drawBall(float x, float y) {
    drawCircle(x, y, BALL_RADIUS);
}

void drawBalls() {
    glColor3f(1, 1, 1);
    for (int i = 0; i < ballsLen; i++) {
        drawBall(balls[i].coordX, balls[i].coordY);
    }
}

void setLineColor(int len) {
    if (len < MIN_LEN)
        glColor3f(1, 1, 1);
    else {
        glColor3f(len / MAX_LEN, 1 - len / MAX_LEN, 0);
    }
}

void drawStrikeLine(int len) {
    //ЕСЛИ ЦЕЛИТСЯ СДЕЛАТЬ ЧТОБ НЕ РИСОВАЛО ПРИ МИНИМУМЕ
    setLineColor(len);

    glLineWidth(1.5);

    glBegin(GL_LINE_LOOP);
    glVertex2f(whiteBall->coordX, whiteBall->coordY);
    if (whiteBall->coordX < mouseX) {
        glVertex2f(0, whiteBall->coordY +
                      whiteBall->coordX * (whiteBall->coordY - mouseY) / (mouseX - whiteBall->coordX));
    } else if (whiteBall->coordX != mouseX) {
        glVertex2f(APP_WIDTH, whiteBall->coordY -
                              whiteBall->coordX * (whiteBall->coordY - mouseY) / (mouseX - whiteBall->coordX));
    } else if (whiteBall->coordY > mouseY) {
        glVertex2f(mouseX, APP_HEIGHT);
    } else {
        glVertex2f(mouseX, 0);
    }
    glEnd();
}