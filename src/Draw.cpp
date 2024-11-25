#include <GL/gl.h>
#include <cmath>
#include "Draw.h"
#include "Constants.h"
#include "Balls.h"

void drawBall(float x, float y) {
    const int POINTS_NUM = 52;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);

    for (int i = 0; i <= POINTS_NUM; i++) {
        float angle = M_PI * 2 * (float)i / POINTS_NUM;
        float dx = BALL_SIZE * cosf(angle);
        float dy = BALL_SIZE * sinf(angle);
        glVertex2f(x + dx, y + dy);
    }

    glEnd();
}

void drawBalls() {
    for (int i = 0; i < ballsLen; i++) {
        drawBall(balls[i].coordX, balls[i].coordY);
    }
}