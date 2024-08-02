#include "common.h"
#include "struct.h"
#include "sprite.h"
#include "initSplashScreen.h"
#include "initTitleScreen.h"

/* EXTERNAL DATA  */
extern Game* game;

/* GAME OBJECTS */
Sprite* SplashScreenLogo = NULL;
Sprite* Dinosaur = NULL;

/* PRIVATE VARIABLES */
//static float ElapsedTime = 0;

/* FUNCTIONS */
static void Setup();                            // for initializing game objects
static void Update(float deltaTime);            // for processing game logics
static void HandleKeyInput(SDL_Event* evnt);    // for handling user key input
static void Render();                           // for drawing sprites on game
static void Destroy();                          // for freeing memory after exit

void InitSplashScreen()
{
    /* INITIALIZE SCENE */
    game->delegate.handleKeyInput = &HandleKeyInput;
    game->delegate.update         = &Update;
    game->delegate.render         = &Render;
    game->delegate.destroy        = &Destroy;

    /* INITIALIZE GAME OBJECTS */
    Setup();
}

/* FUNCTIONS */
static void Setup()
{
    SplashScreenLogo = InitSprite("res/gfx/SplashScreen_Placeholder.png", NULL);
    SetSpritePosition(SplashScreenLogo, GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2);
}

static void Update(float deltaTime)
{
}

static void HandleKeyInput(SDL_Event* evnt)
{
    switch(evnt->key.keysym.sym)
    {
        case SDLK_RETURN:
            InitTitleScreen();
            break;
    }
}

static void Render()
{
    /* SET BACKGROUND COLOR */
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);

    /* DRAW GAME OBJECTS */
    DrawSprite(SplashScreenLogo);

    /*  RENDER GRAPHICS */
    SDL_RenderPresent(game->renderer);
}

static void Destroy()
{
    DestroySprite(SplashScreenLogo);
    SplashScreenLogo = NULL;
}
