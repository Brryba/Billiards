#include "GameState.h"
#include "Player.h"
#include "Balls.h"
#include "Collisions.h"

States gameState = WAIT;

Color firstTouched = CL_NONE;

std::vector<Ball *> fallenBalls;

Player *player1 = new Player;

Player *player2 = new Player;

Player *activePlayer = player1;

void swapActivePlayer() {
    activePlayer = activePlayer == player1 ? player2 : player1;
}

void putTheBallBack(Ball *ball) {
    if (ball->color == CL_WHITE) {

    } else if (ball->color != CL_RED && ball->color > activePlayer->neededColor) {
        ball->setSpeed(0, 0);
        ball->isActive = true;
        bool hasCol = false;
        int i = -1;
        do {
            i++;
            ball->setStartCoord(BALL_POS[RED_AMOUNT + ball->color - 1 + i][0],
                                BALL_POS[RED_AMOUNT + ball->color - 1][1]);
            for (int j = 0; j < BALL_AMOUNT; j++) {
                if (ball != &balls[i] &&countBallDistance(ball, &balls[i]) < BALL_RADIUS * 2) {
                    hasCol = true;
                }
            }
        } while (hasCol);
    }
}

bool hasActiveRed() {
    for (int i = 1; i <= RED_AMOUNT; i++) {
        if (balls[i].isActive) {
            return true;
        }
    }
    return false;
}

void changeNeededColor(bool hasScored) {
    bool hasRed = hasActiveRed();
    if (hasScored) {
        if (activePlayer->neededColor == CL_RED) {
            if (hasRed) {
                activePlayer->neededColor = CL_COLOR;
            } else {
                activePlayer->neededColor = CL_YELLOW;
            }
        } else {
            if (hasRed) {
                activePlayer->neededColor = CL_RED;
            } else {
                if (activePlayer->neededColor != CL_BLACK) {
                    activePlayer->neededColor = static_cast<Color>(activePlayer->neededColor + 1);
                }
            }
        }
    } else {
        if (hasRed) {
            activePlayer->neededColor = CL_RED;
        } else {
            Ball* temp = &balls[YELLOW_BALL];
            activePlayer->neededColor = CL_YELLOW;
            int i = 0;
            while (!temp->isActive) {
                i++;
                activePlayer->neededColor = balls[YELLOW_BALL + i].color;
                temp = &balls[YELLOW_BALL + i];
            }
        }
    }
}

bool isWrongBall(Color playerColor, Color actualColor) {
    if (playerColor == CL_COLOR) {
        return actualColor == CL_RED;
    }
    return playerColor != actualColor;
}

void findNextTarget() {
    if (firstTouched == CL_NONE) {
        swapActivePlayer();
        activePlayer->points += 4;
        changeNeededColor(false);
    } else if (fallenBalls.empty()) {
        Color temp = activePlayer->neededColor;
        swapActivePlayer();
        if (isWrongBall(temp, firstTouched)) {
            activePlayer->points += firstTouched;
        }
        changeNeededColor(false);
    }
    if (!fallenBalls.empty()) {
        bool isFoul = false;
        int points = 0;
        for (auto &fallenBall: fallenBalls) {
            putTheBallBack(fallenBall);
            if (!isFoul && isWrongBall(activePlayer->neededColor, fallenBall->color)) {
                swapActivePlayer();
                activePlayer->points += fallenBall->color;
                changeNeededColor(false);
                isFoul = true;
            } else {
                points += fallenBall->color;
            }
        }
        if (!isFoul) {
            if (isWrongBall(activePlayer->neededColor, firstTouched)) {
                swapActivePlayer();
                changeNeededColor(false);
            } else {
                changeNeededColor(true);
            }
            activePlayer->points += points;
        }
    }
}

void clearState() {
    firstTouched = CL_NONE;
    fallenBalls.clear();
    gameState = WAIT;
}

void countNext() {
    findNextTarget();
    clearState();
}