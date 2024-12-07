#include "Balls.h"
#include "Collisions.h"
#include "GameState.h"

using namespace ::std;

int ballsLen = 0;
Ball *balls = nullptr;
Ball* whiteBall = nullptr;

void createBalls() {
    ballsLen = 4;
    balls = new Ball[ballsLen];
    for (int i = 0; i < ballsLen; i++) {
        //balls[i].coordX = 400;
        //balls[i].coordY = 500;
    }
    balls[0].coordX = 1500;
    balls[0].coordY = 600;
    balls[0].color = CL_BLUE;
    balls[1].coordX = 1650;
    balls[1].coordY = 369;
    balls[2].coordX = 1500;
    balls[2].coordY = 924;
    balls[3].coordX = 1500;
    balls[3].coordY = 948;
    //balls[1].setSpeed(1.3, 1.3);
    whiteBall = &balls[0];
}

float countSpeed(float speed, float acceleration) {
    return (abs(speed) < abs(acceleration)) ? 0 :
           (speed > 0) ? speed - acceleration : speed + acceleration;
}

void moveBalls() {
    collisionsCheck();
    gameState = WAIT;
    for (int i = 0; i < ballsLen; i++) {
        balls[i].coordX = balls[i].coordX + balls[i].speedX;
        balls[i].coordY = balls[i].coordY + balls[i].speedY;
        balls[i].speedX = countSpeed(balls[i].speedX,
                                     sin(balls[i].angle) * ACCELERATION);
        balls[i].speedY = countSpeed(balls[i].speedY,
                                     cos(balls[i].angle) * ACCELERATION);
        if (balls[i].speedX != 0 || balls[i].speedY != 0) {
            gameState = MOVE;
        }
    }
}