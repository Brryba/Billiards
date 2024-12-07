#include <GL/gl.h>
#include <cmath>
#include <iostream>
#include <cstring>
#include "Draw.h"
#include "../Main/Constants.h"
#include "../GamePlay/Balls.h"
#include "GL/glut.h"
#include "../Controls/Handlers.h"
#include "../GamePlay/GameState.h"

void drawCircle(float x, float y, float size) {
    const int POINTS_NUM = 100;

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
    for (int i = 0; i < BALL_AMOUNT; i++) {
        if (balls[i].isActive) {
            glColor3f(BALL_COLORS[balls[i].color][0],
                      BALL_COLORS[balls[i].color][1],
                      BALL_COLORS[balls[i].color][2]);
            drawBall(balls[i].coordX, balls[i].coordY);
        }
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
        glVertex2f(WIDTH_START - BROWN_BORDER_LEN, whiteBall->coordY +
                (whiteBall->coordX - WIDTH_START + BROWN_BORDER_LEN)
                * (whiteBall->coordY - mouseY) / (mouseX - whiteBall->coordX));
    } else if (whiteBall->coordX != mouseX) {
        glVertex2f(WIDTH_FINISH + BROWN_BORDER_LEN, whiteBall->coordY +
                (WIDTH_FINISH + BROWN_BORDER_LEN - whiteBall->coordX)
                * (mouseY - whiteBall->coordY) / (mouseX - whiteBall->coordX));
    } else if (whiteBall->coordY > mouseY) {
        glVertex2f(mouseX, APP_HEIGHT);
    } else {
        glVertex2f(mouseX, 0);
    }
    glEnd();
}

void drawSquare(int width_start, int width_finish, int height_start, int height_finish) {
    glBegin(GL_POLYGON);
    glVertex2i(width_start, height_start);
    glVertex2i(width_start, height_finish);
    glVertex2i(width_finish, height_finish);
    glVertex2i(width_finish, height_start);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void drawBackGround() {
    glColor3f(0.6, 0.9, 0.9);
    drawSquare(WIDTH_START - BROWN_BORDER_LEN, WIDTH_FINISH + BROWN_BORDER_LEN,
               0, HEIGHT_START - BROWN_BORDER_LEN);
    drawSquare(WIDTH_START - BROWN_BORDER_LEN, WIDTH_FINISH + BROWN_BORDER_LEN,
               HEIGHT_FINISH + BROWN_BORDER_LEN, APP_HEIGHT);
}

void printScores() {
    glColor3f(0.2, 0.2, 1);
    glRasterPos2f(250, 150);
    std::string str = "PLAYER 1: " + std::to_string(player1->points);
    for (char c : str) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }


    glColor3f(1, 0.2, 0.2);
    glRasterPos2f(1500, 150);
    str = "PLAYER 2: " + std::to_string(player2->points);
    for (char c : str) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    switch (activePlayer->neededColor) {
        case CL_RED: str = "RED"; break;
        case CL_YELLOW: str = "YELLOW"; break;
        case CL_GREEN: str = "GREEN"; break;
        case CL_BROWN: str = "BROWN"; break;
        case CL_BLUE: str = "BLUE"; break;
        case CL_PINK: str = "PINK"; break;
        case CL_BLACK: str = "BLACK"; break;
        case CL_COLOR: str = "COLOR (NOT RED)"; break;
    }


    if (activePlayer == player1) {
        glColor3f(0.2, 0.2, 1);
    } else {
        glColor3f(1, 0.2, 0.2);
    }
    glRasterPos2f(825, 150);
    std::string playerStr = (activePlayer == player1 ? "PLAYER 1: SCORE " : "PLAYER 2: SCORE ") + str;
    for (char c : playerStr) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glFlush();
}