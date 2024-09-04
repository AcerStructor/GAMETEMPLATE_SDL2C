/**************************************************************************
 *
 * @file    initSplashScreen.c
 *
 * @brief   TitleScreen is the main menu of this program. Where user use
 *          key inputs to start the game or other way around.
 *
 * @author  Jerico G. Despe (aka @AcerStructor)
 *
 * @note
 * Ensure that the appropriate header files such as common.h, struct.h
 * sprite.h, and initTitleScreen.h is included where these functions are
 * used.
 *
 * @dependencies
 * SDL2 SDL2_image Libraries
 *
 **************************************************************************/

#include "common.h"
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
    game->currentScene.destroy(); // deallocate previous scene

    /* INITIALIZE SCENE */
    game->currentScene.handleKeyInput = &HandleKeyInput;
    game->currentScene.update         = &Update;
    game->currentScene.render         = &Render;
    game->currentScene.destroy        = &Destroy;

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
