#include <stdio.h>

#include "struct.h"
#include "initTitleScreen.h"

extern Game* game;

static void Setup();                            // for initializing game objects
static void Update(float deltaTime);            // for processing game logics
static void HandleKeyInput(SDL_Event* evnt);    // for handling user key input
static void Render();                           // for drawing sprites on game
static void Destroy();                          // for freeing memory after exit


void InitTitleScreen()
{
    game->delegate.destroy(); // deallocate previous scene

    /* INITIALIZE SCENE */
    game->delegate.handleKeyInput = &HandleKeyInput;
    game->delegate.update         = &Update;
    game->delegate.render         = &Render;
    game->delegate.destroy        = &Destroy;

    /* INITIALIZE GAME OBJECTS */
    Setup();

}

static void Setup()
{
}

static void Update(float deltaTIme)
{
}

static void HandleKeyInput(SDL_Event* evnt)
{
    switch(evnt->key.keysym.sym)
    {
        case SDLK_RETURN:
            printf("ENTER KEY HAS BEEN PRESSED!\n");
            break;
    }
}

static void Render()
{
    /* SET BACKGROUND COLOR */
    SDL_SetRenderDrawColor(game->renderer, 0, 102, 204, 255);
    SDL_RenderClear(game->renderer);

    /* DRAW GAME OBJECTS */
    
    /*  RENDER GRAPHICS */
    SDL_RenderPresent(game->renderer);
}

static void Destroy()
{
}
