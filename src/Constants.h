#define WINDOW_HEIGHT (glutGet(GLUT_WINDOW_HEIGHT))
#define WINDOW_WIDTH (glutGet(GLUT_WINDOW_WIDTH))
#ifndef BILLIARDS_CONSTANTS_H
#define BILLIARDS_CONSTANTS_H

const int APP_WIDTH = 1920; //сколько на моем экране
const int APP_HEIGHT = 1080; //СВЕРХУ 0 ХВАТИТ ПУТАТЬ
const float BALL_SIZE = 15;
const int MAX_SPEED = 8;
const float MIN_LEN = 20;
const float MAX_LEN = 300;
const float ACCELERATION = 0.008;

enum Color {
    CL_WHITE
};
#endif
