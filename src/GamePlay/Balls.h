#ifndef BALLS_H
#define BALLS_H

#include <cmath>
#include <valarray>
#include "../Main/Constants.h"
#include "BallConstants.h"

using namespace ::std;

struct Ball {
    Color color;
    float coordX;
    float coordY;
    float speedX;
    float speedY;
    float angle;
    bool isActive;

    Ball() {
        this->speedY = 0;
        this->speedX = 0;
    }

    void setSpeed(float x, float y) {
        this->speedX = x;
        this->speedY = y;
        this->angle = y == 0 ? 0: atan(abs(x) / abs(y));
    }

    void setStartCoord(int x, int y) {
        this->coordX = x;
        this->coordY = y;
    }
};

extern Ball* balls;
extern int ballsLen;
extern Ball* whiteBall;

void createBalls();
void moveBalls();

#endif