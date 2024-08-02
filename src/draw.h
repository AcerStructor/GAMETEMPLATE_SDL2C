#ifndef _DRAW_H_
#define _DRAW_H_

#include "common.h"
#include "struct.h"

// LOAD TEXTURE FROM FILEPATH
SDL_Texture* LoadTexture(const char* spritePath);

// RENDER TEXTURE TO THE GAME
void         DrawTexture(SDL_Texture* texture, Scale scale, Position pos, SDL_Rect* clipRect);

void         DestroyTexture(SDL_Texture* texture);

#endif // _DRAW_H_
