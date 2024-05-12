#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <gba_input.h>
#include "graphics.h"

struct input
{
	bool up;
	bool down;
};

void SetInput(struct input* cInput);
void KeepInBounds(struct rect* cRect);
bool CheckCollision(struct rect* cRectA, struct rect* cRectB);
void MovePlayer(struct rect* player, struct input* input);
void MoveBall(struct rect* ball);
void BallBoundaries(struct rect* cBall);
void AdjustVelocityByHitPosition(struct rect* cBall, struct rect* cPaddle);

#endif