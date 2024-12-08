#include <iostream>
#include "GL/glut.h"
#include "../Graphics/Draw.h"
#include "../Main/Constants.h"
#include "../GamePlay/Balls.h"
#include "../Graphics/DrawTable.h"
#include "../GamePlay/GameState.h"
#include "../GamePlay/Collisions.h"

int mouseX = 0, mouseY = 0;
int activeMouseStartX = 0, activeMouseStartY = 0;
int activeMouseX = 0, activeMouseY = 0;
float len = 0;

float toAppWidth(int x) {
    return (float) x * APP_WIDTH / WINDOW_WIDTH;
}

float toAppHeight(int y) {
    return (float) y * APP_HEIGHT / WINDOW_HEIGHT;
}

void mousePassiveMove(int x, int y) {
    mouseX = toAppWidth(x);
    mouseY = toAppHeight(y);
}

void mouseActivePress(int button, int state, int x, int y) {
    if ((gameState == START || gameState == FOUL) && button == GLUT_RIGHT_BUTTON) {
        x = toAppWidth(x);
        y = toAppHeight(y);
        if (!hasCueBallCollisions(x, y)) {
            if (gameState == START) {
                if ((x < WIDTH_START + LINE_OFFSET) &&
                    countPointDistance(WIDTH_START + LINE_OFFSET, HEIGHT_CENTER,
                                       x, y) < DZONE_RADIUS) {
                    whiteBall->setStartCoord(x, y);
                }
            } else {
                whiteBall->setStartCoord(x, y);
            }
        }
    }

    if (gameState == WAIT || gameState == START || gameState == FOUL) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            activeMouseStartX = x;
            activeMouseStartY = y;
        } else if (button == GLUT_LEFT_BUTTON) {
            if (len > MAX_LEN) {
                len = MAX_LEN;
            }
            if (len > MIN_LEN) {
                float angle = atan((toAppWidth(activeMouseStartX) - whiteBall->coordX) /
                                   (toAppHeight(activeMouseStartY) - whiteBall->coordY));
                float speed = len * MAX_SPEED / MAX_LEN;
                if (toAppHeight(activeMouseStartY) < whiteBall->coordY) {
                    whiteBall->setSpeed(speed * sin(angle), speed * cos(angle));
                } else {
                    whiteBall->setSpeed(-1 * speed * sin(angle), -1 * speed * cos(angle));
                }
            }

            len = 0;
        }
    }
}

void mouseActiveMove(int x, int y) {
    int dx = x - activeMouseStartX;
    int dy = y - activeMouseStartY;
    len = sqrt(dx * dx + dy * dy);
}

void display() {
    glClearColor(0.6, 0.9, 0.9, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    moveBalls();
    drawTable();
    drawBalls();
    if (gameState == WAIT || gameState == START || gameState == FOUL) {
        drawStrikeLine(len);
    } else if (gameState == CALC) {
        countNext();
    }
    drawBackGround();
    printScores();
    glutSwapBuffers();
}