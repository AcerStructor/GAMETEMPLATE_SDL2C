#include <SDL.h>
#include "spriteClip.h"

SDL_Rect GetSpriteRect(SpriteClip clip)
{
    SDL_Rect spriteRect;
    spriteRect.x = (clip.spriteIndex % clip.spritesPerRow) * clip.spriteWidth;
    spriteRect.y = (clip.spriteIndex / clip.spritesPerRow) * clip.spriteHeight;
    spriteRect.w = clip.spriteWidth;
    spriteRect.h = clip.spriteHeight;
    return spriteRect;
}
