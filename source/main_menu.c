#include "game_states.h"
#include "characters.h"

void MainMenu()
{
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