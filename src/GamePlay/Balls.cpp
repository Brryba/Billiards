#include "Balls.h"
#include "Collisions.h"

using namespace ::std;

int ballsLen = 0;
Ball *balls = nullptr;
Ball* whiteBall = nullptr;

void createBalls() {
    ballsLen = 1;
    balls = new Ball[ballsLen];
    for (int i = 0; i < ballsLen; i++) {
        balls[i].coordX = 400;
        balls[i].coordY = 500;
    }
    whiteBall = &balls[0];
}

float countSpeed(float speed, float acceleration) {
    return (abs(speed) < abs(acceleration)) ? 0 :
           (speed > 0) ? speed - acceleration : speed + acceleration;
}

void moveBalls() {
    collisionsCheck();
    for (int i = 0; i < ballsLen; i++) {
        balls[i].coordX = balls[i].coordX + balls[i].speedX;
        balls[i].coordY = balls[i].coordY + balls[i].speedY;
        balls[i].speedX = countSpeed(balls[i].speedX,
                                     sin(balls[i].angle) * ACCELERATION);
        balls[i].speedY = countSpeed(balls[i].speedY,
                                     cos(balls[i].angle) * ACCELERATION);
    }
}