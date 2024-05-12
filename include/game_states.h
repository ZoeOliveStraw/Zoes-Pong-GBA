#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "gameplay.h"

//This header files will define methods  for the various gameplay states of the game

void MainMenu();
void SetGame(int player1Score, int player2Score);
void RunGame(int player1Score, int player2Score);
void EndGame(int player1Score, int player2Score);

#endif