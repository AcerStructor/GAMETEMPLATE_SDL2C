#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <SDL.h>
#include <SDL_image.h>
#include "defs.h"

typedef struct
{
    void (*handleKeyInput)(SDL_Event*);
    void (*update)(float); 
    void (*render)();
    void (*destroy)();
}
Scene;

typedef struct
{
    SDL_Window*    window;
    SDL_Renderer*  renderer;
    CBOOL          isRunning;
    Scene          delegate;
}
Game;

typedef struct
{
    float x;
    float y;
}
Position;

typedef Position Scale;
typedef Position Vector2D;

typedef struct
{
    CBYTE spriteIndex;
    CBYTE spritesPerRow;
    short spriteWidth;
    short spriteHeight; 
}
SpriteClip;

typedef struct
{
    SDL_Texture* texture;
    Position     cursorPos;
    Position     midPos;
    Scale        scale;
    SpriteClip   clip;
}
Sprite;

typedef struct
{
    CBYTE currentFrames; // Should be set as 0 by default
    float elapsedTime;
    CBYTE startFrame;
    CBYTE endFrame;
    CBOOL isLooped;
    float frameTime;
}
Animation;

#endif // _STRUCT_H_
