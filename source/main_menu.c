#include <stdlib.h>
#include "game_states.h"
#include "characters.h"

void MainMenu()
{
    for(int i = 0; i < 64; i++)
    {
        if(*score + i) DrawPixel(20 + i, 20, 0x7FFF);
    }

    struct input* Input = (struct input*)malloc(sizeof(struct rect));
    PrintCharacter(&score[0], 5, 5);

    while(1)
    {
        SetInput(Input);

        if(Input->start)
        {
            break;
        }
    }

    free(Input);
    ClearScreen();
    RunGame(0,0);
}