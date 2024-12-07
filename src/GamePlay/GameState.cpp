#include "GameState.h"
#include "Player.h"

States gameState = WAIT;

Color firstTouched = CL_NONE;

std::vector<Color> fallenBalls;

Player* player1 = new Player;

Player* player2 = new Player;

Player* activePlayer = player1;

void swapActivePlayer() {
    activePlayer = activePlayer == player1 ? player2 : player1;
}

void putTheBallBack()

void findNextTarget() {
    if (firstTouched == CL_NONE) {
        swapActivePlayer();
        activePlayer->points += 4;
    } else if (firstTouched != activePlayer->neededColor) {
        swapActivePlayer();
        activePlayer->points += firstTouched;
        //////IF GAME ENDS CHECK ADD
        activePlayer->neededColor = CL_RED;
    } else if (fallenBalls.empty()) {
        swapActivePlayer();
    } else {
        bool isFoul = false;
        int points = 0;
        for (auto & fallenBall : fallenBalls) {
            if (fallenBall != activePlayer->neededColor) {
                swapActivePlayer();
                activePlayer->points += fallenBall;
                isFoul = true;
            } else {
                points += activePlayer->neededColor;
            }
            putTheBallBack(fallenBall);
        }
        if (!isFoul) {
            activePlayer->points += points;
            activePlayer->neededColor = CL_COLOR;
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