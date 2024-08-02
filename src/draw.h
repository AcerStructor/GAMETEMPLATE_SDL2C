/**********************************************************************
 *
 * @file    draw.h
 * @brief   This file provides functions to load textures from
 *          filetypes such as pngs and jpgs, and draw those textures
 *          inside the program window 
 *
 * @author  Jerico G. Despe (aka @AcerStructor)
 *
 * @note
 * Ensure that header files such as "common.h" and "struct.h"
 * are included in this header file
 *
 * @dependencies
 * SDL2 SDL2_Image libraries
 *
 **********************************************************************/

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
