#include "GL/glut.h"
#include "Draw.h"
#include "../Main/Constants.h"

const int BROWN_BORDER_LEN = 50;

void drawSquare(int width_start, int width_finish, int height_start, int height_finish) {
    glBegin(GL_POLYGON);
    glVertex2i(width_start, height_start);
    glVertex2i(width_start, height_finish);
    glVertex2i(width_finish, height_finish);
    glVertex2i(width_finish, height_start);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void drawCenter() {
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(30);

    drawSquare(WIDTH_START, WIDTH_FINISH, HEIGHT_START, HEIGHT_FINISH);
}

void drawBorders() {
    /*glColor3f(0.0, 0.7, 0.0);
    drawSquare(WIDTH_START, WIDTH_START + BORDER_LEN,
               HEIGHT_START + POCKET_RADIUS, HEIGHT_FINISH - POCKET_RADIUS);
    drawSquare(WIDTH_FINISH - BORDER_LEN, WIDTH_FINISH,
               HEIGHT_START + POCKET_RADIUS, HEIGHT_FINISH - POCKET_RADIUS);
    drawSquare(WIDTH_START, MID_POCKET - POCKET_RADIUS,
               HEIGHT_START, HEIGHT_START + BORDER_LEN);
    drawSquare(WIDTH_START + POCKET_RADIUS, MID_POCKET - POCKET_RADIUS,
               HEIGHT_FINISH - BORDER_LEN, HEIGHT_FINISH);
    drawSquare(MID_POCKET + POCKET_RADIUS, WIDTH_FINISH - POCKET_RADIUS,
               HEIGHT_START, HEIGHT_START + BORDER_LEN);
    drawSquare(MID_POCKET + MID_POCKET_RADIUS, WIDTH_FINISH - POCKET_RADIUS,
               HEIGHT_FINISH - BORDER_LEN, HEIGHT_FINISH);*/

    glColor3f(0.0, 0.7, 0.0);
    drawSquare(WIDTH_START, WIDTH_START + BORDER_LEN,
               HEIGHT_START, HEIGHT_FINISH);
    drawSquare(WIDTH_FINISH - BORDER_LEN, WIDTH_FINISH,
               HEIGHT_START, HEIGHT_FINISH);
    drawSquare(WIDTH_START, WIDTH_FINISH,
               HEIGHT_START, HEIGHT_START + BORDER_LEN);
    drawSquare(WIDTH_START, WIDTH_FINISH,
               HEIGHT_FINISH, HEIGHT_FINISH - BORDER_LEN);

    glColor3f(0.5, 0.5, 0.0);
    drawSquare(WIDTH_START - BROWN_BORDER_LEN, WIDTH_START,
               HEIGHT_START - BROWN_BORDER_LEN, HEIGHT_FINISH + BROWN_BORDER_LEN);
    drawSquare(WIDTH_FINISH, WIDTH_FINISH + BROWN_BORDER_LEN, HEIGHT_START - BROWN_BORDER_LEN,
               HEIGHT_FINISH + BROWN_BORDER_LEN);
    drawSquare(WIDTH_START - BROWN_BORDER_LEN, WIDTH_FINISH + BROWN_BORDER_LEN,
               HEIGHT_START - BROWN_BORDER_LEN, HEIGHT_START);
    drawSquare(WIDTH_START - BROWN_BORDER_LEN, WIDTH_FINISH + BROWN_BORDER_LEN,
               HEIGHT_FINISH, HEIGHT_FINISH + BROWN_BORDER_LEN);
}

void drawPockets() {
    glColor3f(0, 0, 0);
    for (int i = 0; i < 6; i++) {
        drawCircle(POCKETS_COORDS[i][0], POCKETS_COORDS[i][1], POCKET_RADIUS);
    }
}

void drawTable() {
    drawCenter();
    drawBorders();
    drawPockets();
}
