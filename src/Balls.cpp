#include "Balls.h"

using namespace ::std;

int ballsLen = 0;
Ball *balls = nullptr;

void createBalls() {
    ballsLen = 2;
    balls = new Ball[ballsLen];
    for (int i = 0; i < ballsLen; i++) {
        balls[i].coordX = 1300;
        balls[i].coordY = 490;
    }
    balls[1].coordX = 823;
    balls[1].coordY = 265;
    balls[1].setSpeed(-2, 2);
    balls[0].setSpeed(2, 2);
    //huyniu delau
}

float countSpeed(float speed, float acceleration) {
    return (abs(speed) < abs(acceleration)) ? 0 :
           (speed > 0) ? speed - acceleration : speed + acceleration;
}

void moveBalls() {
    const float ACCELERATION = 0.008;
    for (int i = 0; i < ballsLen; i++) {
        balls[i].coordX = balls[i].coordX + balls[i].speedX;
        balls[i].coordY = balls[i].coordY + balls[i].speedY;
        balls[i].speedX = countSpeed(balls[i].speedX,
                                     sin(balls[i].angle) * ACCELERATION);
        balls[i].speedY = countSpeed(balls[i].speedY,
                                     cos(balls[i].angle) * ACCELERATION);
    }
}