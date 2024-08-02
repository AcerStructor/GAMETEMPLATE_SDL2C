#include <SDL.h>
#include "input.h"

extern Game* game;

void HandleUserInput()
{
    // HANDLE INPUT
    SDL_Event evnt;
    while (SDL_PollEvent(&evnt))
    {
        if (evnt.type == SDL_QUIT)    game->isRunning = FALSE;
        if (evnt.type == SDL_KEYDOWN) game->delegate.handleKeyInput(&evnt);
    }
}
