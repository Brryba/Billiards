#define WINDOW_HEIGHT (glutGet(GLUT_WINDOW_HEIGHT))
#define WINDOW_WIDTH (glutGet(GLUT_WINDOW_WIDTH))
#ifndef BILLIARDS_CONSTANTS_H
#define BILLIARDS_CONSTANTS_H

const int APP_WIDTH = 2000; //сколько на моем экране
const int APP_HEIGHT = 1125; //СВЕРХУ 0 ХВАТИТ ПУТАТЬ
const float BALL_RADIUS = 12;
const int MAX_SPEED = 10;
const float MIN_LEN = 20;
const float MAX_LEN = 300;
const float ACCELERATION = 0.01;

const int WIDTH_START = 300;
const int WIDTH_FINISH = 1700;
const int MID_POCKET = (WIDTH_START + WIDTH_FINISH) / 2;
const int HEIGHT_START = 315;
const int HEIGHT_FINISH = 1015;
const int POCKET_RADIUS = 25;
const int BORDER_LEN = 20;
const int POCKETS_AMOUNT = 6;

const float POCKETS_COORDS[6][2] = {
        {WIDTH_START + POCKET_RADIUS, HEIGHT_START + POCKET_RADIUS},
        {MID_POCKET, HEIGHT_START + POCKET_RADIUS / 3},
        {WIDTH_FINISH - POCKET_RADIUS, HEIGHT_START + POCKET_RADIUS},
        {WIDTH_START + POCKET_RADIUS, HEIGHT_FINISH - POCKET_RADIUS},
        {MID_POCKET, HEIGHT_FINISH - POCKET_RADIUS / 3},
        {WIDTH_FINISH - POCKET_RADIUS, HEIGHT_FINISH - POCKET_RADIUS},
};

enum Color {
    CL_WHITE
};
#endif