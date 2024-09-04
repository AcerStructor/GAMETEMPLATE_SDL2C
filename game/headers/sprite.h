/**********************************************************************
 *
 * @file    sprite.h
 * @brief   This file provides functions to initialize and manipulate
 *          a sprite.
 *
 * @author  Jerico G. Despe (aka @AcerStructor)
 *
 * @note
 * It is important to ensure that header files such as "defs.h",
 * "spriteClip.h" and "struct.h" are included in this header file,
 * and also "draw.h" in its source file
 *
 * @dependencies
 * SDL2 SDL2_Image libraries
 *
 **********************************************************************/

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
