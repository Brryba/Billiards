#ifndef BILLIARDS_BALLCONSTANTS_H
#define BILLIARDS_BALLCONSTANTS_H
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

const float BALL_COLORS[CL_BLACK + 1][3] = {{1, 1, 1},
                                         {1, 0, 0},
                                          {1, 1, 0},
                                          {0, 0.5, 0},
                                            {0.6, 0/2, 0.2},
                                            {0, 0, 1},
                                            {1, 0.75, 0.75},
                                            {0, 0, 0}
                                         };
#endif
