/**********************************************************************
 *
 * @file    spriteClip.h
 * @brief   This file includes functions that are important for
 *          sprite clipping in graphics.
 *
 * @author  Jerico G. Despe (aka @AcerStructor)
 *
 * @note
 * Ensure that header file such as "struct.h" is included in this
 * file
 *
 * @dependencies
 * SDL2 SDL2_Image libraries
 *
 **********************************************************************/

#ifndef _SPRITE_CLIP_H_
#define _SPRITE_CLIP_H_
#include <SDL.h>
#include "struct.h"

SDL_Rect GetSpriteRect(SpriteClip clip);

#endif // _SPRITE_CLIP_H_
