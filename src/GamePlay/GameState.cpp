#include "GameState.h"
#include "Player.h"
#include "Balls.h"
#include "Collisions.h"
#include <algorithm>

States gameState = START;

Color firstTouched = CL_NONE;

std::vector<Ball *> fallenBalls;

Player *player1 = new Player;

Player *player2 = new Player;

Player *activePlayer = player1;

const int MIN_FINE = 4;

void swapActivePlayer() {
    activePlayer = activePlayer == player1 ? player2 : player1;
}

void putTheBallBack(Ball *ball) {
    if (ball->color == CL_WHITE) {
        ball->setStartCoord(BALL_POS[0][0], BALL_POS[0][1]);
        ball->setSpeed(0, 0);
        gameState = FOUL;
        ball->isActive = true;
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

void findOutWinner() {
    if (fallenBalls.size() > 1 || firstTouched == CL_NONE) {
        swapActivePlayer();
        gameState = VICTORY;
        return;
    }
    if (fallenBalls.size() == 1) {
        if (fallenBalls.at(0)->color == CL_BLACK) {
            gameState = VICTORY;
            activePlayer->points += CL_BLACK;
            activePlayer = player1->points > player2->points ? player1
                    : player1->points < player2->points ? player2 : nullptr;
        }
    } else {
        swapActivePlayer();
        changeNeededColor(false);
    }
}

void checkFallenBals() {
    bool isFoul = false;
    int points = 0;
    for (auto &fallenBall: fallenBalls) {
        putTheBallBack(fallenBall);
        if (!isFoul && isWrongBall(activePlayer->neededColor, fallenBall->color)) {
            if (fallenBall->color == CL_WHITE) {
                if (firstTouched != CL_NONE) {
                    swapActivePlayer();
                    activePlayer->points += MIN_FINE;
                }
                gameState = FOUL;
            } else {
                swapActivePlayer();
                activePlayer->points += max((int)fallenBall->color, MIN_FINE);
            }
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

void findNextTarget() {
    if (activePlayer->neededColor == CL_BLACK) {
        return findOutWinner();
    }
    if (firstTouched == CL_NONE) {
        swapActivePlayer();
        activePlayer->points += MIN_FINE;
        changeNeededColor(false);
    } else if (fallenBalls.empty()) {
        Color temp = activePlayer->neededColor;
        swapActivePlayer();
        if (isWrongBall(temp, firstTouched)) {
            activePlayer->points += max((int)firstTouched, MIN_FINE);
        }
        changeNeededColor(false);
    }
    if (!fallenBalls.empty()) {
        checkFallenBals();
    }
}

void clearState() {
    firstTouched = CL_NONE;
    fallenBalls.clear();
    gameState = gameState == CALC ? WAIT : gameState;
}

void countNext() {
    findNextTarget();
    clearState();
}