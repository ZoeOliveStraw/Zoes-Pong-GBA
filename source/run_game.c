#include "libraries.h"
#include "game_states.h"

int ballSpeed = 2;

void RunGame(int player1Score, int player2Score)
{

	struct rect* HumanPlayer = CreateRect(1, (SCREEN_HEIGHT/2 - 24/2), paddle_width, paddle_height, 0, 0);
	struct rect* CPUplayer = CreateRect((SCREEN_WIDTH - 8 - 1), SCREEN_HEIGHT/2 - 24/2, 8, 24, 0, 0);
	struct rect* ball = CreateRect((SCREEN_WIDTH / 2 - 8/2), (SCREEN_HEIGHT / 2 - 8/2), 8, 8, -ballSpeed, 0);

	struct input* Input = (struct input*)malloc(sizeof(struct rect));
	Input->up = false;
	Input->down = false;

	while(1)
	{
		VBlankIntrWait();
		DrawCenterLine();

		/* Respond to user input and move player */
		SetInput(Input);
		MovePlayer(HumanPlayer, Input);
		KeepInBounds(HumanPlayer);

		if(CheckCollision(ball, HumanPlayer))
        {
            ball->velocityX = ball->velocityX * -1;
            AdjustVelocityByHitPosition(ball, HumanPlayer);
        }

        if(CheckCollision(ball, CPUplayer)) 
        {
            ball->velocityX = ball->velocityX * -1;
            AdjustVelocityByHitPosition(ball, CPUplayer);
        }


        BallBoundaries(ball);
		MoveBall(ball);

		/* Clear previous */
		ClearPrevious(ball);
		ClearPrevious(HumanPlayer);
		ClearPrevious(CPUplayer);

		HumanPlayer->y += HumanPlayer->velocityY;

		/* Draw actors in scene */
		DrawRect(HumanPlayer);
		DrawRect(CPUplayer);
		DrawRect(ball);
	}

	free(ball);
	free(HumanPlayer);
	free(CPUplayer);
	free(Input);
}