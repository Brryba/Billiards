#include <iostream>
#include "Balls.h"
#include "Collisions.h"
#include "GameState.h"

using namespace ::std;

int ballsLen = 0;
Ball *balls = nullptr;
Ball* whiteBall = nullptr;

void createBalls() {
    ballsLen = BALL_AMOUNT;
    balls = new Ball[BALL_AMOUNT];
    for (int i = 0; i < BALL_AMOUNT; i++) {
        balls[i].setStartCoord(BALL_POS[i][0], BALL_POS[i][1]);
        balls[i].isActive = true;
    }
    balls[0].color = CL_WHITE;
    for (int i = 1; i <= RED_AMOUNT; i++) {
        balls[i].color = CL_RED;
    }
    balls[YELLOW_BALL].color = CL_YELLOW;
    balls[GREEN_BALL].color = CL_GREEN;
    balls[BROWN_BALL].color = CL_BROWN;
    balls[BLUE_BALL].color = CL_BLUE;
    balls[PINK_BALL].color = CL_PINK;
    balls[BLACK_BALL].color = CL_BLACK;
    whiteBall = &balls[0];
}

float countSpeed(float speed, float acceleration) {
    return (abs(speed) < abs(acceleration)) ? 0 :
           (speed > 0) ? speed - acceleration : speed + acceleration;
}

void moveBalls() {
    collisionsCheck();
    gameState = gameState == MOVE ? CALC : gameState;
    for (int i = 0; i < ballsLen; i++) {
        balls[i].coordX = balls[i].coordX + balls[i].speedX;
        balls[i].coordY = balls[i].coordY + balls[i].speedY;
        balls[i].speedX = countSpeed(balls[i].speedX,
                                     sin(balls[i].angle) * ACCELERATION);
        balls[i].speedY = countSpeed(balls[i].speedY,
                                     cos(balls[i].angle) * ACCELERATION);
        if (balls[i].speedX != 0 || balls[i].speedY != 0 && balls[i].isActive) {
            gameState = MOVE;
        }
    }
}