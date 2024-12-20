#include <vector>
#include "Balls.h"
#include "../Main/Constants.h"
#include "GameState.h"

const float WASTE_COEF = 0.8;

std::vector<std::vector<Ball *>> collisioned;

bool checkPocketsCollisions(Ball *ball) {
    for (auto i : POCKETS_COORDS) {
        float dx = ball->coordX - i[0];
        float dy = ball->coordY - i[1];
        if (sqrt(dx * dx + dy * dy) < POCKET_RADIUS && ball->isActive) {
            ball->coordX = 0;
            ball->coordY = 0;
            ball->setSpeed(0, 0);
            ball->isActive = false;
            fallenBalls.push_back(ball);
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

void implementCollision(Ball *ball1, Ball *ball2) {
    if (firstTouched == CL_NONE) {
        firstTouched = ball1->color = ball1->color;
    }
    float dx = ball1->coordX - ball2->coordX;
    float dy = ball1->coordY - ball2->coordY;
    float angle = atan(dy / dx);

    float newV1x = ball1->speedX * cos(-angle) - ball1->speedY * sin(-angle);
    float newV1y = ball1->speedX * sin(-angle) + ball1->speedY * cos(-angle);
    float newV2x = ball2->speedX * cos(-angle) - ball2->speedY * sin(-angle);
    float newV2y = ball2->speedX * sin(-angle) + ball2->speedY * cos(-angle);

    ball1->setSpeed(newV2x * cos(angle) - newV1y * sin(angle),
                    newV2x * sin(angle) + newV1y * cos(angle));
    ball2->setSpeed(newV1x * cos(angle) - newV2y * sin(angle),
                    newV1x * sin(angle) + newV2y * cos(angle));

}

float countPointDistance(float x1, float y1, float x2, float y2) {
    float dx = x1 - x2;
    float dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

float countBallDistance(Ball *ball1, Ball *ball2) {
    return countPointDistance(ball1->coordX, ball1->coordY, ball2->coordX, ball2->coordY);
}

bool hasCollision(Ball *ball1, Ball *ball2) {
    if (ball1 == ball2) return false;
    if (!ball1->isActive || !ball2->isActive) {
        return false;
    }
    for (auto &i: collisioned) {
        if (i.at(0) == ball1 && i.at(1) == ball2 ||
            i.at(1) == ball1 && i.at(0) == ball2) {
            return true;
        }
    }
    return false;
}

void checkBallsCollisions(Ball *ball) {
    for (int i = 0; i < ballsLen; i++) {
        if (&balls[i] != ball) {
            if (countBallDistance(ball, &balls[i]) <= BALL_RADIUS * 2 &&
                !hasCollision(ball, &balls[i])) {
                implementCollision(&balls[i], ball);
                std::vector<Ball *> newCollision = {ball, &balls[i]};
                collisioned.push_back(newCollision);
            }
        }
    }
}

void collisionsCheck() {
    for (int i = 0; i < collisioned.size(); i++) {
        if (countBallDistance(collisioned.at(i).at(0), collisioned.at(i).at(1)) > 2 * BALL_RADIUS) {
            collisioned.erase(collisioned.begin() + i);
            i--;
        }
    }

    for (int i = 0; i < ballsLen; i++) {
        if (balls[i].isActive && !checkPocketsCollisions(&balls[i])) {
            if (!checkBorders(&balls[i])) {
                checkBallsCollisions(&balls[i]);
            }
        }
    }
}

bool hasCueBallCollisions(int x, int y) {
    for (int i = 1; i < BALL_AMOUNT; i++) {
        if (countPointDistance(balls[i].coordX, balls[i].coordY, x, y) < 2 * BALL_RADIUS) {
            return true;
        }
    }
    if (x < WIDTH_START + BORDER_LEN || x > WIDTH_FINISH - BORDER_LEN ||
        y > HEIGHT_FINISH - BORDER_LEN || y < HEIGHT_START + BORDER_LEN) {
        return true;
    }
    for (auto i : POCKETS_COORDS) {
        float dx = x - i[0];
        float dy = y - i[1];
        if (sqrt(dx * dx + dy * dy) < POCKET_RADIUS) {
            return true;
        }
    }
    return false;
}