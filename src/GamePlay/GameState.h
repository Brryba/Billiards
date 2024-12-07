#include <vector>
#include "../Main/Constants.h"
#include "BallConstants.h"

#ifndef BILLIARDS_GAMESTATE_H
#define BILLIARDS_GAMESTATE_H
enum States {
    WAIT,
    CALC,
    MOVE
};

extern States gameState;

extern Color firstTouched;

extern std::vector<Color> fallenBalls;

void countNext();

#endif
