#ifndef BILLIARDS_BALLCONSTANTS_H
#define BILLIARDS_BALLCONSTANTS_H

const int BALL_AMOUNT = 22;
const int RED_AMOUNT = 15;
const int YELLOW_BALL = RED_AMOUNT + 1;
const int GREEN_BALL = RED_AMOUNT + 2;
const int BROWN_BALL = RED_AMOUNT + 3;
const int BLUE_BALL = RED_AMOUNT + 4;
const int PINK_BALL = RED_AMOUNT + 5;
const int BLACK_BALL = RED_AMOUNT + 6;

enum Color {
    CL_WHITE = 0,
    CL_RED,
    CL_YELLOW,
    CL_GREEN,
    CL_BROWN,
    CL_BLUE,
    CL_PINK,
    CL_BLACK
};

const float BALL_COLORS[CL_BLACK + 1][3] = {{1,   1,     1},
                                            {1,   0,     0},
                                            {1,   1,     0},
                                            {0,   0.5,   0},
                                            {0.6, 0.3, 0.3},
                                            {0,   0,     1},
                                            {1,   0.75,  0.75},
                                            {0,   0,     0}
};

const int BALL_OFFSET = (int) (BALL_RADIUS * 2 / 1.42 + 1);
const int X_OFFSET = BALL_OFFSET + 5;
const int Y_OFFSET = BALL_OFFSET - 4;

const int FIRST_RED_COORDS[2] = {(WIDTH_FINISH + MID_POCKET) / 2, HEIGHT_CENTER};

const int BALL_POS[BALL_AMOUNT][2] = {
        {WIDTH_START + LINE_OFFSET - 50, HEIGHT_CENTER},
        {FIRST_RED_COORDS[0], FIRST_RED_COORDS[1]},
        {FIRST_RED_COORDS[0] + X_OFFSET, FIRST_RED_COORDS[1] + Y_OFFSET},
        {FIRST_RED_COORDS[0] + X_OFFSET, FIRST_RED_COORDS[1] - Y_OFFSET},
        {FIRST_RED_COORDS[0] + 2 * X_OFFSET, FIRST_RED_COORDS[1] + 2 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 2 * X_OFFSET, FIRST_RED_COORDS[1]},
        {FIRST_RED_COORDS[0] + 2 * X_OFFSET, FIRST_RED_COORDS[1] - 2 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 3 * X_OFFSET, FIRST_RED_COORDS[1] + 3 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 3 * X_OFFSET, FIRST_RED_COORDS[1] + 1 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 3 * X_OFFSET, FIRST_RED_COORDS[1] - 1 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 3 * X_OFFSET, FIRST_RED_COORDS[1] - 3 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 4 * X_OFFSET, FIRST_RED_COORDS[1] + 4 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 4 * X_OFFSET, FIRST_RED_COORDS[1] + 2 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 4 * X_OFFSET, FIRST_RED_COORDS[1]},
        {FIRST_RED_COORDS[0] + 4 * X_OFFSET, FIRST_RED_COORDS[1] - 2 * Y_OFFSET},
        {FIRST_RED_COORDS[0] + 4 * X_OFFSET, FIRST_RED_COORDS[1] - 4 * Y_OFFSET},
        {WIDTH_START + LINE_OFFSET, HEIGHT_CENTER + DZONE_RADIUS},
        {WIDTH_START + LINE_OFFSET, HEIGHT_CENTER - DZONE_RADIUS},
        {WIDTH_START + LINE_OFFSET, HEIGHT_CENTER},
        {MID_POCKET, HEIGHT_CENTER},
        {FIRST_RED_COORDS[0] - (int) (1.15 * X_OFFSET), FIRST_RED_COORDS[1]},
        {FIRST_RED_COORDS[0]  + 200, FIRST_RED_COORDS[1]},

};
#endif
