#include <vector>
#include "../Main/Constants.h"
#include "BallConstants.h"
#include "Player.h"
#include "Balls.h"

#ifndef BILLIARDS_GAMESTATE_H
#define BILLIARDS_GAMESTATE_H
enum States {
    WAIT,
    CALC,
    MOVE,
    START,
    FOUL,
    VICTORY
};

extern States gameState;

extern Color firstTouched;

extern std::vector<Ball*> fallenBalls;

extern Player* player1;

extern Player* player2;

extern Player* activePlayer;

void countNext();

#endif
