#ifndef BILLIARDS_COLLISIONS_H
#define BILLIARDS_COLLISIONS_H

void collisionsCheck();

float countBallDistance(Ball *ball1, Ball *ball2);

bool hasCollision(Ball *ball1, Ball *ball2);

float countPointDistance(float x1, float y1, float x2, float y2);

bool hasCueBallCollisions(int x, int y);

#endif
