#include "gameplay.h"

void SetInput(struct input* cInput)
{
	scanKeys();
	int key_pressed = keysDown();
	int key_released = keysUp();

	if(key_pressed & KEY_UP)
	{
		cInput->up = true;
	}

	if(key_pressed & KEY_DOWN)
	{
		cInput->down = true;
	}

	if(key_released & KEY_UP)
	{
		cInput->up = false;
	}

	if(key_released & KEY_DOWN)
	{
		cInput->down = false;
	}
}

void KeepInBounds(struct rect* cRect)
{
	if(cRect->y < 0)
	{
		cRect->y = 0;
	}

		if(cRect->y + cRect->height > SCREEN_HEIGHT)
	{
		cRect->y = (SCREEN_HEIGHT - cRect->height);
	}
}

bool CheckCollision(struct rect* cRectA, struct rect* cRectB)
{
	if(cRectA->x > (cRectB->x + cRectB->width)) return false;
	if((cRectA->x + cRectA-> width) < cRectB->x) return false;
	if(cRectA->y > (cRectB->y + cRectB->height)) return false;
	if((cRectA->y + cRectA-> height) < cRectB->y) return false;

	return true;
}

void MovePlayer(struct rect* player, struct input* input)
{
	if(input->up) player->velocityY = -2;
	else if(input->down) player->velocityY = 2;
	else player->velocityY = 0;

	player->prevX = player->x;
	player->prevY = player->y;
}

//Sets previous values of ball position and then updates its  position
void MoveBall(struct rect* ball)
{
	ball->prevX = ball->x;
	ball->prevY = ball->y;

	ball->x += ball->velocityX;
	ball->y += ball->velocityY;
}

void BallBoundaries(struct rect* cBall)
{

	//Keep the ball vertically within the playspace.
	if(cBall->y < 0)
	{
		cBall->y = 0;
		cBall->velocityY = cBall->velocityY * -1;
	}

	if(cBall->y + cBall->height > SCREEN_HEIGHT)
	{
		cBall->y = (SCREEN_HEIGHT - cBall->height);
		cBall->velocityY = cBall->velocityY * -1;
	}
}

void AdjustVelocityByHitPosition(struct rect* cBall, struct rect* cPaddle)
{
	int ballMiddle = cBall->y + (cBall->height / 2);
	int paddleMiddle = cPaddle->y + (cPaddle->height / 2);

	int difference = (ballMiddle - paddleMiddle) / 8;
	cBall->velocityY = 0;
	cBall->velocityY += difference;
}