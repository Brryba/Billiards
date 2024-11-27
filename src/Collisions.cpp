#include <iostream>
#include "Balls.h"
#include "Constants.h"

const float WASTE_COEF = 0.8;

bool checkPocketsCollisions(Ball *ball) {
    for (auto j : POCKETS_COORDS) {
        float dx = ball->coordX - j[0];
        float dy = balls->coordY - j[1];
        if (sqrt(dx * dx + dy * dy) < POCKET_RADIUS) {
            ball->coordX = 100;
            ball->setSpeed(0, 0);
            return true;
        }
    }
    return false;
}

bool checkBorders(Ball *ball) {
    if (ball->coordX - BALL_RADIUS < WIDTH_START + BORDER_LEN) {
        if (abs(ball->coordX - MID_POCKET) > POCKET_RADIUS) {
            ball->speedX *= -WASTE_COEF;
            ball->speedY *= WASTE_COEF;
            ball->coordX = WIDTH_START + BORDER_LEN + BALL_RADIUS;
            return true;
        } else {
            return false;
        }
    }
    if (ball->coordX + BALL_RADIUS > WIDTH_FINISH - BORDER_LEN) {
        if (abs(ball->coordX - MID_POCKET) > POCKET_RADIUS) {
            ball->speedX *= -WASTE_COEF;
            ball->speedY *= WASTE_COEF;
            ball->coordX = WIDTH_FINISH - BORDER_LEN - BALL_RADIUS;
            return true;
        } else {
            return false;
        }
    }
    if (ball->coordY + BALL_RADIUS > HEIGHT_FINISH - BORDER_LEN) {
        ball->speedX *= WASTE_COEF;
        ball->speedY *= -WASTE_COEF;
        ball->coordY = HEIGHT_FINISH - BORDER_LEN - BALL_RADIUS;
        return true;
    }
    if (ball->coordY - BALL_RADIUS < HEIGHT_START + BORDER_LEN) {
        ball->speedX *= WASTE_COEF;
        ball->speedY *= -WASTE_COEF;
        ball->coordY = HEIGHT_START + BORDER_LEN + BALL_RADIUS;
        return true;
    }
    return false;
}

void collisionsCheck() {
    for (int i = 0; i < ballsLen; i++) {
        if (!checkPocketsCollisions(&balls[i])) {
            if (checkBorders(&balls[i])) {}
        }
    }
}