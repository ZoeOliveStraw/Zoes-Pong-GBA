#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <gba_input.h>
#include "graphics.h"

struct input
{
	bool up;
	bool down;
	bool start;
};

//Receives input from the system and sets it to the members of the cInput struct
void SetInput(struct input* cInput);

//Will check if cRect is outside of the boundaries, and if so, sets it right to those boundaries
void KeepInBounds(struct rect* cRect);

//Checks if cRectA and cRectB overlap, returns true if they do, false otherwise.
bool CheckCollision(struct rect* cRectA, struct rect* cRectB);

//Process the movement of the player struct
void MovePlayer(struct rect* player, struct input* input);

//Process the movement of the ball
void MoveBall(struct rect* ball);

//keep ball within the boundaries
void BallBoundaries(struct rect* cBall);


//Adjust ball vertical velocity relative to where it hit a paddle
void AdjustVelocityByHitPosition(struct rect* cBall, struct rect* cPaddle);

#endif