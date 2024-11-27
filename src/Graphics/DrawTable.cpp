#include "GL/glut.h"
#include "Draw.h"
#include "../Main/Constants.h"

void drawCenter() {
    glColor3f(0.0, 1.0, 0.0);
    glLineWidth(30);

    drawSquare(WIDTH_START, WIDTH_FINISH, HEIGHT_START, HEIGHT_FINISH);
}

void drawBorders() {
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
