#include "common.h"
#include "struct.h"
#include "input.h"
#include "init.h"
#include "initSplashScreen.h"

#ifdef _WIN32
    #include <windows.h>
#endif

/* GLOBAL DATA */
Game* game = NULL;

/* FRAME LIMITING */
static void FrameCap(Uint32 frameStart, Uint32 targetTime);

/* MAIN PROGRAM ENTRY POINT */
int main(int argc, char* argv[])
{
    if (!InitGame())
    {
        QuitGame(); // Deallocate allocated memory after initialization fails
        return EXIT_FAILURE;
    }

    InitSplashScreen(); // Initialize Splash Screen as first scene

    Uint32 framePrev = 0;
    while (game->isRunning)
    {
        // CALCULATE DELTA TIME:
        Uint32 frameStart = SDL_GetTicks();
        float deltaTime = (frameStart - framePrev) / 1000.0f;
        framePrev = frameStart; // set previous frame value same as current frame

        // PROCESS GAME:
        HandleUserInput();
        game->delegate.update(deltaTime);
        game->delegate.render();

        // FRAME CAPPING
        FrameCap(frameStart, FRAME_TARGET_TIME);
    }

    game->delegate.destroy();

    return EXIT_SUCCESS;
}

static void FrameCap(Uint32 frameStart, Uint32 targetTime)
{
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameTime < targetTime)
    {
        SDL_Delay(FRAME_TARGET_TIME - frameTime);
    }
}
