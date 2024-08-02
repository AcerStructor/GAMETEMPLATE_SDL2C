#ifndef _SPRITE_H_
#define _SPRITE_H_
#include "defs.h"
#include "spriteClip.h"
#include "struct.h"

Sprite*  InitSprite(const char* spritePath, SpriteClip* clip);

void     DrawSprite(Sprite* sprite);

void     DestroySprite(Sprite* sprite);

void     SetSpritePosition(Sprite* sprite, float x, float y);

#endif // _SPRITE_H_
