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

void findNextTarget() {
    if (firstTouched != activePlayer->neededColor) {
        swapActivePlayer();
        activePlayer->points += 4;
        //////IF GAME ENDS CHECK ADD
        activePlayer->neededColor = CL_RED;
    } else if (fallenBalls.empty()) {
        swapActivePlayer();
    } else {
        bool isFoul = false;
        for (auto & fallenBall : fallenBalls) {
            if (fallenBall != activePlayer->neededColor) {
                swapActivePlayer();
                //ACTUAL NUM APPEND
                activePlayer->points += 5;
                isFoul = true;
            }
        }
        if (!isFoul) {
            activePlayer->points += 4;
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