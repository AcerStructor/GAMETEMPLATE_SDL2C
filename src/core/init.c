/*
 * @file   init.c
 * @brief  This is the source code for init.c
 * #author Jerico G. Despe (aka @AcerStructor)
 */

#include "common.h"
#include "init.h"
#include "struct.h"

extern Game* game;

static CBOOL IsInitializedSDL = FALSE;
static CBOOL IsInitializedIMG = FALSE;

CBOOL InitGame()
{
    game = (Game*)malloc(sizeof(Game));

    if (game == NULL)
    {
        fprintf(stderr, "ERROR: Couldn't allocate game data\n");
        return FALSE;
    }

    /* INITIALIZE WINDOW AND RENDERER AS NULL */
    game->renderer = NULL;
    game->window   = NULL;

    printf("LOG: Game Data Allocated...\n");

    const int sdlFlags =  SDL_INIT_VIDEO;

    if (SDL_Init(sdlFlags) != 0)
    {
        fprintf(stderr, "ERROR: Couldn't initialize SDL2: %s\n", SDL_GetError());
        return FALSE;
    }

    IsInitializedSDL = TRUE;

    printf("LOG: SDL2 has been initialized...\n");

    /* INITIALIZE WINDOW */
    const int windowFlags   = SDL_WINDOW_MAXIMIZED;

    game->window = SDL_CreateWindow(GAME_WINDOW_TITLE,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    GAME_WINDOW_WIDTH,
                                    GAME_WINDOW_HEIGHT,
                                    windowFlags);

    if (game->window == NULL)
    {
        fprintf(stderr, "ERROR: Couldn't initialize the game window: %s\n", SDL_GetError());
        return FALSE;
    }

    printf("LOG: SDL2 window has been initialized!...\n");

    /* INITIALIZE RENDERER */
    const int rendererFlags = SDL_RENDERER_ACCELERATED;

    game->renderer = SDL_CreateRenderer(game->window, -1, rendererFlags);

    if (game->renderer == NULL)
    {
        fprintf(stderr, "ERROR: Couldn't initialize the game renderer: %s\n", SDL_GetError());
        return FALSE;
    }

    printf("LOG: SDL2 renderer has been initialized!...\n");
   
    /* INITIALIZE IMG */ 
    if (IMG_Init(IMG_INIT_PNG) == 0) 
    {
        fprintf(stderr, "ERROR: Couldn't initialize SDL2 image: %s\n", IMG_GetError());
        return FALSE;
    }

    IsInitializedIMG = TRUE;

    printf("LOG: SDL2 IMG has been initialized!...\n");

    game->isRunning = TRUE;

    atexit(QuitGame);

    return TRUE;
}

void QuitGame()
{
    /* DE-ALLOCATE RENDERER */
    if (game->renderer != NULL)
    {
        SDL_DestroyRenderer(game->renderer);
        game->renderer = NULL;
        printf("LOG: SDL2 renderer has been deallocated...\n");
    }

    /* DE-ALLOCATE WINDOW */
    if (game->window != NULL)
    {
        SDL_DestroyWindow(game->window);
        game->window   = NULL;
        printf("LOG: SDL2 window has been deallocated...\n");
    }

    /* DE-ALLOCATE IMG */
    if (IsInitializedIMG)
    {
        IMG_Quit();
        IsInitializedIMG = FALSE;
        printf("LOG: IMG has been deallocated...\n");
    }

    /* DE-ALLOCATE SDL */
    if (IsInitializedSDL)
    {
        SDL_Quit();
        IsInitializedSDL = FALSE;
        printf("LOG: SDL2 has been deallocated...\n");
    }

    /* DE-ALLOCATE GAME DATA */
    if (game != NULL)
    {
        free(game);
        game = NULL;
        printf("LOG: Game Data freed...\n");
    }
}
