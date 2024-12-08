#ifndef BILLIARDS_PLAYER_H
#define BILLIARDS_PLAYER_H

#include "../Main/Constants.h"
#include "BallConstants.h"

struct Player {
    int points = 0;
    Color neededColor = CL_RED;
    void reset() {
        this->points = 0;
        this->neededColor = CL_RED;
    }
};
#endif
