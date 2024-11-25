#ifndef BALLS_H
#define BALLS_H

#include <cmath>
#include <valarray>

using namespace ::std;

struct Ball {
    float coordX;
    float coordY;
    float speedX;
    float speedY;
    float angle;

    Ball() {
        this->speedY = 0;
        this->speedX = 0;
    }

    void setSpeed(float x, float y) {
        this->speedX = x;
        this->speedY = y;
        this->angle = atan(abs(x) / abs(y));
    }
};

extern Ball* balls;
extern int ballsLen;

void createBalls();
void moveBalls();

#endif